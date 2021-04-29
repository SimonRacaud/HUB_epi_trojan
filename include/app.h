/*
** EPITECH PROJECT, 2021
** 0_C_BASE_FILES
** File description:
** app
*/

#ifndef APP_H_
#define APP_H_

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "daemon.h"
#include "socket.h"
#include "utility.h"
#include "server_t.h"

#ifdef EXIT_FAILURE
    #undef EXIT_FAILURE
#endif
#define EXIT_FAILURE 84

/// Config
#define PORT       42
#define MAX_CLIENT 1

/// Core
int app_start(void);

int signal_init(void);

int process_command(const char *command, server_t *server, shell_t *shell);

/// SHELL
void shell_stop(shell_t *shell);
int shell_client_init(socket_t *client, shell_t *shell);
int send_shell_command(shell_t *shell, const char *command);

/// USER
bool is_logout_command(const char *command);
void logout_user(server_t *server);

#endif /* !APP_H_ */