/*
** EPITECH PROJECT, 2020
** init_map_pos.c
** File description:
** initialiaze array of position
*/

#include "proto.h"

char **init_map_pos(game_t *game)
{
    int x = 0;
    int y = 0;
    game->map.map_pos = malloc(sizeof(char *) * (RAM));

    for (int i = 0; i < game->map.len_pos; i++)
        game->map.map_pos[i] = malloc(sizeof(char) * (RAM));
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