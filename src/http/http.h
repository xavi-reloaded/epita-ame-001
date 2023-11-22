#ifndef HTTP_H
#define HTTP_H

char *get_piece(char *str, char *separator, size_t position);

char *get_first_line_from_http_message(char *http_message);

void Trim(char* destination, char* source, int size);
void ParseUpToSymbol(char* destination, char* source, int size, char delimiter);

#endif /* !HTTP_H */