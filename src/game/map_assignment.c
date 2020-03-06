/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** assignment_map
*/

#include "proto.h"

void map_assignment(game_t *game)
{
    if (game->map.map[COLS][LINES] >= '2' && game->map.map[COLS][LINES] <= '5') {
        game->map.map[COLS][LINES] = 'x';
    }
    //display_map(game);
}