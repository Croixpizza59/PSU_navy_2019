/*
** EPITECH PROJECT, 2020
** navy
** File description:
** axes
*/

#include "proto.h"

bool x_axes(navy_t *navy, int y, bool check)
{
    navy->map.map[J + 1][I] = NB + '0';
    while (I <= A) {
        navy->map.map[J + 1][I] = NB + '0';
        I += 2;
        ++COUNT1;
    }
    if (COUNT1 != (navy->map_pos.map2[y][0] - '0'))
        check = true;
    COUNT1 = 0;
    return (check);
}

bool y_axes(navy_t *navy, int y, bool check)
{
    navy->map.map[J + 1][I] = NB + '0';
    while (J <= K) {
        navy->map.map[J + 1][I] = NB + '0';
        ++J;
        ++COUNT2;
    }
    if (COUNT2 != (navy->map_pos.map2[y][0] - '0'))
        check = true;
    COUNT2 = 0;
    return (check);
}