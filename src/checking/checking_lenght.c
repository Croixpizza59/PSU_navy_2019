/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** checking_lenght
*/

#include "proto.h"

bool checking_lenght(game_t *game)
{
    int x = 0;
    bool check = false;

    for (int y = 0; y < 3; y++) {
        if ((CURSOR(y, x) - '0') >= (CURSOR(y + 1, x) - '0'))
            check = true;
    }
    return (check);
}