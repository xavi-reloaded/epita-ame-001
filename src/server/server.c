#define _GNU_SOURCE
#define _PSIX_C_SOURCE 200809L
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "server.h"
#include "httpcommand.h"


#define BUFFER_SIZE 1024

int create_and_bind(const char *node, const char *service)
{
    struct addrinfo hints = { 0 };
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_IP;

    struct addrinfo *res = NULL;
    int server_socket = -1;

    if (getaddrinfo(node, service, &hints, &res) == -1)
    {
        fprintf(stderr, "getaddrinfo failed: %s", strerror(errno));
        return -1;
    }

    struct addrinfo *current = NULL;

    for (current = res; current != NULL; current = current->ai_next) {
        server_socket = socket(current->ai_family, current->ai_socktype, current->ai_protocol);
        if (server_socket == -1) {
            continue;
        }

        if (bind(server_socket, current->ai_addr, current->ai_addrlen) == 0) {
            break;
        }
        close(server_socket);
        server_socket = -1;
    }

    freeaddrinfo(res);

    if (current == NULL) {
        fprintf(stderr, "Failed to create and bind socket");
        return -1;
    }

    return server_socket;
}

void respond(int client_fd, const char *buffer, size_t bytes)
{
    size_t total = 0;
    ssize_t sent = 0;
    while (total != bytes)
    {
        sent = send(client_fd, buffer, bytes, 0);
        if (sent == -1)
        {
            fprintf(stderr, "Send failed: %s", strerror(errno));
            return;
        }
        total += sent;
    }
}

void communicate(int client_fd, const char *root_dir)
{
    ssize_t bytes = 0;
    char buffer[BUFFER_SIZE];
    fprintf(stdout, "root: \n%s", root_dir);
    while ((bytes = recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0)
    {
        char *my_var = malloc(sizeof(char) * (bytes + 1));
        for (ssize_t i = 0; i < bytes; i++)
        {
            my_var[i] = buffer[i];
        }
        my_var[bytes] = '\0';
        
        fprintf(stdout, "Received message: \n%s", my_var);

        struct httprequest *res = parse(my_var);
        fprintf(stdout, "Received message: \n%s", res->command);

        // EMPIEZA LA FIESTA BUSCANDO EN ROOT DIR
        // 1. no existe => (err(404))
        // 2. si existe te paso el archivo (getFile(char *filename))
        // 3. 

        respond(client_fd, my_var, strlen(my_var));

        free(my_var);

        


    }

    // here check_buffer
        /*
        if (is_word)
            fprintf(stdout, "Received message: \n%.*s", int_bytes, buffer);
        else if (is_file)
            do_file(client_fd, buffer, bytes);
        else if (is_image)
            do_image(client_fd, buffer, bytes);
        else if .......
        */
    // fprintf(stdout, "Received message: \n%s", my_var);
    // respond(client_fd, my_var, strlen(my_var));
    
}

void start_server(int server_socket, const char *root_dir)
{
    if (listen(server_socket, 10) == -1)
    {
        fprintf(stderr, "Failed to start server: %s", strerror(errno));
        return;
    }
    fprintf(stdout, "Start accepting connections\n");
    while (1)
    {
        int client_fd = accept(server_socket, NULL, NULL);
        if (client_fd != -1)
        {
            communicate(client_fd, root_dir);
        }
    }
}

