/*
** EPITECH PROJECT, 2020
** user1_connection
** File description:
** user_one connection with user2 and sig_handler
*/

#include "proto.h"

bool glob = true;

void sig_handler(int i, siginfo_t *sig, void *test)
{
    my_putstr("\nenemy connected\n\n");
    glob = false;
}

int user1(game_t *game)
{
    glob = true;
    struct sigaction signal;
    signal.sa_handler = &sig_handler;
    sleep(1);
    signal.sa_flags = SA_SIGINFO;
    my_putstr("my_pid:\t");
    my_putstr(show_number(getpid()));
    my_putstr("\nwaiting for enemy connection...\n");
    sigemptyset(&signal.sa_mask);
    sigaction(12, &signal, NULL);
    if (create_map_pos(game, game->user.pos1) == 84) {
        close(game->map.fd_pos);
        return (84);
    }
    while (glob != false)
        usleep(5000);
    return (0);
}