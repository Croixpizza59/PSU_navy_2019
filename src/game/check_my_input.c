/*
** EPITECH PROJECT, 2020
** navy
** File description:
** check_my_input
*/

#include "proto.h"

int check_my_input(char *buffer)
{
    int lenght = 0;

    if (buffer[0] < 'A' || buffer[0] > 'H')
        return (84);
    if (buffer[1] < '1' || buffer[1] > '8')
        return (84);
    if ((lenght = my_lenght(buffer)) != 3)
        return (84);
    return (0);
}