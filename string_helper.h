#ifndef STRING_HELPER_H
#define STRING_HELPER_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    int allocated_size;
    char *value;
} string_helper;

string_helper *create_string_helper(const char *str);
void destroy_string_helper(string_helper *s);
void print_string(string_helper *s);
void string_add(string_helper *s, const char *new_str, bool prepend);
void string_replace(string_helper *s, const char *sub_string, const char *replace_string);
void string_replace_all(string_helper *s, const char *sub_string, const char *replace_string);

#endif /* STRING_HELPER_H */