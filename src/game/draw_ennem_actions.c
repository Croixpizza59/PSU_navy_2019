/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** draw_actions
*/

#include "proto.h"

static char find_letter(int i)
{
    char buffer = 0;

    if (i == 2)
        buffer = 'A';
    if (i == 4)
        buffer = 'B';
    if (i == 6)
        buffer = 'C';
    if (i == 8)
        buffer = 'D';
    if (i == 10)
        buffer = 'E';
    if (i == 12)
        buffer = 'F';
    if (i == 14)
        buffer = 'G';
    if (i == 16)
        buffer = 'H';
    return (buffer);
}

void draw_ennem_actions(navy_t *navy)
{
    char letter = 0;

    letter = find_letter(navy->coord.lines);
    if (navy->coord.hm == 1) {
        my_putchar(letter);
        my_putstr(show_number(navy->coord.cols - 1));
        my_putstr(": ");
        my_putstr("hit\n\n");
    } else if (navy->coord.hm == 2) {
        my_putchar(letter);
        my_putstr(show_number(navy->coord.cols - 1));
        my_putstr(": ");
        my_putstr("missed\n\n");
    }
}