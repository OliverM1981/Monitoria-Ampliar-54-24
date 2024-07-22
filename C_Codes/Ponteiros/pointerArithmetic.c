#include <stdio.h>

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    printf("Primeiro elemento: %d\n", *ptr);
    ptr++; // Avança o ponteiro para o próximo inteiro
    printf("Segundo elemento: %d\n", *ptr);

}

