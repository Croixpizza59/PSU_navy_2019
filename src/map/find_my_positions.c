/*
** EPITECH PROJECT, 2020
** find_my_position
** File description:
** find position of my_boat
*/

#include "proto.h"

static void display_map_sec(game_t *game)
{
    int x;
    int y;

    my_putstr("enemy’s positions:\n");
    for (y = 0; y < game->map.y_max; y++) {
        for (x = 0; x < game->map.x_max; x++)
            my_putchar(game->map.map[y][x]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

int find_my_position(game_t *game)
{
    int nb = 2;
    int i = 0;
    int j = 0;

    for (int y = 0; y < Y_MAX; y++) {
        for (int x = 0; x < X_MAX; x++) {
            if (game->map.map_pos[y][x] == ':') {
                ++x;
                i = checking_board(game, x, y, i);
                j= game->map.map_pos[y][x + 1] - '0';
                game->map.map[j + 1][i] = nb + '0';
            }
        }
        ++nb;
    }
    game->map.map = turtle_hare_x(game);
    display_map_sec(game);
    return (0);
}
