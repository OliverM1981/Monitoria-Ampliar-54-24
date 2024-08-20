#include <stdio.h>

int main() {
    // Grafo com 4 vértices e 3 arestas
    // Aresta 0: entre 0 e 1
    // Aresta 1: entre 1 e 2
    // Aresta 2: entre 2 e 3

    int matriz_incidencia[4][3] = {
        {1, 0, 0},  // Vértice 0 conectado à Aresta 0
        {1, 1, 0},  // Vértice 1 conectado às Arestas 0 e 1
        {0, 1, 1},  // Vértice 2 conectado às Arestas 1 e 2
        {0, 0, 1}   // Vértice 3 conectado à Aresta 2
    };

    // Print da Matriz de Incidência
    printf("\nMatriz de Incidência:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz_incidencia[i][j]);
        }
        printf("\n");
    }

    return 0;
}
