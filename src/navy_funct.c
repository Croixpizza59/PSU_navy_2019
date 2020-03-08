/*
** EPITECH PROJECT, 2020
** navy
** File description:
** navy function --> contain all src functions
*/

#include "proto.h"

int navy_funct(navy_t *navy, int ac, char **av)
{
    if (ac == 2) {
        navy->map_pos.pos = av[1];
        if (player1_funct(navy) == 84)
            return (84);
    }
    else if (ac == 3) {
        navy->map_pos.pos = av[2];
        if (player2_funct(navy, av[1]) == 84)
            return (84);
    }
    return (0);
}