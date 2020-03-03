/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** turtle_hare
*/

#include "proto.h"

static bool first_check(game_t *game)
{
    char count;
    int count_sec = 0;
    bool check = false;
    bool final_check = false;

    for (int y = 0; y < game->map.y_max; y++) {
        for (int x = 0; x < game->map.x_max; x++) {
            if (game->map.map[y][x] >= '1' && game->map.map[y][x] <= '9') {
                count = game->map.map[y][x];
                check = true;
                break;
        }
        if (check == true)
            break;
    }
}
    for (int y = 0 ;y < game->map.y_max; y++) {
        for (int x = 0; x < game->map.x_max; x++) {
            if (game->map.map[y][x] == count)
                count_sec += 1;
        }
    }
    if (count_sec == 0)
        final_check = true;
    return (final_check);
}

char **turtle_hare_x(game_t *game)
{
    char nb;

    for (int y = 2; y < game->map.y_max; y++) {
        for (int x = 2; x < game->map.x_max; x++) {
            if (game->map.map[y][x] >= '1' && game->map.map[y][x] <= '9') {
                nb = game->map.map[y][x];
                x++;
                while (game->map.map[y][x] != nb) {
                    game->map.map[y][x] = nb;
                    if (game->map.map[y][x] == game->map.x_max)
                        break;
                }
            }
        }
    }
    return (game->map.map);
}