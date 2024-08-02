#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode; 
    return newNode;
}

void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* tail = (*head)->next;

        newNode->next = *head;
        while (tail->next != *head) {
            tail = tail->next;
        }
        tail->next = newNode;
        *head = newNode;
    }
}

void removeNode(Node** head, int data) {
    if (*head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node* current = *head;
    Node* prev = NULL;

    do {
        if (current->data == data) {
            if (prev == NULL) {
                Node* tail = (*head)->next;
                while (tail->next != *head) {
                    tail = tail->next;
                }
                if (current->next == *head) {
                    *head = (current->next != current) ? current->next : NULL;
                }
                tail->next = *head;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Elemento %d removido.\n", data);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *head);

    printf("Elemento %d não encontrado.\n", data);
}

void printList(Node* head) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Node* head = NULL;
    int choice, data;

    srand(time(NULL));

    while (1) {
        if(head != NULL){
            printf("Lista: ");
            printList(head);
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
                insertAtHead(&head, data);
                printf("Número %d inserido na lista.\n", data);
                break;
            case 2:
                if (head == NULL) {
                    printf("A lista está vazia, não é possível remover elementos.\n");
                    break;
                }
                printf("Digite o número a ser removido: ");
                scanf("%d", &data);
                removeNode(&head, data);
                break;
            case 3:
                if (head != NULL) {
                    Node* current = head;
                    Node* nextNode;
                    do {
                        nextNode = current->next;
                        free(current);
                        current = nextNode;
                    } while (current != head);
                }
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }
}
