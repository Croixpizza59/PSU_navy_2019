/*
** EPITECH PROJECT, 2020
** navy
** File description:
** checking_format
*/

#include "proto.h"

static bool check_my_point(navy_t *navy)
{
    int x = 1;
    int x_sec = 4;

    for (int y = 0; y < navy->map_pos.y_max_2 - 1; y++) {
        if (CURSOR(y, x) != ':')
            CHECK = true;
    }
    for (int y = 0; y < navy->map_pos.y_max_2 - 1; y++) {
        if (navy->map_pos.map2[y][x_sec] != ':')
            CHECK = true;
    }
    return (CHECK);
}

bool check_my_formater(navy_t *navy)
{
    if (navy->map_pos.len_2 != 32)
        CHECK = true;
    if (check_my_point(navy) == true)
        CHECK = true;
    return (CHECK);
}