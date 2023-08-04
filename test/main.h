#ifndef head_h
#define head_h
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct list_s
{
    char *str;
    struct list_s *next;
    // struct list_s *prev;
} list_t;

void write_json_to_file(list_t *data, unsigned int is_single);
#endif