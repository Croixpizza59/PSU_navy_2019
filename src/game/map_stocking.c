/*
** EPITECH PROJECT, 2020
** navy
** File description:
** map stocking_signals
*/

#include "proto.h"

void map_stocking_user2(navy_t *navy)
{
    usleep(10000);
    if (navy->map.map[COLS][LINES] >= '2' &&
    navy->map.map[COLS][LINES] <= '5') {
        navy->map.map[COLS][LINES] = 'x';
        kill(navy->user2.pid_user1, SIGUSR2);
    } else if (navy->map.map[COLS][LINES] == '.') {
        navy->map.map[COLS][LINES] = 'o';
        kill(navy->user2.pid_user1, SIGUSR1);
    }
}

void map_stocking_user1(navy_t *navy)
{
    usleep(10000);
    if (navy->map.map[COLS][LINES] >= '2' &&
    navy->map.map[COLS][LINES] <= '5') {
        navy->map.map[COLS][LINES] = 'x';
        kill(navy->user1.pid_user2, SIGUSR2);
    } else if (navy->map.map[COLS][LINES] == '.') {
        navy->map.map[COLS][LINES] = 'o';
        kill(navy->user1.pid_user2, SIGUSR1);
    }
}