/*
** EPITECH PROJECT, 2020
** map_assigment.c
** File description:
** map_assigment
*/

#include "proto.h"

void map_assignment(game_t *game)
{
    if (game->map.map[COLS][LINES] >= '2' && game->map.map[COLS][LINES] <= '5')
        game->map.map[COLS][LINES] = 'x';
    else {
        game->map.map[COLS][LINES] = 'o';
    }
}