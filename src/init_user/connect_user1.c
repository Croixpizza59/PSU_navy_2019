/*
** EPITECH PROJECT, 2020
** connect_user1.c
** File description:
** connection user1
*/

#include "proto.h"

void sig_handler(int i, siginfo_t *sig, void *test)
{
    (void)i;
    (void)test;
    global = sig->si_pid;
    my_putstr("\nenemy connected\n\n");
}

int prepare_my_user1(game_t *game)
{
    struct sigaction signal;
    signal.sa_sigaction = &sig_handler;
    signal.sa_flags = SA_SIGINFO;
    my_putstr("my_pid:\t");
    my_putstr(show_number(getpid()));
    my_putstr("\nwaiting for enemy connection...\n");
    sigemptyset(&signal.sa_mask);
    sigaction(12, &signal, NULL);
    create_map_sec(game);
    if (create_map(game) == 84) {
        my_free(game);
        close(game->map.fd);
        return (84);
    }
    return (0);
}

int prepare_my_user2(game_t *game, char *pid1)
{
    game->user.pid_ennemy = to_number(pid1);
    my_putstr("my_pid:\t");
    my_putstr(show_number(getpid()));
    my_putchar('\n');
    if (kill(game->user.pid_ennemy, SIGUSR2) == -1)
        return (84);
    my_putstr("succesfully connected\n\n");
    return (0);
}