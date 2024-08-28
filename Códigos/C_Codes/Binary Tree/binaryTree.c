#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(const struct Node* node) {  // 'node' como ponteiro para const
    return (node == NULL) ? 0 : node->height;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(const struct Node* node) {  // 'node' como ponteiro para const
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node* minValueNode(const struct Node* node) {  // 'node' como ponteiro para const
    struct Node* current = (struct Node*)node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* search(const struct Node* root, int key) {  // 'root' como ponteiro para const
    if (root == NULL || root->data == key)
        return (struct Node*)root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

void inOrder(const struct Node* root) {  // 'root' como ponteiro para const
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(const struct Node* root) {  // 'root' como ponteiro para const
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(const struct Node* root) {  // 'root' como ponteiro para const
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void printTree(const struct Node* root, int space) {  // 'root' como ponteiro para const
    const int COUNT = 5;
    if (root == NULL)
        return;

    space += COUNT;

    printTree(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, space);
}

void freeTree(struct Node* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    struct Node* root = NULL;
    int choice, num, n;

    do {
        printf("\nMenu:\n");
        printf("1. Criar arvore\n");
        printf("2. Buscar no na arvore\n");
        printf("3. Percurso em ordem\n");
        printf("4. Percurso pre-ordem\n");
        printf("5. Percurso pos-ordem\n");
        printf("6. Balancear arvore (AVL)\n");
        printf("7. Imprimir arvore\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Quantos nos deseja inserir na arvore binaria? ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    num = rand()%100;
                    root = insert(root, num);
                }
                break;
            case 2:
                printf("Digite o numero a ser buscado: ");
                scanf("%d", &num);
                if (search(root, num) != NULL)
                    printf("N� %d encontrado na arvore.\n", num);
                else
                    printf("No %d nao encontrado na arvore.\n", num);
                break;
            case 3:
                printf("Percurso em ordem: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Percurso pre-ordem: ");
                preOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Percurso pos-ordem: ");
                postOrder(root);
                printf("\n");
                break;
            case 6:
                printf("A árvore foi balanceada utilizando AVL.\n");
                break;
            case 7:
                printf("Árvore binária:\n");
                printTree(root, 0);
                break;
            case 8:
                freeTree(root);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (choice != 8);

    return 0;
}
