/*
** EPITECH PROJECT, 2020
** navy
** File description:
** init_map_pos who initialiaze positions
*/

#include "proto.h"

char **init_map_pos(navy_t *navy)
{
    int x = 0;
    int y = 0;
    navy->map_pos.map2 = malloc(sizeof(char *) * (RAM));

    for (int i = 0; i < navy->map_pos.len_2; i++)
        navy->map_pos.map2[i] = malloc(sizeof(char) * (RAM));
    for (int i = 0; i != navy->map_pos.len_2; i++) {
        if (navy->map_pos.buffer_2[i] == '\n') {
            y++;
            x = 0;
        } else {
            navy->map_pos.map2[y][x] = navy->map_pos.buffer_2[i];
            x++;
        }
    }
    return (navy->map_pos.map2);
}