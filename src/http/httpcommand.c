#define _GNU_SOURCE
#define _PSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../config/config.h"
#include "http.h"

#define COMMAND_GET GET
#define COMMAND_HEAD HEAD



struct http_request *parse(char* str) 
{
    
  char SP[] = " ";

  char *line = get_first_line_from_http_message(str);
  struct header *headers = get_headers_http_message(str);
  
  char *version = get_piece(line, SP, 3);
  char *path = get_piece(str, SP, 2);
  char *command = get_piece(str, SP, 1);
  
  

  struct http_request *res = malloc(sizeof(struct http_request));
  res->command = command;
  res->path = path;
  res->version = version;
  res->headers = headers;
  return res;
}


