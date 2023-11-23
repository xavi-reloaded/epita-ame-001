#ifndef HTTPCOMMAND_H
#define HTTPCOMMAND_H
#include <stddef.h>

struct httprequest
{
    char *command;
    char *path;
    char *version;
    char *headers;
};

struct httprequest *parse(char *str);

#endif /* !HTTPCOMMAND_H */
