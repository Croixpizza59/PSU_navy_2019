/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** recept_win
*/

#include "proto.h"

static void sig_handler_who_win(int signal, siginfo_t *sig, void *test)
{
    (void)test;
    (void)sig;
    static int i = 0;

    if (signal == 10) {
        i = 1;
        global = i;
    }
    if (signal == 12) {
        i = 2;
        global = i;
    }
}

int recept_win(void)
{
    int sign = 0;
    struct sigaction signal;

    signal.sa_sigaction = &sig_handler_who_win;
    signal.sa_flags = SA_SIGINFO;
    sigaction(10, &signal, NULL);
    signal.sa_sigaction = &sig_handler_who_win;
    signal.sa_flags = SA_SIGINFO;
    sigaction(12, &signal, NULL);
    while (global == 0) {
        pause();
        sign = global;
    }
    if (sign == 1) {
        my_putstr("Ennemy won\n");
        return (-84);
    }
    global = 0;
    return (0);
}