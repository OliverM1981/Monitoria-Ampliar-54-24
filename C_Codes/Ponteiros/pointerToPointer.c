#include <stdio.h>

int main() {

    int a = 10;int var = 10;
    int *ptr;
    int **ptr_to_ptr;

    ptr = &var;
    ptr_to_ptr = &ptr;

    printf("Valor de var: %d\n", **ptr_to_ptr); // Acessa o valor de var através de dois níveis de indireção

}

