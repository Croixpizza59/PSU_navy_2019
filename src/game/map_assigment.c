/*
** EPITECH PROJECT, 2020
** map_assigment.c
** File description:
** map_assigment
*/

#include "proto.h"

void map_assignment_user2(game_t *game)
{
    if (game->map.map[COLS][LINES] >= '2' &&
    game->map.map[COLS][LINES] <= '5') {
        game->map.map[COLS][LINES] = 'x';
        kill(game->user.pid_user1, SIGUSR2);
    }
    else if (game->map.map[COLS][LINES] == '.'){
        game->map.map[COLS][LINES] = 'o';
        kill(game->user.pid_user1, SIGUSR1);
    }
}

void map_assignment_user1(game_t *game)
{
    if (game->map.map[COLS][LINES] >= '2' &&
    game->map.map[COLS][LINES] <= '5') {
        game->map.map[COLS][LINES] = 'x';
        kill(game->user.pid_user2, SIGUSR2);
    }
    else if (game->map.map[COLS][LINES] == '.'){
        game->map.map[COLS][LINES] = 'o';
        kill(game->user.pid_user2, SIGUSR1);
    }
}
