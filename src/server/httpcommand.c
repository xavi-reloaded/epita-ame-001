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
    
  char SP[] = " ";
  
  // CUIDADO CON str que CAMBIA CUANDO VA A PIECE
  char *version = get_piece(str, SP, 3);
  char *argument = get_piece(str, SP, 2);
  char *command = get_piece(str, SP, 1);

  struct httprequest *res = malloc(sizeof(struct httprequest));
  res->command = command;
  res->argument = argument;
  res->version = version;
  return res;
  
}


