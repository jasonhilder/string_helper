#include "string_helper.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    string_helper *sh = create_string_helper("Hello");

    print_string(sh);
    printf("String len: %d\n", (int)strlen(sh->value));
    printf("Allocation len: %d\n", sh->allocated_size);
    // ===============================================

    string_add(sh, " World!", false);
    print_string(sh);
    printf("String len: %d\n", (int)strlen(sh->value));
    printf("Allocation len: %d\n", sh->allocated_size);
    // ===============================================

    string_add(sh, "The ", true);
    print_string(sh);
    printf("String len: %d\n", (int)strlen(sh->value));
    printf("Allocation len: %d\n", sh->allocated_size);
    // ===============================================

    string_replace(sh, "The ", "");
    print_string(sh);
    printf("String len: %d\n", (int)strlen(sh->value));
    printf("Allocation len: %d\n", sh->allocated_size);
    // ===============================================

    destroy_string_helper(sh);
    return 0;
}
