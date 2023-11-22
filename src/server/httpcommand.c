#define _GNU_SOURCE
#define _PSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "httpcommand.h"
#include "../http/http.h"

#define COMMAND_GET GET
#define COMMAND_HEAD HEAD

struct httprequest *parse(char str[]) {
  char separator[] = "SP";
  char *command = get_piece(str, separator, 1);
  char *argument = get_piece(str, separator, 2);

  struct httprequest *res = malloc(sizeof(struct httprequest));
  res->command = command;
  res->argument = argument;

  return res;
  
}

void tokenizer(char *command)
{
    printf("FULL STRING IS [%s] \n", command);
    struct httprequest *res = parse(command);
    printf("q [%s] \n", res->command);
    printf("w [%s] \n", res->argument);         
}

