/*
** EPITECH PROJECT, 2020
** checking
** File description:
** checking
*/

#include "proto.h"

static bool check_my_point(game_t *game)
{
    int x = 1;
    int x_sec = 4;

    for (int y = 0; y < game->map.y_max_pos; y++) {
        if (game->map.map_pos[y][x] != ':') {
            printf("deux point place 2\n");
            game->user.check = true;
        }
    }
    for (int y = 0; y < game->map.y_max_pos; y++) {
        if (game->map.map_pos[y][x_sec] != ':') {
            printf("deux points place 5\n");
            game->user.check = true;
        }
    }
    return (game->user.check);
}

bool checking_letter(game_t *game)
{
    int x = 0;
    int y = 0;

    if (check_my_point(game) == true)
        game->user.check = true;
    for (y = 0; y < game->map.y_max_pos; y++) {
        for (x = 0; x < game->map.x_max_pos; x++) {
            if (game->map.map_pos[y][x] >= 'A' && game->map.map_pos[y][x] <= 'Z') {
                if (game->map.map_pos[y][x] > 'H') {
                    printf("if 1\n");
                    game->user.check = true;
                }
            }
            else if (game->map.map_pos[y][x] >= '0' && game->map.map_pos[y][x] <= '9')
                if (game->map.map_pos[y][x] > '8' || game->map.map_pos[y][x] < '1')
                    game->user.check = true;
            }
        }
    return (game->user.check);
}