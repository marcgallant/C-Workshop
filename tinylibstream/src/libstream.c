#include "../include/libstream.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int get_flags(const char *mode)
{
    if (!strcmp(mode, "r"))
        return O_RDONLY;
    else if (!strcmp(mode, "r+"))
        return O_RDWR;
    else if (!strcmp(mode, "w"))
        return O_WRONLY | O_CREAT | O_TRUNC;
    else if (!strcmp(mode, "w+"))
        return O_RDWR | O_CREAT | O_TRUNC;
    else
        return -1;
}

struct stream *lbs_fdopen(int fd, const char *mode)
{
    struct stream *stream = malloc(sizeof(struct stream));
    int flags = get_flags(mode);

    if (stream && flags != -1 && fd > 0)
    {
        if (isatty(fd))
            stream->buffering_mode = STREAM_LINE_BUFFERED;
        else
            stream->buffering_mode = STREAM_BUFFERED;

        stream->io_operation = STREAM_READING;
        stream->fd = fd;
        stream->flags = flags;
        stream->already_read = 0;
        stream->buffered_size = 0;
        stream->error = 0;

        return stream;
    }
    free(stream);
    return NULL;
}

struct stream *lbs_fopen(const char *path, const char *mode)
{
    int flags = get_flags(mode);

    if (flags != -1)
        return lbs_fdopen(open(path, flags), mode);
    else
        return NULL;
}

int lbs_fflush(struct stream *stream)
{
    if (stream)
    {
        if (stream->io_operation == STREAM_READING)
        {
            int tmp = stream_remaining_buffered(stream);
            if (tmp != 0)
                lseek(stream->fd, -tmp, SEEK_CUR);

            stream->buffered_size = 0;
            stream->already_read = 0;

            return 0;
        }

        if (stream->io_operation == STREAM_WRITING)
        {
            if (write(stream->fd, stream->buffer, stream->buffered_size) == -1)
            {
                stream->error = 1;
                return EOF;
            }

            stream->buffered_size = 0;
            return 0;
        }
    }
    return EOF;
}

int lbs_fclose(struct stream *file)
{
    if (file)
    {
        if (lbs_fflush(file) == -1)
        {
            close(file->fd);
            free(file);
            return EOF;
        }

        if (close(file->fd) == -1)
        {
            free(file);
            return EOF;
        }
    }
    free(file);
    return 0;
}

int lbs_fputc(int c, struct stream *stream)
{
    if (stream && stream_writable(stream))
    {
        if (stream->buffered_size == LBS_BUFFER_SIZE)
        {
            if (lbs_fflush(stream) == -1)
            {
                stream->error = 1;
                return EOF;
            }
        }

        if (stream->io_operation == STREAM_READING)
        {
            if (lbs_fflush(stream) == -1)
            {
                stream->error = 1;
                return EOF;
            }
        }

        stream->io_operation = STREAM_WRITING;
        stream->buffer[stream->buffered_size] = c;
        stream->buffered_size++;

        if ((stream->buffering_mode == STREAM_LINE_BUFFERED && c == '\n') //
            || stream->buffering_mode == STREAM_UNBUFFERED)
        {
            if (lbs_fflush(stream) == -1)
            {
                stream->error = 1;
                return EOF;
            }
        }
        return c;
    }
    return EOF;
}

int lbs_fgetc(struct stream *stream)
{
    if (stream && stream_readable(stream))
    {
        if (stream->io_operation == STREAM_WRITING)
        {
            if (lbs_fflush(stream) == -1)
            {
                stream->error = 1;
                return EOF;
            }
        }

        stream->io_operation = STREAM_READING;

        if (stream->already_read >= stream->buffered_size)
        {
            if (lbs_fflush(stream) == -1)
            {
                stream->error = 1;
                return EOF;
            }
        }

        if (!stream_remaining_buffered(stream))
        {
            int tmp;
            if ((tmp = read(stream->fd, stream->buffer, LBS_BUFFER_SIZE)) <= 0)
            {
                stream->error = 1;
                return EOF;
            }
            stream->buffered_size = tmp;
        }

        unsigned char c = stream->buffer[stream->already_read];
        stream->already_read++;

        if (c == 0)
            return EOF;
        else
            return c;
    }
    return EOF;
}
