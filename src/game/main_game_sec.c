/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main_game_sec
*/

#include "proto.h"

static int before_check_sec(char buffer, int i)
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

int signal_checking_sec(game_t *game, char buffer, char buffer_sec)
{
    int crypt = 0;
    int crypt_sec = 0;
    int lines = 0;
    int colms = 0;

    crypt = before_check_sec(buffer, crypt);
    crypt_sec = buffer_sec - '0';

    usleep(10000);
    while (lines < crypt) { // horizontal
        kill(game->user.pid_user1, SIGUSR1);
        lines++;
        usleep(10000);
    }
    kill(game->user.pid_user1, SIGUSR2); // separation
    usleep(10000);
    while (colms < crypt_sec) { // vertical
        kill(game->user.pid_user1, SIGUSR1);
        colms++;
        usleep(10000);
    }
    kill(game->user.pid_user1, SIGUSR2); // final
    return (0);
}

int main_game_sec(game_t *game)
{
    size_t n = 0;
    ssize_t get_rd = 0;
    char *buffer = malloc(sizeof(char) * 10);
    bool condition = false;
    int check_buffer = 0;

    while (1) {
        my_putstr("attack:\t");
        get_rd = getline(&buffer, &n, stdin);
        if (get_rd <= 0)
            return (84);
        if ((check_buffer = check_my_buffer(buffer)) != 84) {
            signal_checking_sec(game, buffer[0], buffer[1]);
            break;
        }
        else {
            my_putstr("wrong position\n");
            return (main_game_sec(game));
        }
    }
    map_assignment(game);
    return (0);
}