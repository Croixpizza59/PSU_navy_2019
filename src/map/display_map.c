/*
** EPITECH PROJECT, 2020
** display_map.c
** File description:
** display_map
*/

#include "proto.h"

bool display_map(game_t *game)
{
    bool check = false;

    my_putstr("my positions:\n");
    display_map_sec(game);
    my_putstr("enemy’s positions\n");
    my_putstr(game->map.buffer);
    my_putchar('\n');
    return (check);
}