/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "proto.h"

int main(int ac, char **av)
{
    game_t game = {0};

    /*if (ac == 1)
        user1(&game);
    else if (ac == 2)
        user2(&game, av[1]);
    else
        return (84);*/
    if (create_map(&game) == 84)
        return (84);
    return (0);
}