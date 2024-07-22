#include <stdio.h>

void to_uppercase(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - ('a' - 'A');
        }
        str++;
    }
}

int main() {
    char str[] = "hello, world!";
    to_uppercase(str);
    printf("Uppercase: %s\n", str);
    return 0;
}
