#include <stdio.h>

int main() {
    const char *fruits[] = {"Apple", "Banana", "Cherry"};

    for (int i = 0; i < 3; i++) {
        printf("%s\n", fruits[i]);
    }

    return 0;
}
