/*
** EPITECH PROJECT, 2020
** navy
** File description:
** player1
*/

#include "proto.h"

static int game_connect_user1(navy_t *navy)
{
    while (1) {
        if (get_input_user1(navy) == 84)
            return (84);
        global = 0;
        hit_or_miss(navy);
        receive_signals(navy);
        draw_ennem_actions(navy);
        navy->coord.hm = 0;
        map_stocking_user1(navy);
        display_map(navy);
    }
    return (0);
}

int player1_funct(navy_t *navy)
{
    if (connection_user1() == 84)
        return (84);
    if (map_maker(navy) == 84)
        return (84);
    if (replace_boat_positions(navy) == true)
        return (84);
    pause();
    navy->user1.pid_user2 = global;
    display_map(navy);
    if (game_connect_user1(navy) == 84)
        return (84);
    return (0);
}