#include <criterion/criterion.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *multi_tok(char *input, char *delimiter) {
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

Test(tmpfunction, WIP)
{
    char input [] = "this is abc a big abc input string abc to split up";
    char *token = multi_tok(input, "abc");
    while (token != NULL) {
        printf("%s\n", token);
        token = multi_tok(NULL, "abc");
    }
}

