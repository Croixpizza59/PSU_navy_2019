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
    game.user.check = false;

    if (ac > 3 || ac == 1)
        return (84);
    else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        helper();
        return (0);
    }
    if (create_map_pos(&game) == 84) {
        close(game.map.fd_pos);
        return (84);
    }
    if (navy(&game, ac, av) == 84)
        return (84);
    return (0);
}