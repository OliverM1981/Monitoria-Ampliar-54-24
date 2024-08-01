#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void removeNode(Node** head, int data) {
    Node* temp = *head;

    if (temp == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Elemento %d não encontrado.\n", data);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}


void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
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
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }
}
