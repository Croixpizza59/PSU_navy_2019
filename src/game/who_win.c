/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** who_win
*/

#include "proto.h"

int who_win_user1(game_t *game)
{
    int count = 0;

    for (int y = 2; y < game->map.y_max; y++) {
        for (int x = 2; x < game->map.x_max; x++) {
            if (game->map.map[y][x] >= '2' && game->map.map[y][x] <= '5')
                ++count;
        }
    }
    if (count == 0) {
        my_putstr("I won\n");
        kill(game->user.pid_user2, SIGUSR1);
    }
    else
        kill(game->user.pid_user2, SIGUSR2);
    return (0);
}

int who_win_user2(game_t *game)
{
    int count = 0;

    for (int y = 2; y < game->map.y_max; y++) {
        for (int x = 2; x < game->map.x_max; x++) {
            if (game->map.map[y][x] >= '2' && game->map.map[y][x] <= '5')
                ++count;
        }
    }
    if (count == 0) {
        my_putstr("I won\n");
        kill(game->user.pid_user1, SIGUSR1);
    }
    else
        kill(game->user.pid_user2, SIGUSR2);
    return (0);
}