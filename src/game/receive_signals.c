/*
** EPITECH PROJECT, 2020
** navy
** File description:
** receive signals of kill user player
*/

#include "proto.h"

static void sig_handler_sig2(int signal, siginfo_t *sig, void *stream)
{
    (void)stream;
    (void)sig;
    static int count = 0;
    static int sec = 0;

    if (signal == 10)
        count ++;
    else if (signal == 12) {
        sec++;
        global = count;
        if (sec == 2)
            global = count;
        count = 0;
    }
}

int receive_signals(navy_t *navy)
{
    struct sigaction signal;

    my_putstr("waiting for enemy's attack...\n");
    signal.sa_sigaction = &sig_handler_sig2;
    signal.sa_flags = SA_RESTART;
    while (global == 0) {
        sigaction(10, &signal, NULL);
        sigaction(12, &signal, NULL);
        navy->coord.lines = global;
    }
    global = 0;
    while (global == 0) {
        sigaction(10, &signal, NULL);
        sigaction(12, &signal, NULL);
        navy->coord.cols = global + 1;
    }
    global = 0;
    return (0);
}