/*
** EPITECH PROJECT, 2020
** navy
** File description:
** check the output
*/

#include "proto.h"

static bool checking_letter_two(navy_t *navy, int x, int y)
{
    if (CURSOR(y, x) >= 'A' && CURSOR(y, x) <= 'Z') {
        if (CURSOR(y, x) > 'H')
            CHECK = true;
    } else if (CURSOR(y, x) >= '0' && CURSOR(y, x) <= '9') {
        if (CURSOR(y, x) > '8' || CURSOR(y, x) < '1')
            CHECK = true;
    }
    return (CHECK);
}

bool checking_letter(navy_t *navy)
{
    int x = 0;
    int y = 0;
    bool check_two = false;

    if (check_my_formater(navy) == true)
        CHECK = true;
    if (checking_lenght(navy) == true)
        CHECK = true;
    for (y = 0; y < navy->map_pos.y_max_2 - 1; y++) {
        for (x = 0; x < navy->map_pos.x_max_2 - 1; x++) {
            if ((check_two = checking_letter_two(navy, x, y)) == true)
                CHECK = true;
        }
    }
    return (CHECK);
}