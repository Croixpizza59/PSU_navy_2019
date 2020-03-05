/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main game
*/

#include "proto.h"

int main_game(game_t *game)
{
    size_t n = 0;
    ssize_t get_rd = 0;
    char *buffer = malloc(sizeof(char) * 10);
    bool condition = false;
    int check_buffer = 0;

    while (condition != true) {
        my_putstr("attack:\t");
        if ((get_rd = getline(&buffer, &n, stdin)) <= 0)
            return (84);
        if ((check_buffer = check_my_buffer(game, buffer)) != 84)
            condition = true;
        else
            my_putstr("wrong position\n");
        //signal_checking(game, buffer[0], buffer[1]);
    }
    return (0);
}