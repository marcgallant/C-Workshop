#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static int sig = 0;
static int gen = -1;

void daemon(void)
{
    pid_t cpid;
    cpid = fork();

    if (cpid == 0)
        gen++;
    else
        exit(0);
}

void handler(int signum)
{
    sig++;
    switch (signum)
    {
    case SIGUSR1:
        printf("Received %d signals.\n", sig);
        break;
    case SIGUSR2:
        printf("Current generation: %d\n", gen);
        break;
    case SIGTERM:
        sig = 0;
        fflush(stdout);
        daemon();
        break;
    case SIGINT:
        exit(0);
    default:
        break;
    }
}

int main(void)
{
    daemon();

    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = handler;

    if (sigemptyset(&sa.sa_mask) < 0)
    {}
    if (sigaction(SIGUSR1, &sa, NULL) < 0)
    {}
    if (sigaction(SIGUSR2, &sa, NULL) < 0)
    {}
    if (sigaction(SIGTERM, &sa, NULL) < 0)
    {}
    if (sigaction(SIGINT, &sa, NULL) < 0)
    {}

    while (1)
        ;
}
