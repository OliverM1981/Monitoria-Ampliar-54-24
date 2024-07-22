#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5;

    arr = (int*)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Todos os elementos são inicializados com zero
    }
    printf("\n");

    free(arr);
    return 0;
}
