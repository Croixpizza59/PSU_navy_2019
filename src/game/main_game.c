/*
** EPITECH PROJECT, 2020
** main_game
** File description:
** main_game
*/

#include "proto.h"

int main_game(game_t *game)
{
    size_t n = 0;
    ssize_t get_rd = 0;
    char *buffer = NULL;
    int check_buffer = 0;

    while (1) {
        my_putstr("attack:\t");
        get_rd = getline(&buffer, &n, stdin);
        if (get_rd <= 0)
            return (84);
        if ((check_buffer = check_my_buffer(buffer)) != 84) {
            signal_checking(game, buffer[0], buffer[1]);
            break;
        }
        else
            my_putstr("wrong position\n");
    }
    return (0);
}