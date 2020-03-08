/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** who win
*/

#include "proto.h"

int who_win_user1(navy_t *navy)
{
    int count = 0;

    for (int y = 2; y < navy->map.y_max; y++) {
        for (int x = 2; x < navy->map.x_max; x++) {
            if (navy->map.map[y][x] >= '2' && <= '5')
                count++;
            }
        }
        if (count == 0)
            kill(navy->user1.pid_user2, SIGUSR1);
    return (0);
}

int who_win_user2(navy_t *navy)
{
    int count = 0;

    for (int y = 2; y < navy->map.y_max; y++) {
        for (int x = 2; x < navy->map.x_max; x++) {
            if (navy->map.map[y][x] >= '2' && <= '5')
                count++;
            }
        }
        if (count == 0)
            kill(navy->user2.pid_user1, SIGUSR2);
    return (0);
}