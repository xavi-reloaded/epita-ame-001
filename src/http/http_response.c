#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "http.h"

static size_t header_len(struct http_response *response)
{
    size_t len = 0;
    struct header *h_copy = response->header;
    while (h_copy != NULL)
    {
        len += strlen(h_copy->data) * sizeof(char);
        len += strlen(h_copy->type) * sizeof(char);
        h_copy = h_copy->next;
    }
    return len;
}

char *response_from_struct_response(struct http_response *response) //what with sp and crlf
{
    size_t c = sizeof(char);
    size_t line_len = c * strlen(response->http_version) + c * 3 + c * strlen(response->reason_phrase);
    size_t h_len = header_len(response);
    size_t b_len = c * strlen(response->body);

    char *res = malloc(line_len + h_len + b_len + 1);

    strcat(res, response->http_version);

    int int_status = response->status_code;
    char *status = malloc(c * 3);
    for (size_t i = 0; i < 3; i++)
    {
        status[3 - i] = int_status % 10;
        int_status = int_status / 10;
    }
    strcat(res, status);

    strcat(res, response->reason_phrase);

    struct header *h_copy = response->header;
    while (h_copy != NULL)
    {
        strcat(res, h_copy->type);
        strcat(res, h_copy->data);
        h_copy = h_copy->next;
    }

    strcat(res, response->body);

    return res;
}