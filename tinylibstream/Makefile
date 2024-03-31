# Simple Makefile

# Compilers vars
CC=gcc
CFLAGS= -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -D_POSIX_C_SOURCE
LDFLAGS=

SRC= src/libstream.c
OBJ= $(SRC:.c=.o)

.PHONY: all clean

all: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ)

library: $(OBJ)
	ar csr libstream.a $(OBJ)

$(OBJ): $(SRC)

clean:
	rm -f $(OBJ)
	rm -f libstream.a

# END Makefile
