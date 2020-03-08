/*
** EPITECH PROJECT, 2020
** navy
** File description:
** checking_lenght check lenght of positions
*/

#include "proto.h"

bool checking_lenght(navy_t *navy)
{
    int x = 0;
    bool check = false;

    for (int y = 0; y < 3; y++) {
        if ((CURSOR(y, x) - '0') >= (CURSOR(y + 1, x) - '0'))
            check = true;
    }
    return (check);
}