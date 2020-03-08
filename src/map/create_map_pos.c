/*
** EPITECH PROJECT, 2020
** navy
** File description:
** create_map_pos
*/

#include "proto.h"

static int basics_actions(navy_t *navy, char *map_pos)
{
    if ((navy->map_pos.size_2 = getstat(map_pos)) <= 0) {
        my_putstr("getstat failed\n");
        return (84);
    } else if (!(navy->map_pos.buffer_2 = malloc(sizeof(char) *
        (navy->map_pos.size_2))))
        return (84);
    if ((navy->map_pos.fd_2 = open(map_pos, O_RDONLY)) <= 0) {
        my_putstr("open failed\n");
        return (84);
    } else if ((navy->map_pos.len_2 = read(navy->map_pos.fd_2,
        navy->map_pos.buffer_2, navy->map_pos.size_2)) <= 0) {
        my_putstr("read failed\n");
        return (84);
    }
    return (0);
}

int create_map_pos(navy_t *navy, char *map_pos)
{
    navy->map_pos.buffer_2 = NULL;
    navy->map_pos.x_max_2 = 8;
    navy->map_pos.y_max_2 = 5;
    int basics = 0;

    if ((basics = basics_actions(navy, map_pos)) == 84)
        return (84);
    navy->map_pos.map2 = init_map_pos(navy);
    if (checking_letter(navy) == true) {
        my_putstr("Position Error\n");
        return (84);
    }
    return (0);
}