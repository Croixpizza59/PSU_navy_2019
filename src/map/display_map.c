/*
** EPITECH PROJECT, 2020
** display_map.c
** File description:
** display_map
*/

#include "proto.h"

void display_map(game_t *game)
{
    int x;
    int y;

    my_putstr("my positions:\n");
    for (y = 0; y < game->map.y_max; y++) {
        for (x = 0; x < game->map.x_max; x++)
            my_putchar(game->map.map[y][x]);
        my_putchar('\n');
    }
    my_putchar('\n');
    find_my_position(game);
}
