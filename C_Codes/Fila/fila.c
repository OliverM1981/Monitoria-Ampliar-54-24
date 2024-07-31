#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int itens[MAX];
    int frente;
    int tras;
} Fila;

void inicializarFila(Fila *fila) {
    fila->frente = 0;
    fila->tras = -1;
}

bool filaVazia(Fila fila) {
    return fila.tras < fila.frente;
}

bool filaCheia(Fila fila) {
    return fila.tras == MAX - 1;
}

bool enfileirar(Fila *fila, int valor) {
    if (filaCheia(*fila)) {
        printf("Fila cheia\n");
        return false;
    }
    fila->itens[++fila->tras] = valor;
    return true;
}

bool desenfileirar(Fila *fila, int *valor) {
    if (filaVazia(*fila)) {
        printf("Fila vazia\n");
        return false;
    }
    *valor = fila->itens[fila->frente++];
    return true;
}

void imprimirFila(Fila fila) {
    if (filaVazia(fila)) {
        printf("Fila está vazia\n");
        return;
    }
    printf("Fila: ");
    for (int i = fila.frente; i <= fila.tras; i++) {
        printf("%d ", fila.itens[i]);
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);
    enfileirar(&fila, 40);
    enfileirar(&fila, 50);

    imprimirFila(fila);

    int valor;
    desenfileirar(&fila, &valor);
    printf("Desenfileirado: %d\n", valor);

    imprimirFila(fila);

    return 0;
}
