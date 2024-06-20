#include "string_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

string_helper *create_string_helper(const char *str) {
    string_helper *s = (string_helper *) malloc(sizeof(string_helper));
    if (s == NULL) {
        // Handle allocation failure
        return NULL;
    }

    int alloc_size = strlen(str) + 1;
    s->allocated_size = alloc_size;
    s->value = (char *) calloc(alloc_size, sizeof(char));
    if (s->value == NULL) {
        // Free struct if allocation fails
        free(s); 
        return NULL;
    }

    strcpy(s->value, str);

    return s;
};

void destroy_string_helper(string_helper *s) {
    if (s == NULL) {
    // Check for NULL pointer
        return; 
    }

    if (s->value != NULL) { 
        // Free the dynamically allocated string
        free(s->value);
        // Set to NULL to avoid dangling pointer
        s->value = NULL; 
    }

    // Free the struct itself
    free(s);
}

void print_string(string_helper *s) {
    printf("%s\n", s->value);
};

// The third boolean parameter declares the position ie. is it prepend or append.
void string_add(string_helper *s, const char *new_str, bool prepend) {
    char *res;

    s->allocated_size += strlen(new_str);

    if(prepend) {

        res = calloc(s->allocated_size, sizeof(char));

        if(!res) {
            fprintf(stderr, "realloc() failed: insufficient memory!\n");
        }

        sprintf(res, "%s%s", new_str, s->value);

        //strcpy(res, new_str); strcat(res, s->value);
        s->value = res;

    } else {
        res = realloc(s->value, s->allocated_size);
        if(!res) {
            fprintf(stderr, "realloc() failed: insufficient memory!\n");
        }

        strcat(res, new_str);
        s->value = res;
    }
};

void string_replace(string_helper *s, const char *sub_string, const char *replace_string) {

    if(strcmp(sub_string, replace_string) == 0) return;

    char *p = strstr(s->value, sub_string);

    if(p != NULL) {
        size_t len1 = strlen(sub_string);
        size_t len2 = strlen(replace_string);

        if(len1 != len2) {
            int new_alloc_size = s->allocated_size - len1 + len2;

            if(new_alloc_size > s->allocated_size) {
                char *new_value = (char *)malloc(new_alloc_size + 1);
                if(new_value == NULL) {
                   fprintf(stderr, "Memory allocation failed\n");
                   return;
                }

                // Copy the part of the string before the replacement
                size_t prefix_len = p - s->value;
                strncpy(new_value, s->value, prefix_len);
                new_value[p - s->value] = '\0';

                // Append the replacement string
                strcat(new_value, replace_string);

                // Append the part of the string after the replacement
                strcat(new_value, p + len1);

                free(s->value);

                s->value = new_value;
                s->allocated_size = new_alloc_size;
            } else {
                // If new_alloc_size is not larger, adjust in place
                memmove(p + len2, p + len1, strlen(p + len1) + 1);
                memcpy(p, replace_string, len2);

                char *tmp = (char *)realloc(s->value, new_alloc_size + 1);
                if(tmp == NULL) {
                    fprintf(stderr, "Memory reallocation failed\n");
                    return;
                }

                s->value = tmp;
                s->allocated_size = new_alloc_size;
            }
        } else {
            // If len1 == len2, just replace in place
            memcpy(p, replace_string, len2);
        }
    }

    return;
}

void string_replace_all(string_helper *s, const char *sub_string, const char *replace_string) {

    while(true) {
        char *p = strstr(s->value, sub_string);

        if(p != NULL) {
            string_replace(s, sub_string, replace_string);
        } else {
            break;
        }
    }

    return;
}
