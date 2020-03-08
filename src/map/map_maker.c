/*
** EPITECH PROJECT, 2020
** navy
** File description:
** map_maker.c contain all creator map and initialize map
*/

#include "proto.h"

int map_maker(navy_t *navy)
{
    if (create_map(navy) == 84) {
        write(2, "Error with map creation\n", 25);
        my_free(navy);
        return (84);
    } else if (create_map_dup(navy) == 84) {
        write(2, "Error with duplicate map\n", 25);
        my_free(navy);
        return (84);
    }
    if (create_map_pos(navy, navy->map_pos.pos) == 84) {
        write(2, "Error with map positions\n", 26);
        my_free(navy);
        return (84);
    }
    return (0);
}