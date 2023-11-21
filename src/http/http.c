#include "http.h"

char *get_piece(char *str, const char *separator, size_t position)
{
    char *token;
    size_t current_position = 1;

    token = strtok(str, separator);
    while (token != NULL) 
    {
        token = strtok(NULL, separator);
        if (current_position == position)
            return token;
        current_position++;
    }
    return NULL;
}

char *get_first_line_from_http_message(const char *http_message)
{
    return get_piece(http_message, "CRLF", 1);
}
