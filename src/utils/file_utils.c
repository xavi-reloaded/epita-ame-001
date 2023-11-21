#include <stdio.h>

static int file_exist(char *path)
{
    FILE *file = fopen(path, "r");
    if (file != NULL)
    {
        printf("File %s exists\n", path);
        fclose(file);
        return 1;
    }
    printf("File  %s does not exist\n", path);
    return 0;
}

int main(void)
{
    file_exist("string/string.c");
    file_exist("string/string.wee");
    return 0;
}