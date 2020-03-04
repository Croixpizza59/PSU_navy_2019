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
    int k = 0;
    int a = 0;

    for (int y = 0; y < Y_MAX; y++) {
        for (int x = 0; x < 3; x++) {
            if (game->map.map_pos[y][x] == ':') {
                ++x;
                i = checking_board(game, x, y, i);
                a = checking_board(game, 5, y, i);
                j = game->map.map_pos[y][x + 1] - '0';
                k = game->map.map_pos[y][6] - '0';
                if (j == game->map.map_pos[y][6] - '0') {
                    game->map.map[j + 1][i] = nb + '0';
                    while (i <= a) {
                        game->map.map[j + 1][i] = nb + '0';
                        i += 2;
                    }
                }
                else {
                    game->map.map[j + 1][i] = nb + '0';
                    while (j <= k) {
                        game->map.map[j + 1][i] = nb + '0';
                        j++;
                    }
                }
            }
        }
        ++nb;
    }
    display_map_sec(game);
    return (0);
}
