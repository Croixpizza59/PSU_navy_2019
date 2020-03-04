/*
** EPITECH PROJECT, 2020
** checking
** File description:
** checking posiiton map
*/

#include "proto.h"

static bool checking_letter_two(game_t *game, int x, int y)
{
    if (CURSOR(y, x) >= 'A' && CURSOR(y, x) <= 'Z') {
        if (CURSOR(y, x) > 'H')
            CHECK = true;
    }
    else if (CURSOR(y, x) >= '0' && CURSOR(y, x) <= '9')
        if (CURSOR(y, x) > '8' || CURSOR(y, x) < '1')
            CHECK = true;
    return (CHECK);
}

bool checking_letter(game_t *game)
{
    int x = 0;
    int y = 0;
    bool check_two = false;

    if (check_my_formater(game) == true)
        CHECK = true;
    for (y = 0; y < game->map.y_max_pos - 1; y++) {
        for (x = 0; x < game->map.x_max_pos - 1; x++)
            if ((check_two = checking_letter_two(game, x, y)) == true)
                CHECK = true;
    }
    return (CHECK);
}
