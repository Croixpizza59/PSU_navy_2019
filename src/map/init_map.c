/*
** EPITECH PROJECT, 2020
** navy
** File description:
** init map
*/

#include "proto.h"

char **init_map(navy_t *navy)
{
    int x = 0;
    int y = 0;
    navy->map.map = malloc(sizeof(char *) * (navy->map.y_max));

    for (int i = 0; i < navy->map.y_max; i++)
        navy->map.map[i] = malloc(sizeof(char) * (navy->map.x_max));
    for (int i = 0; i != navy->map.len; i++) {
        if (navy->map.buffer[i] == '\n') {
            y++;
            x = 0;
        } else {
            navy->map.map[y][x] = navy->map.buffer[i];
            x++;
        }
    }
    return (navy->map.map);
}

char **init_map_dup(navy_t *navy)
{
    int x = 0;
    int y = 0;
    navy->map.map_dup = malloc(sizeof(char *) * (navy->map.y_max));

    for (int i = 0; i < navy->map.y_max; i++)
        navy->map.map_dup[i] = malloc(sizeof(char) * (navy->map.x_max));
    for (int i = 0; i != navy->map.len_dup; i++) {
        if (navy->map.buffer_dup[i] == '\n') {
            y++;
            x = 0;
        } else {
            navy->map.map_dup[y][x] = navy->map.buffer_dup[i];
            x++;
        }
    }
    return (navy->map.map_dup);
}