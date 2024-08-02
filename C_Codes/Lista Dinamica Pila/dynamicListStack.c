#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Definição do nó da pilha
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para empurrar um novo nó no topo da pilha
void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Função para remover o nó do topo da pilha
void pop(Node** top) {
    if (*top == NULL) {
        printf("A pilha está vazia, não há elementos para remover.\n");
        return;
    }

    Node* temp = *top;
    *top = (*top)->next;
    free(temp);
    printf("Elemento removido do topo da pilha.\n");
}

// Função para imprimir a pilha
void printStack(Node* top) {
    Node* current = top;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Node* top = NULL;  // Inicializa o topo da pilha
    int choice, data;

    srand(time(NULL));

    while (1) {
        if(top != NULL){
            printf("Pilha Dinâmica: ");
            printStack(top);
            printf("\n1. Inserir na lista\n2. Remover da lista\n3. Sair\nEscolha uma opção: ");
            scanf("%d", &choice);
        } else {
            printf("\n1. Inserir na lista\n3. Sair\nEscolha uma opção: ");
            scanf("%d", &choice);
            if (choice == 2) {
                printf("Opção Inválida\n");
                continue;
            } 
        }

        switch (choice) {
            case 1:
                data = rand() % 100;
                push(&top, data);
                printf("Número %d inserido na pilha.\n", data);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                // Libera a memória alocada para a pilha
                while (top != NULL) {
                    Node* temp = top;
                    top = top->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }
}
