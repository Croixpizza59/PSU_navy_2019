/*
** EPITECH PROJECT, 2020
** user1_connection
** File description:
** user_one connection with user2 and sig_handler
*/

#include "proto.h"

void sig_handler(int i, siginfo_t *sig, void *test)
{
    (void)i;
    (void)test;
    global = sig->si_pid;
    my_putstr("\nenemy connected\n\n");
}

static int prepare_my_user1(game_t *game)
{
    bool check = false;

    struct sigaction signal;
    signal.sa_handler = &sig_handler;
    signal.sa_flags = SA_SIGINFO;
    my_putstr("my_pid:\t");
    my_putstr(show_number(getpid()));
    my_putstr("\nwaiting for enemy connection...\n");
    sigemptyset(&signal.sa_mask);
    sigaction(12, &signal, NULL);
    if (create_map(game) == 84) {
        my_free(game);
        close(game->map.fd);
        return (84);
    }
    return (0);
}

int user1(game_t *game)
{
    int user1 = 0;

    if ((user1 = prepare_my_user1(game)) == 84)
        return (84);
    if (create_map_pos(game, game->user.pos1) == 84) {
        close(game->map.fd_pos);
        return (84);
    }
    if ((find_my_position(game)) == true)
        return (84);
    pause();
    game->user.pid_user2 = global;
    display_map(game);
    my_putchar('\n');
    main_game(game);
    return (0);
}
