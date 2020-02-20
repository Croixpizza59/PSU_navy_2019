/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include "proto.h"

void signal_handler(pid_t pid2)
{
    my_putstr("enemy connected\n");
    kill(pid2, SIGUSR2);
}
void signal_usr2()
{
    my_putstr("successfully connected\n");
}

int main(int ac, char **av)
{
    pid_t pid;
    pid_t pid2;
    struct sigaction s = {0};

    if (ac == 1) {
        pid = getpid();
        printf("my_pid:\t%d\n", pid);
        my_putstr("waiting for enemy connection...\n\n");
        s.sa_handler = signal_handler;
        sigaction(SIGUSR1, &s, NULL);
        while (1)
            sleep(2);
    }
    else if (ac == 2) {
        pid2 = getpid();
        printf("my_pid:\t%d\n", pid2);
        pid = to_number(av[1]);
        kill(pid, SIGUSR1);
        s.sa_handler = signal_usr2;
        sigaction(SIGUSR2, &s, NULL);
        while (1)
            sleep(2);
    } else
        return (84);
    return (0);
}