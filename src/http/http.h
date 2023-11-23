#ifndef HTTP_H
#define HTTP_H

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

char *get_piece(char *str, char *separator, size_t position);

char *get_first_line_from_http_message(char *http_message);
char *get_headers_http_message(char *http_message);

char *response_from_struct_response(struct http_response *response);

#endif /* !HTTP_H */