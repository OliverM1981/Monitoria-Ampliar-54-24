#include <stdio.h>

int main (){

    int var = 10;
    int *ptr;
    ptr = &var;

    printf("Valor de var: %d\n", *ptr); // Desreferencia o ponteiro para acessar o valor de var
    *ptr = 20; // Modifica o valor de var através do ponteiro
    printf("Novo valor de var: %d\n", var);


}