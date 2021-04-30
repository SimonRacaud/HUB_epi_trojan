/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 logout_user.c
*/

#include "troyan_server.h"

void client_disconnect(server_t *server)
{
    if (server->client_connected) {
        socket_close(&server->client);
        server->client_connected = false;
        fprintf(stderr, CLIENT_DISCONNECT);
    }
}