/*
** EPITECH PROJECT, 2020
** signal checking.c
** File description:
** signal_checking_sec
*/

#include "proto.h"

int signal_checking_sec(game_t *game, char buffer, char buffer_sec)
{
    int lines = 0;
    int colms = 0;
    game->user.crypt = before_check_sec(buffer, game->user.crypt);
    game->user.crypt_sec = buffer_sec - '0';

    usleep(10000);
    while (lines < game->user.crypt) {
        kill(game->user.pid_user1, SIGUSR1);
        lines++;
        usleep(10000);
    }
    kill(game->user.pid_user1, SIGUSR2);
    usleep(10000);
    while (colms < game->user.crypt_sec) {
        kill(game->user.pid_user1, SIGUSR1);
        colms++;
        usleep(10000);
    }
    kill(game->user.pid_user1, SIGUSR2);
    return (0);
}