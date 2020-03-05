/*
** EPITECH PROJECT, 2020
** user2
** File description:
** connection with user2 and user1 and sig_handler
*/

#include "proto.h"

static int prepare_my_user2(game_t *game, char *pid1)
{
    game->user.pid_ennemy = to_number(pid1);
    my_putstr("my_pid:\t");
    my_putstr(show_number(getpid()));
    my_putchar('\n');
    if (kill(game->user.pid_ennemy, SIGUSR2) == -1)
        return (84);
    my_putstr("succesfully connected\n\n");
    return (0);
}

int user2(game_t *game, char *pid1)
{
    int user2 = 0;
    bool check = false;

    if ((user2 = prepare_my_user2(game, pid1)) == 84)
        return (84);
    if (create_map(game) == 84) {
        my_free(game);
        close(game->map.fd);
        return (84);
    }
    if (create_map_pos(game, game->user.pos2) == 84) {
        close(game->map.fd_pos);
        return (84);
    }
    if ((check = find_my_position(game)) == true)
        return (84);
    display_map(game);
    my_putstr("\nwaiting for ennemy's attack...\n");
    pause();
    return (0);
}