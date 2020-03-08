/*
** EPITECH PROJECT, 2020
** navy
** File description:
** signal_sending.c send signal at other player
*/

#include "proto.h"

int find_number(char buffer, int i)
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

int signal_sending_user1(navy_t *navy, char buffer, char buffer_sec)
{
    int lines = 0;
    int colms = 0;
    navy->coord.crypt = find_number(buffer, navy->coord.crypt);
    navy->coord.crypt_sec = buffer_sec - '0';

    while (lines < navy->coord.crypt) {
        kill(navy->user1.pid_user2, SIGUSR1);
        lines++;
        usleep(10000);
    }
    kill(navy->user1.pid_user2, SIGUSR2);
    usleep(10000);
    while (colms < navy->coord.crypt_sec) {
        kill(navy->user1.pid_user2, SIGUSR1);
        colms++;
        usleep(10000);
    }
    kill(navy->user1.pid_user2, SIGUSR2);
    return (0);
}