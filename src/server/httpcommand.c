#define _GNU_SOURCE
#define _PSIX_C_SOURCE 200809L
#include <stdio.h>

void parse(const char *command)
{
    fprintf(stdout, "Received message: \n%s", command);
}
