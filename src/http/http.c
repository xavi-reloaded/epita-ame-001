#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "http.h"

char *get_piece(char *str, char *separator, size_t position)
{
    size_t current_position = 1;

    char *token = strtok(str, separator);
    /*while (token != NULL && current_position < position) 
    {
        token = strtok(NULL, separator);
        if (current_position == position)
            return token;
        current_position++;
    }*/
    return token;
}

char *get_first_line_from_http_message(char *http_message)
{
    return get_piece(http_message, "CRLF", 1);
}
