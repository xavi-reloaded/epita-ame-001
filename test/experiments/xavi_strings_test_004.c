#include <criterion/criterion.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *tokenize(char *input, char *delimiter, size_t position) {
    static char *string;
    if (input != NULL)
        string = input;
    if (string == NULL)
        return string;
    char *end = strstr(string, delimiter);
    if (end == NULL) {
        char *temp = string;
        string = NULL;
        return temp;
    }
    char *temp = string;
    *end = '\0';
    string = end + strlen(delimiter);
    return temp;
}

char *get_piece(char *str, char *separator, size_t position)
{
    char *token = tokenize(str, separator, position);
    size_t current_position = 1;
    while (token != NULL && current_position < position) {
        token = tokenize(NULL, separator, position);
        current_position++;
    }
    return token;
}


Test(tmpfunction, WIP)
{
    char input [] = "this isFSa mierderFSfor you";
    char *token = get_piece(input, "FS", 2);
    printf("%s\n", token);
}

