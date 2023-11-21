#define _GNU_SOURCE
#define _PSIX_C_SOURCE 200809L
#include <string.h>
#include <stdio.h>
#include "httpcommand.h"

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s mierder for you", argv[0]);
        return 1;
    }

    tokenizer(argv[1]);


    return 0;
}


