/*
** EPITECH PROJECT, 2020
** navy.c
** File description:
** navy
*/

#include "proto.h"

void my_free(game_t *game)
{
    for (int y = 0; y != game->map.y_max; y++)
        free(game->map.map[y]);
}

void my_free_pos(game_t *game)
{
    for (int y = 0; y != game->map.y_max_pos; y++)
    free(game->map.map_pos[y]);
}

int navy(game_t *game, int ac, char **av)
{
    if (ac == 2) {
        game->user.pos1 = av[1];
        user1(game);
    } else if (ac == 3) {
        game->user.pos2 = av[2];
        user2(game, av[1]);
    }
    if (create_map(game) == 84) {
        my_free(game);
        close(game->map.fd);
        return (84);
    }
    my_putchar('\n');
    my_free(game);
    close(game->map.fd);
    return (0);
}