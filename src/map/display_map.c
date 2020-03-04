/*
** EPITECH PROJECT, 2020
** display_map.c
** File description:
** display_map
*/

#include "proto.h"

void display_map(game_t *game)
{
    my_putstr("my positions:\n");
    find_my_position(game);
    my_putstr("enemy’s positions\n");
    my_putstr(game->map.buffer);
    my_putchar('\n');
}
