#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Definição do nó da fila
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

// Função para enfileirar (inserir no final)
void enqueue(Node** front, Node** rear, int data) {
    Node* newNode = createNode(data);
    if (*rear == NULL) {
        // Se a fila está vazia
        *front = *rear = newNode;
    } else {
        // Adiciona no final da fila
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Função para desenfileirar (remover do início)
void dequeue(Node** front, Node** rear) {
    if (*front == NULL) {
        printf("A fila está vazia, não há elementos para remover.\n");
        return;
    }

    Node* temp = *front;
    *front = (*front)->next;

    if (*front == NULL) {
        // Se a fila ficou vazia, o rear também deve ser NULL
        *rear = NULL;
    }

    free(temp);
    printf("Elemento removido do início da fila.\n");
}

// Função para imprimir a fila
void printQueue(Node* front) {
    Node* current = front;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Node* front = NULL; // Início da fila
    Node* rear = NULL;  // Final da fila
    int choice, data;

    srand(time(NULL));

    while (1) {
        if(front != NULL){
            printf("FilaDinâmica: ");
            printQueue(front);
            printf("\n1. Inserir na fila\n2. Remover da fila\n3. Sair\nEscolha uma opção: ");
            scanf("%d", &choice);
        } else {
            printf("\n1. Inserir na Fila\n3. Sair\nEscolha uma opção: ");
            scanf("%d", &choice);
            if (choice == 2) {
                printf("Opção Inválida\n");
                continue;
            } 
        }

        switch (choice) {
            case 1:
                data = rand() % 100;
                enqueue(&front, &rear, data);
                printf("Número %d enfileirado.\n", data);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                // Libera a memória alocada para a fila
                while (front != NULL) {
                    Node* temp = front;
                    front = front->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }
}
