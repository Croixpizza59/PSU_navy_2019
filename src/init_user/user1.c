/*
** EPITECH PROJECT, 2020
** user1.c
** File description:
** user1
*/

#include "proto.h"

static int test_usr1(game_t *game)
{
    if (main_game(game) == 84)
        return (84);
    my_putstr("waiting for ennemy's attack...\n");
    global = 0;
    receive_signal(game);
    map_assignment_user1(game);
    who_kill_who(game);
    display_map(game);
    who_win_user1(game);
    return (0);
}

int user1(game_t *game)
{
    int user1 = 0;

    if ((user1 = prepare_my_user1(game)) == 84)
        return (84);
    if (create_map_pos(game, game->user.pos) == 84) {
        close(game->map.fd_pos);
        return (84);
    }
    if ((find_my_position(game)) == true)
        return (84);
    pause();
    game->user.pid_user2 = global;
    display_map(game);
    my_putchar('\n');
    while (1) {
        if (test_usr1(game) == 84)
            return (84);
    }
    return (0);
}