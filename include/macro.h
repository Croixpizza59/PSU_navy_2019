/*
** EPITECH PROJECT, 2020
** macro
** File description:
** navy macro
*/

#ifndef MACRO
#define MACRO

#define RAM 2048
#define Y_MAX game->map.y_max_pos
#define X_MAX game->map.x_max_pos
#define CHECK game->user.check
#define CURSOR(y, x) game->map.map_pos[y][x]
#define LETTER(i) (i >= 'A' && i <= 'Z')
#define NUMBER(i) (i >= '1' && i <= '9')

// define positions structure

#define J game->pos.j
#define I game->pos.i
#define A game->pos.a
#define K game->pos.k
#define NB game->pos.nb
#define COUNT1 game->pos.count1
#define COUNT2 game->pos.count2

/* define letter for build map */

#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define H 8

#endif
