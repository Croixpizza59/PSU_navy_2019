/*
** EPITECH PROJECT, 2020
** navy
** File description:
** player_2_funct who control all of connection
*/

#include "proto.h"

static int game_connect_user2(navy_t *navy)
{
    while (1) {
        receive_signals(navy);
        map_stocking_user2(navy);
        if (get_input_user2(navy) == 84)
            return (84);
        global = 0;
        hit_or_miss(navy);
        display_map(navy);
    }
    return (0);
}

int player2_funct(navy_t *navy, char *pid1)
{
    navy->user2.pid_user1 = to_number(pid1);

    if (connection_user2(navy, pid1) == 84)
        return (84);
    if (map_maker(navy) == 84)
        return (84);
    if (replace_boat_positions(navy) == true)
        return (84);
    display_map(navy);
    if (game_connect_user2(navy) == 84)
        return (84);
    return (0);
}