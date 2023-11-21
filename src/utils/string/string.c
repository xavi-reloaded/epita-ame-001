#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string *string_create(const char *str, size_t size)
{
    struct string *res = malloc(sizeof(struct string));
    if (res == NULL)
        return NULL;
    res->size = size;
    if (size == 0)
    {
        res->data = NULL;
        return res;
    }
    char *s = malloc(size * sizeof(char));
    if (s == NULL)
    {
        free(res);
        return NULL;
    }
    for (size_t i = 0; i < size; i++)
    {
        s[i] = str[i];
    }
    res->data = s;
    return res;
}

static int my_memcmp(const char *s1, const char *s2, size_t num)
{
    if (num == 0)
        return 0;
    size_t i = 0;
    int res = 0;
    while (i < num)
    {
        if (s1[i] > s2[i])
        {
            res = 1;
            break;
        }
        if (s2[i] > s1[i])
        {
            res = -1;
            break;
        }
        i++;
    }
    return res;
}

int string_compare_n_str(const struct string *str1, const char *str2, size_t n)
{
    return my_memcmp(str1->data, str2, n);
}

void string_concat_str(struct string *str, const char *to_concat, size_t size)
{
    size_t new_s = size + str->size;
    str->data = realloc(str->data, new_s);
    if (str->data == NULL)
        return;
    size_t s = str->size;
    for (size_t i = 0; i < size; i++)
    {
        (str->data)[s + i] = to_concat[i];
    }
    str->size = new_s;
}

void string_destroy(struct string *str)
{
    free(str->data);
    free(str);
}
