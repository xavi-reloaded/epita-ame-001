#define _GNU_SOURCE
#define _PSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "httpcommand.h"
#include "http.h"

#define COMMAND_GET GET
#define COMMAND_HEAD HEAD


struct httprequest *parse(char* str) {
    
  char SP[] = " ";
  char CRLN[] = "\r\n";

  char *tmp = malloc(strlen(str) + 1);
  strncpy(tmp, str, strlen(str));

  char *version = get_piece(tmp, CRLN, 1);
  version = get_piece(version, SP, 3); 
  char *path = get_piece(str, SP, 2);
  char *command = get_piece(str, SP, 1);
  

  struct httprequest *res = malloc(sizeof(struct httprequest));
  res->command = command;
  res->path = path;
  res->version = version;
  return res;
  
}


