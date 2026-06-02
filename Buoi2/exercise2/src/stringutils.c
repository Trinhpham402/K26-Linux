#include "stringutils.h"

void to_uppercase(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i++;
    }
}

int string_length(const char *str) {
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }

    return count;
}

void reverse_string(char *str) {
    int left = 0;
    int right = string_length(str) - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}