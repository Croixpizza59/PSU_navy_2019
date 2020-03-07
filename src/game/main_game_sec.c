/*
** EPITECH PROJECT, 2020
** main_game_sec.c
** File description:
** main_game_sec
*/

#include "proto.h"

int before_check_sec(char buffer, int i)
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

int main_game_sec(game_t *game)
{
    size_t n = 0;
    ssize_t get_rd = 0;
    char *buffer = malloc(sizeof(char) * 10);
    int check_buffer = 0;

    while (1) {
        my_putstr("attack:\t");
        get_rd = getline(&buffer, &n, stdin);
        if (get_rd <= 0)
            return (84);
        if ((check_buffer = check_my_buffer(buffer)) != 84) {
            game->user.receptor = buffer;
            signal_checking_sec(game, buffer[0], buffer[1]);
            break;
        }
        else
            my_putstr("wrong position\n");
    }
    return (0);
}