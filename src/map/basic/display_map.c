/*
** EPITECH PROJECT, 2020
** display_map.c
** File description:
** display_map.c
*/

#include "proto.h"

static void display_map_enem(game_t *game)
{
    int x;
    int y;

    for (y = 0; y < game->map.y_max; y++) {
        for (x = 0; x < game->map.x_max; x++)
            my_putchar(game->map.map2[y][x]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

bool display_map(game_t *game)
{
    bool check = false;

    my_putstr("my positions:\n");
    display_map_sec(game);
    my_putstr("enemy’s positions:\n");
    display_map_enem(game);
    return (check);
}