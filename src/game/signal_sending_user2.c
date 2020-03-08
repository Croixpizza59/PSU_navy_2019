/*
** EPITECH PROJECT, 2020
** navy
** File description:
** signal_sending_user2
*/

#include "proto.h"

int signal_sending_user2(navy_t *navy, char buffer, char buffer_sec)
{
    int lines = 0;
    int colms = 0;
    navy->coord.crypt = find_number(buffer, navy->coord.crypt);
    navy->coord.crypt_sec = buffer_sec - '0';

    while (lines < navy->coord.crypt) {
        kill(navy->user2.pid_user1, SIGUSR1);
        lines++;
        usleep(10000);
    }
    kill(navy->user2.pid_user1, SIGUSR2);
    usleep(10000);
    while (colms < navy->coord.crypt_sec) {
        kill(navy->user2.pid_user1, SIGUSR1);
        colms++;
        usleep(10000);
    }
    kill(navy->user2.pid_user1, SIGUSR2);
    usleep(10000);
    return (0);
}