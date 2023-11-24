#ifndef HTTP_H
#define HTTP_H

#include <stddef.h>
#include "../config/config.h"

struct header
{
    char *type;
    char *data;
    struct header *next;
};

struct http_response 
{
    char *http_version;
    char *status_code;
    char *reason_phrase;
    struct header *header;
    char *body;
};

struct http_request
{
    char *command;
    char *path;
    char *version;
    struct header *headers;
};

struct http_request *parse(char *str);

char *get_piece(char *str, char *separator, size_t position);

char *get_first_line_from_http_message(char *http_message);
struct header *get_headers_http_message(char *http_message);

char *response_from_struct_response(struct http_response *response);

void check_method(char *method, struct http_response *response);
void check_version(char *version, struct http_response *response);
int check_headers(struct header *headers, struct config *config);
void check_valid_request(struct http_request *request, struct http_response *response);
void check_forbidden(char *ressource, struct http_response *response);
void check_found(char *ressource, struct http_response *response);
void do_status_line(struct http_request *request, struct http_response *response);

#endif /* !HTTP_H */