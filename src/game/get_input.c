/*
** EPITECH PROJECT, 2020
** navy
** File description:
** get_input
*/

#include "proto.h"

int get_input_user1(navy_t *navy)
{
    ssize_t get_rd = 0;
    size_t n = 0;
    char *buffer = NULL;
    int check_buffer = 0;

    my_putstr("attack:\t");
    get_rd = getline(&buffer, &n, stdin);
    if (get_rd <= 0)
        return (84);
    if ((check_buffer = check_my_input(buffer)) != 84) {
        signal_sending_user1(navy, buffer[0], buffer[1]);
    } else {
        my_putstr("wrong position\n");
        return (get_input_user1(navy));
    }
    return (0);
}

int get_input_user2(navy_t *navy)
{
    ssize_t get_rd = 0;
    size_t n = 0;
    char *buffer = NULL;
    int check_buffer = 0;

    my_putstr("attack:\t");
    get_rd = getline(&buffer, &n, stdin);
    if (get_rd <= 0)
        return (84);
    if ((check_buffer = check_my_input(buffer)) != 84) {
        signal_sending_user2(navy, buffer[0], buffer[1]);
    } else {
        my_putstr("wrong position\n");
        return (get_input_user2(navy));
    }
    return (0);
}