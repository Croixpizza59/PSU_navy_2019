/*
** EPITECH PROJECT, 2020
** navy
** File description:
** main function for navy project
*/

#include "proto.h"

int global = 0;

static void my_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    first_player_pid: only for the 2nd player.");
    my_putstr(" pid of the first player.\n");
    my_putstr("    navy_positions: file representing");
    my_putstr(" the positions of the ships.\n");
}

int main(int ac, char *av[])
{
    navy_t navy = {0};
    navy.verif.check = false;

    if (ac > 3 || ac < 2)
        return (84);
    else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_help();
        return (0);
    }
    if (navy_funct(&navy, ac, av) == 84)
        return (84);
    return (0);
}