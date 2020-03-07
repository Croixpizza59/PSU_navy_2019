/*
** EPITECH PROJECT, 2020
** suer2.c
** File description:
** user2
*/

#include "proto.h"

static int test(game_t *game)
{
    while (1) {
        my_putstr("\nwaiting for ennemy's attack...\n");
        receive_signal(game);
        main_game_sec(game);
        global = 0;
        who_kill_who(game);
        map_assignment_user2(game);
        display_map(game);
        recept_win();
        who_win_user2(game);
    }
    return (0);
}

int user2(game_t *game, char *pid1)
{
    int user2 = 0;
    bool check = false;
    game->user.pid_user1 = to_number(pid1);

    if ((user2 = prepare_my_user2(game, pid1)) == 84)
        return (84);
    create_map_sec(game);
    if (create_map(game) == 84) {
        my_free(game);
        return (84);
    }
    if (create_map_pos(game, game->user.pos) == 84) {
        close(game->map.fd_pos);
        return (84);
    }
    if ((check = find_my_position(game)) == true)
        return (84);
    display_map(game);
    test(game);
    return (0);
}