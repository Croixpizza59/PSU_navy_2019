/*
** EPITECH PROJECT, 2020
** checking_format.c
** File description:
** check the style of pos script
*/

#include "proto.h"

static bool check_my_point(game_t *game)
{
    int x = 1;
    int x_sec = 4;

    for (int y = 0; y < 4; y++) {
        if (CURSOR(y, x) != ':') {
            CHECK = true;
        }
    }
    for (int y = 0; y < 4; y++) {
        if (game->map.map_pos[y][x_sec] != ':') {
            CHECK = true;
        }
    }
    return (CHECK);
}

bool check_my_formater(game_t *game)
{
    if (game->map.len_pos > 32)
        CHECK = true;
    if (check_my_point(game) == true)
        CHECK = true;
    return (CHECK);
}