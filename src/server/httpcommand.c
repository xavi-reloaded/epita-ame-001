#define _GNU_SOURCE
#define _PSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "httpcommand.h"

#define COMMAND_GET GET
#define COMMAND_HEAD HEAD

struct httprequest *parse(char *str) {
  static const char *separator = " \t"; 
  char *command = str;
  str += strcspn(str, separator);
  if (*str) {
    *str++ = 0;
  }
  
  char *argument = str;
  printf("Command : %s\n", command);
  printf("Argument: %s \n", argument);
  

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

