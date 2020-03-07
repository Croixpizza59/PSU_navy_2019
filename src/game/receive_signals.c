/*
** EPITECH PROJECT, 2020
** receive_signals.c
** File description:
** receive_signals
*/

#include "proto.h"

void sig_handler_sec(int signal, siginfo_t *sig, void *test)
{
    (void)test;
    (void)sig;
    static int count = 0;
    static int sec = 0;

    if (signal == 10) {
        count ++;
    }
    else if (signal == 12) {
        sec++;
        global = count;
        if (sec == 2)
            global = count;
        count = 0;
    }
}

int receive_signal(game_t *game)
{
    struct sigaction signal;
    signal.sa_sigaction = &sig_handler_sec;
    signal.sa_flags = SA_RESTART;
    sigaction(10, &signal, NULL);
    signal.sa_sigaction = &sig_handler_sec;
    signal.sa_flags = SA_RESTART;
    sigaction(12, &signal, NULL);
    while (global == 0) {
        pause();
        game->coord.lines = global;
    }
    global = 0;
    while (global == 0) {
        pause();
        game->coord.cols = global + 1;
    }
    global = 0;
    return (0);
}