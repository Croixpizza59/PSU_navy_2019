/*
** EPITECH PROJECT, 2020
** connect.c
** File description:
** connect
*/

#include "proto.h"

void sig_handler(int i, siginfo_t *sig)
{
    game_t *game;

    game->user.pid_ennemy = sig->si_pid;
    my_putstr("\nenemy connected\n");
    kill(game->user.pid_ennemy, SIGUSR1);
}

int user1(game_t *game)
{
    struct sigaction signal;

    signal.sa_handler = sig_handler;
    signal.sa_flags = SA_SIGINFO;
    my_putstr("my_pid:\t");
    my_putstr(show_number(getpid()));
    my_putstr("\nwaiting for enemy connection...\n");
    sigemptyset(&signal.sa_mask);
    sigaction(SIGUSR2, &signal, NULL);
    while(1)
        usleep(5000);
    return (0);
}

int user2(game_t *game, char *pid1)
{
    game->user.pid_ennemy = to_number(pid1);
    my_putstr("my_pid:\t");
    my_putstr(show_number(getpid()));
    my_putchar('\n');
    kill(game->user.pid_ennemy, SIGUSR2);
    return (0);
}