#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

bool pilhaVazia(Pilha pilha) {
    return pilha.topo == -1;
}

bool pilhaCheia(Pilha pilha) {
    return pilha.topo == MAX - 1;
}

bool empilhar(Pilha *pilha, int valor) {
    if (pilhaCheia(*pilha)) {
        printf("Pilha cheia\n");
        return false;
    }
    pilha->itens[++pilha->topo] = valor;
    return true;
}

bool desempilhar(Pilha *pilha, int *valor) {
    if (pilhaVazia(*pilha)) {
        printf("Pilha vazia\n");
        return false;
    }
    *valor = pilha->itens[pilha->topo--];
    return true;
}

void imprimirPilha(Pilha pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha está vazia\n");
        return;
    }
    printf("Pilha: ");
    for (int i = pilha.topo; i >= 0; i--) {
        printf("%d ", pilha.itens[i]);
    }
    printf("\n");
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);
    empilhar(&pilha, 40);
    empilhar(&pilha, 50);

    imprimirPilha(pilha);

    int valor;
    desempilhar(&pilha, &valor);
    printf("Desempilhado: %d\n", valor);

    imprimirPilha(pilha);

    return 0;
}
