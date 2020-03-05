/*
** EPITECH PROJECT, 2020
** navy.c
** File description:
** navy
*/

#include "proto.h"

int navy(game_t *game, int ac, char **av)
{
    if (ac == 2) {
        game->user.pos1 = av[1];
        if (user1(game) == 84)
            return (84);
    } else if (ac == 3) {
        game->user.pos2 = av[2];
        if (user2(game, av[1]) == 84)
            return (84);
    }
    my_free(game);
    close(game->map.fd);
    return (0);
}
