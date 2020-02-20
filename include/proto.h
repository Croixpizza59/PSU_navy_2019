/*
** EPITECH PROJECT, 2020
** proto
** File description:
** proto
*/

#ifndef PROTO_NAVY
#define PROTO_NAVY

#include "struct.h"
#include "proto_lib.h"

void process_info(void);
int kill_it(pid_t pid);
void who_sig_me(int one, int sec, pid_t pid);
void signal_handler();
void signal_handler_usr2();

#endif