/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** signal check and description
*/

#include "proto.h"

static int before_check(char buffer, int i)
{
    if (buffer == 'A')
        i = 2;
    if (buffer == 'B')
        i = 4;
    if (buffer == 'C')
        i = 6;
    if (buffer == 'D')
        i = 8;
    if (buffer == 'E')
        i = 10;
    if (buffer == 'F')
        i = 12;
    if (buffer == 'G')
        i = 14;
    if (buffer == 'H')
        i = 16;
    return (i);
}

int signal_checking(game_t *game, char buffer, char buffer_sec)
{
    int crypt = 0;
    int crypt_sec = 0;
    int lines = 0;
    int colms = 0;

    crypt = before_check(buffer, crypt);
    crypt_sec = buffer_sec - '0';

    usleep(10000);
    while (lines < crypt) { // horizontal
        kill(game->user.pid_user2, SIGUSR1);
        lines++;
        usleep(10000);
    }
    kill(game->user.pid_user2, SIGUSR2); // separation
    usleep(10000);
    while (colms < crypt_sec) { // vertical
        kill(game->user.pid_user2, SIGUSR1);
        colms++;
        usleep(10000);
    }
    kill(game->user.pid_user2, SIGUSR2); // final
    return (0);
}