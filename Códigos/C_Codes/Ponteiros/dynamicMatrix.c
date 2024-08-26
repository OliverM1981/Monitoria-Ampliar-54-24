#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3;
    int cols = 3;
    int **matrix;

    // Alocação de memória para as linhas
    matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Alocação de memória para as colunas de cada linha
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Erro na alocação de memória.\n");
            return 1;
        }
    }

    // Inicialização e impressão da matriz
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Liberação da memória alocada
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
