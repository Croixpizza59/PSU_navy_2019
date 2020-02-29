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
    game->map.map = malloc(sizeof(char*) * (game->map.y_max));

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

char **init_map_pos(game_t *game)
{
    int x = 0;
    int y = 0;
    game->map.map_pos = malloc(sizeof(char*) * (RAM));

    for (int i = 0; i < game->map.len_pos; i++)
        game->map.map_pos[i] = malloc(sizeof(char) * (game->map.x_max_pos));
    for (int i = 0; i != game->map.len_pos; i++) {
        if (game->map.buffer_pos[i] == '\n') {
            y++;
            x = 0;
        } else {
            game->map.map_pos[y][x] = game->map.buffer_pos[i];
            x++;
        }
    }
    return (game->map.map_pos);
}