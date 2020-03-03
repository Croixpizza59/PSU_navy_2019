/*
** EPITECH PROJECT, 2020
** checking_board
** File description:
** check all board
*/

#include "proto.h"

int checking_board(game_t *game, int x, int y, int i)
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
    if (CURSOR(y, x) == 'H')
        i = 16;
    return (i);
}