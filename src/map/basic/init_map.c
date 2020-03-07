/*
** EPITECH PROJECT, 2020
** init_map.c
** File description:
** init_map
*/

#include "proto.h"

char **init_map(game_t *game)
{
    int x = 0;
    int y = 0;
    game->map.map = malloc(sizeof(char *) * (game->map.y_max));

    for (int i = 0; i < game->map.y_max; i++)
        game->map.map[i] = malloc(sizeof(char) * (game->map.x_max));
    for (int i = 0; i != game->map.len; i++) {
        if (game->map.buffer[i] == '\n') {
            y++;
            x = 0;
        } else {
            game->map.map[y][x] = game->map.buffer[i];
            x++;
        }
    }
    return (game->map.map);
}

char **init_map_sec(game_t *game)
{
    int x = 0;
    int y = 0;
    game->map.map2 = malloc(sizeof(char *) * (game->map.y_max));

    for (int i = 0; i < game->map.y_max; i++)
        game->map.map2[i] = malloc(sizeof(char) * (game->map.x_max));
    for (int i = 0; i != game->map.len2; i++) {
        if (game->map.buffer2[i] == '\n') {
            y++;
            x = 0;
        } else {
            game->map.map2[y][x] = game->map.buffer2[i];
            x++;
        }
    }
    return (game->map.map2);
}