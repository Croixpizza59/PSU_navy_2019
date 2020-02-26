/*
** EPITECH PROJECT, 2020
** init_map.c
** File description:
** init_map
*/

#include "proto.h"

char **init_map(game_t *game, char *buffer, int len)
{
    int x = 0;
    int y = 0;
    game->map.map = malloc(sizeof(char*) * (game->map.y_max));

    for (int i = 0; i < game->map.y_max; i++)
        game->map.map[i] = malloc(sizeof(char) * (game->map.x_max));
    for (int i = 0; i != len; i++) {
        if (buffer[i] == '\n') {
            y++;
            x = 0;
        } else {
            game->map.map[y][x] = buffer[i];
            x++;
        }
    }
    return (game->map.map);
}