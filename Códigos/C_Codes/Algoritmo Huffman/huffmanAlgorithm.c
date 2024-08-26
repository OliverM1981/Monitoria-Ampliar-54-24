#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100

// Estrutura de um nó da árvore de Huffman
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// Estrutura de um MinHeap
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// Função para criar um novo nó de MinHeap
struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    if (node == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Função para criar uma MinHeap de uma dada capacidade
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    if (minHeap == NULL) {
        perror("Failed to allocate memory for MinHeap");
        exit(EXIT_FAILURE);
    }
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    if (minHeap->array == NULL) {
        perror("Failed to allocate memory for MinHeap array");
        exit(EXIT_FAILURE);
    }
    return minHeap;
}

// Troca dois nós
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Função para garantir a propriedade de MinHeap
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Verifica se o tamanho da MinHeap é um
int isSizeOne(const struct MinHeap* minHeap) {
    return minHeap->size == 1;
}

// Extrai o nó de menor valor da MinHeap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size <= 0) return NULL;
    if (minHeap->size == 1) return minHeap->array[--minHeap->size];

    struct MinHeapNode* root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[--minHeap->size];
    minHeapify(minHeap, 0);

    return root;
}

// Insere um nó na MinHeap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    int i = minHeap->size++;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Constrói uma MinHeap
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

// Verifica se o nó é uma folha
int isLeaf(const struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

// Cria e inicializa uma MinHeap
struct MinHeap* createAndBuildMinHeap(const char data[], const int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = newNode(data[i], freq[i]);
    }

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

// Função principal que cria a árvore de Huffman
struct MinHeapNode* buildHuffmanTree(const char data[], const int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    struct MinHeapNode* root = extractMin(minHeap);

    // Liberação da memória da MinHeap
    free(minHeap->array);
    free(minHeap);

    return root;
}

// Função para imprimir os códigos de Huffman a partir da árvore de Huffman
void printCodes(const struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Função principal para construir e imprimir os códigos de Huffman
void HuffmanCodes(const char data[], const int freq[], int size) {
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;

    printCodes(root, arr, top);

    // Liberação da memória da árvore de Huffman
    free(root);
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
