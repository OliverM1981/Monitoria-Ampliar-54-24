#include <stdio.h>

void greet() {
    printf("Hello!\n");
}

void farewell() {
    printf("Goodbye!\n");
}

int main() {
    void (*func_ptr)();
    func_ptr = greet;
    func_ptr();

    func_ptr = farewell;
    func_ptr();

    return 0;
}
