/*
** EPITECH PROJECT, 2020
** my_free.c
** File description:
** free navy
*/

#include "proto.h"

void my_free(game_t *game)
{
    for (int y = 0; y != game->map.y_max; y++)
        free(game->map.map[y]);
    close(game->map.fd);
}

void my_free_pos(game_t *game)
{
    for (int y = 0; y != game->map.y_max_pos; y++)
    free(game->map.map_pos[y]);
}
