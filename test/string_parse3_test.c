#include <criterion/criterion.h>
#include "../src/http/http.h"


Test(get_piece, trim) 
{
    char* buffer = (char*)malloc(64);
    char* temp = (char*)malloc(256);
    strcpy(temp, "GET /path/script.cgi?field1=value1&field2=value2 HTTP/1.1");
    Trim(temp, temp, 256);
    ParseUpToSymbol(buffer, cstr, 64, '?');
    temp = temp + strlen(buffer) + 1;
    Trim(temp, temp, 256);

    cr_assert(strcmp(actual, expected) == 0, "Actual: %s, Expected: %s", temp, temp);
}



