/*
** EPITECH PROJECT, 2020
** navy
** File description:
** display_map.c display navy map
*/

#include "proto.h"

void display_map_sec(navy_t *navy)
{
    int x;
    int y;

    for (y = 0; y < navy->map.y_max; y++) {
        for (x = 0; x < navy->map.x_max; x++)
            my_putchar(navy->map.map[y][x]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

static void display_map_enem(navy_t *navy)
{
    int x;
    int y;

    for (y = 0; y < navy->map.y_max; y++) {
        for (x = 0; x < navy->map.x_max; x++)
            my_putchar(navy->map.map_dup[y][x]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

bool display_map(navy_t *navy)
{
    bool check = false;

    my_putstr("my positions:\n");
    display_map_sec(navy);
    my_putstr("enemy’s positions:\n");
    display_map_enem(navy);
    return (check);
}