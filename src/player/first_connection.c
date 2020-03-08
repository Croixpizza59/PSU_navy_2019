/*
** EPITECH PROJECT, 2020
** navy
** File description:
** first connection
*/

#include "proto.h"

static void sig_handler(int signal, siginfo_t *sig, void *stream)
{
    (void)signal;
    (void)stream;
    global = sig->si_pid;
    my_putstr("\nenemy connected\n\n");
}

int connection_user1(void)
{
    struct sigaction signal;
    signal.sa_sigaction = &sig_handler;
    signal.sa_flags = SA_SIGINFO;
    my_putstr("my_pid:\t");
    my_putstr(show_number(getpid()));
    my_putstr("\nwaiting for enemy connection...\n");
    sigemptyset(&signal.sa_mask);
    sigaction(12, &signal, NULL);
    return (0);
}

int connection_user2(navy_t *navy, char *pid1)
{
    navy->verif.pid_ennemy = to_number(pid1);
    my_putstr("my_pid:\t");
    my_putstr(show_number(getpid()));
    my_putchar('\n');
    if (kill(navy->verif.pid_ennemy, SIGUSR2) == -1)
        return (84);
    my_putstr("successfully connected\n\n");
    return (0);
}