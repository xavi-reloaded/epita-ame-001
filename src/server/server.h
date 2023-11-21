#ifndef SERVER_H
#define SERVER_H
#include <stddef.h>

int create_and_bind(const char *node, const char *service);

void respond(int client_fd, const char *buffer, size_t bytes);

void communicate(int client_fd, const char *root_dir);

void start_server(int server_socket, const char *root_dir);

#endif /* !SERVER_H */
