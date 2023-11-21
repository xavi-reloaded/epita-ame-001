#ifndef HTTP_H
#define HTTP_H

char *get_piece(char *str, char *separator, size_t position);

char *get_first_line_from_http_message(char *http_message);

#endif /* !HTTP_H */