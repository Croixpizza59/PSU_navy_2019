/*
** EPITECH PROJECT, 2020
** user2
** File description:
** connection with user2 and user1 and sig_handler
*/

#include "proto.h"

int user2(game_t *game, char *pid1)
{
    game->user.pid_ennemy = to_number(pid1);
    my_putstr("my_pid:\t");
    my_putstr(show_number(getpid()));
    my_putchar('\n');
    if (kill(game->user.pid_ennemy, SIGUSR2) == -1)
        return (84);
    my_putstr("succesfully connected\n\n");
    if (create_map_pos(game, game->user.pos2) == 84) {
        close(game->map.fd_pos);
        return (84);
    }
    return (0);
}