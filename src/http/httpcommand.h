#ifndef HTTPCOMMAND_H
#define HTTPCOMMAND_H
#include <stddef.h>

struct httprequest
{
    char *command;
    char *argument;
    char *version;
};

void tokenizer(char *command);
struct httprequest *parse(char *str);

#endif /* !HTTPCOMMAND_H */
