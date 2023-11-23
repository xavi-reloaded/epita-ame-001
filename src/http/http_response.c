#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "http.h"

static char *body_as_string(char * path) // TODO
{
    return NULL;
}

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

char *response_from_struct_response(struct http_response *response) // I consider body_as_string
{
    size_t c = sizeof(char);
    size_t line_len = c * strlen(response->http_version) + c * strlen(response->status_code) + c * strlen(response->reason_phrase);
    size_t h_len = header_len(response);
    size_t b_len = c * strlen(response->body);
    size_t sp_crlf_len = c * (4 + h_len * 2);

    char *res = malloc(line_len + h_len + b_len + sp_crlf_len + 1);

    strcpy(res, response->http_version);
    strcat(res, " ");
    strcat(res, response->status_code);
    strcat(res, " ");
    strcat(res, response->reason_phrase);
    strcat(res, "\n");

    struct header *h_copy = response->header;
    while (h_copy != NULL)
    {
        strcat(res, h_copy->type);
        strcat(res, " ");
        strcat(res, h_copy->data);
        strcat(res, "\n");
        h_copy = h_copy->next;
    }
    strcat(res, "\n");

    strcat(res, response->body);
    return res;
}