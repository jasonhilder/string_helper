#include "string_helper.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    string_helper *s = create_string_helper("Hello");

    print_string(s);
    string_add(s, " World!", false);
    print_string(s);

    destroy_string_helper(s);

    return 0;
}
