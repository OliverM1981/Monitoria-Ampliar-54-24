#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 100 // Máximo número de vértices

// Estrutura para representar um nó
struct str_no {
    int id;
    struct str_no *proximo;
};

// Função para adicionar uma aresta ao grafo
void adicionarAresta(struct str_no g[], int origem, int destino) {
    struct str_no *novo_no = (struct str_no*) malloc(sizeof(struct str_no));
    if (!novo_no) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    novo_no->id = destino;
    novo_no->proximo = g[origem].proximo;
    g[origem].proximo = novo_no;
}

// Função para liberar a memória do grafo
void liberarGrafo(struct str_no g[], int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        struct str_no *atual = g[i].proximo;
        while (atual) {
            struct str_no *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
}

// Função de busca em largura
void buscaEmLargura(struct str_no g[], int inicio, int alvo) {
    int fila[MAXV]; // fila
    bool visitado[MAXV]; // nós visitados
    int frente = 0, tras = 0; // controle da fila
    int corrente;
    struct str_no *ptr;

    printf("=-=-=-= Busca em Largura =-=-=-=\n");

    // Marcando os nós como ‘não visitados’.
    for (int i = 0; i < MAXV; i++) {
        visitado[i] = false;
    }

    // Partindo do primeiro vértice.
    printf("VISITANDO: %d.\n", inicio);
    visitado[inicio] = true;
    fila[tras++] = inicio;

    while (frente != tras) {
        corrente = fila[frente++];

        // Visitar os nós adjacentes ao vértice corrente
        for (ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo) {
            if (!visitado[ptr->id]) {
                printf("VISITANDO: %d.\n", ptr->id);
                if (ptr->id == alvo) {
                    printf("Alvo encontrado!\n");
                    return;
                }
                visitado[ptr->id] = true;
                fila[tras++] = ptr->id;
            }
        }
    }

    printf("Encerrando busca.\n");
}

// Função para solicitar o número de vértices e arestas
void solicitarVerticesEArestas(int *num_vertices, int *num_arestas) {
    printf("Digite o número de vértices: ");
    scanf("%d", num_vertices);
    printf("Digite o número de arestas: ");
    scanf("%d", num_arestas);
}

// Função para ler as arestas
void lerArestas(struct str_no grafo[], int num_arestas) {
    int origem, destino;
    for (int i = 0; i < num_arestas; i++) {
        printf("Digite a origem da aresta %d: ", i + 1);
        scanf("%d" , &origem);
        printf("Digite o destino da aresta %d: ", i + 1);
        scanf("%d" , &destino);
        adicionarAresta(grafo, origem, destino);
    }
}

int main() {
    struct str_no grafo[MAXV];
    int num_vertices, num_arestas, inicio, alvo;

    solicitarVerticesEArestas(&num_vertices, &num_arestas);

    // Inicializando o grafo
    for (int i = 0; i < num_vertices; i++) {
        grafo[i].id = i;
        grafo[i].proximo = NULL;
    }

    lerArestas(grafo, num_arestas);

    printf("Digite o vértice de início da busca: ");
    scanf("%d", &inicio);
    printf("Digite o vértice alvo da busca: ");
    scanf("%d", &alvo);

    // Realizando a busca em largura
    buscaEmLargura(grafo, inicio, alvo);

    // Liberando a memória alocada para o grafo
    liberarGrafo(grafo, num_vertices);

    return 0;
}
