#include <stdio.h>
#include <string.h>
#include "stringutils.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char input[256];

    strncpy(input, argv[1], sizeof(input) - 1);
    input[sizeof(input) - 1] = '\0';

    printf("Original string: %s\n", input);
    printf("Length: %d\n", string_length(input));

    to_uppercase(input);
    printf("Uppercase: %s\n", input);

    reverse_string(input);
    printf("Reversed uppercase: %s\n", input);

    return 0;
}