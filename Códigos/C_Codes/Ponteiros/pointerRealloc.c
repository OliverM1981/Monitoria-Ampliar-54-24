#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5;

    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Redimensiona o array para 10 elementos
    arr = (int*)realloc(arr, 10 * sizeof(int));
    if (arr == NULL) {
        printf("Erro na realocação de memória.\n");
        return 1;
    }

    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
