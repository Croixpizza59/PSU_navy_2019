/*
** EPITECH PROJECT, 2020
** navy
** File description:
** my_free
*/

#include "proto.h"

void my_free(navy_t *navy)
{
    for (int y = 0; y != navy->map.y_max; y++)
        free(navy->map.map[y]);
    close(navy->map.fd);
}

void my_free_pos(navy_t *navy)
{
    for (int y = 0; y != navy->map_pos.y_max_2; y++)
    free(navy->map_pos.map2[y]);
}
