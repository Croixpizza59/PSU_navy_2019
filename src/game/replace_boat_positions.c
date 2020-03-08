/*
** EPITECH PROJECT, 2020
** navy
** File description:
** replace '.' by boat number
*/

#include "proto.h"

static int checking_board(navy_t *navy, int x, int y, int i)
{
    if (CURSOR(y, x) == 'A')
        i = 2;
    if (CURSOR(y, x) == 'B')
        i = 4;
    if (CURSOR(y, x) == 'C')
        i = 6;
    if (CURSOR(y, x) == 'D')
        i = 8;
    if (CURSOR(y, x) == 'E')
        i = 10;
    if (CURSOR(y, x) == 'F')
        i = 12;
    if (CURSOR(y, x) == 'G')
        i = 14;
    if (CURSOR(y, x) == 'H')
        i = 16;
    return (i);
}

bool replace_boat_positions(navy_t *navy)
{
    NB = 2;
    bool check = false;

    for (int y = 0; y < Y_MAX - 1; y++) {
        for (int x = 0; x < 3; x++) {
            if (navy->map_pos.map2[y][x] == ':') {
                ++x;
                I = checking_board(navy, x, y, I);
                A = checking_board(navy, 5, y, I);
                J = navy->map_pos.map2[y][x + 1] - '0';
                K = navy->map_pos.map2[y][6] - '0';
                if (J == navy->map_pos.map2[y][6] - '0')
                    check = x_axes(navy, y, check);
                else
                    check = y_axes(navy, y, check);
            }
        }
        ++NB;
    }
    return (check);
}