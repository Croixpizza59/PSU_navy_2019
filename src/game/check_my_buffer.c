/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** check my_buffer -> check the error_handling of buffer
*/

#include "proto.h"

int check_my_buffer(game_t *game, char *buffer)
{
    int lenght = 0;

    if (buffer[0] < 'A' || buffer[0] > 'F')
        return (84);
    if (buffer[1] < '1' || buffer[1] > '8')
        return (84);
    if ((lenght = my_lenght(buffer)) != 3)
        return (84);
    return (0);
}