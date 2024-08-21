#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Variáveis globais
int destino, origem, vertices = 0;
int custo, *custos = NULL;

// Prototipação
void dijkstra(int vertices, int origem, int destino, const int *custos);
void menu_mostrar(void);
void grafo_procurar(void);
void grafo_criar(void);

// Função principal
int main() {
    int opt = -1;
    // Laço principal do menu
    do {
        // Desenha o menu na tela
        menu_mostrar();
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                // Cria um novo grafo
                grafo_criar();
                break;
            case 2:
                // Procura os caminhos
                if (vertices > 0) {
                    grafo_procurar();
                }
                break;
        }
    } while (opt != 0);
    printf("\nAlgoritmo de Dijkstra finalizado...\n\n");
    free(custos); // Libera memória alocada
    return 0;
}

// Implementação do algoritmo de Dijkstra
void dijkstra(int vertices, int origem, int destino, const int *custos) {
    int i, v, cont = 0;
    int *ant = (int *)calloc(vertices, sizeof(int));
    int *tmp = (int *)calloc(vertices, sizeof(int));
    bool *z = (bool *)calloc(vertices, sizeof(bool));
    double min;
    double dist[vertices];

    if (!ant || !tmp || !z) {
        fprintf(stderr, "Erro: Memória Insuficiente\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < vertices; i++) {
        if (custos[(origem - 1) * vertices + i] != -1) {
            ant[i] = origem - 1;
            dist[i] = custos[(origem - 1) * vertices + i];
        } else {
            ant[i] = -1;
            dist[i] = HUGE_VAL;
        }
        z[i] = false;
    }
    z[origem - 1] = true;
    dist[origem - 1] = 0;

    do {
        min = HUGE_VAL;
        for (i = 0; i < vertices; i++) {
            if (!z[i] && dist[i] >= 0 && dist[i] < min) {
                min = dist[i];
                v = i;
            }
        }

        if (min != HUGE_VAL && v != destino - 1) {
            z[v] = true;
            for (i = 0; i < vertices; i++) {
                if (!z[i] && custos[v * vertices + i] != -1 && dist[v] + custos[v * vertices + i] < dist[i]) {
                    dist[i] = dist[v] + custos[v * vertices + i];
                    ant[i] = v;
                }
            }
        }
    } while (v != destino - 1 && min != HUGE_VAL);

    printf("\tDe %d para %d: \t", origem, destino);
    if (min == HUGE_VAL) {
        printf("Não Existe\n");
        printf("\tCusto: \t- \n");
    } else {
        i = destino;
        i = ant[i - 1];
        while (i != -1) {
            tmp[cont] = i + 1;
            cont++;
            i = ant[i];
        }
        for (i = cont; i > 0; i--) {
            printf("%d -> ", tmp[i - 1]);
        }
        printf("%d", destino);
        printf("\n\tCusto: %d\n", (int)dist[destino - 1]);
    }

    free(ant);
    free(tmp);
    free(z);
}

void grafo_criar(void) {
    do {
        printf("\nInforme o número de vértices (no mínimo 3): ");
        scanf("%d", &vertices);
    } while (vertices < 3);

    if (custos) {
        free(custos);
    }

    custos = (int *)malloc(sizeof(int) * vertices * vertices);
    if (custos == NULL) {
        fprintf(stderr, "Erro: Memória Insuficiente\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < vertices * vertices; i++) {
        custos[i] = -1;
    }

    while (true) {
        printf("Entre com as Arestas:\n");
        do {
            printf("Origem (entre 1 e %d ou '0' para sair): ", vertices);
            scanf("%d", &origem);
        } while (origem < 0 || origem > vertices);

        if (origem == 0) break;

        do {
            printf("Destino (entre 1 e %d, menos %d): ", vertices, origem);
            scanf("%d", &destino);
        } while (destino < 1 || destino > vertices || destino == origem);

        do {
            printf("Custo (positivo) do vértice %d para o vértice %d: ", origem, destino);
            scanf("%d", &custo);
        } while (custo < 0);

        custos[(origem - 1) * vertices + destino - 1] = custo;
    }
}

// Busca os menores caminhos entre os vértices
void grafo_procurar(void) {
    printf("Lista dos Menores Caminhos no Grafo Dado: \n");
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            dijkstra(vertices, i, j, custos);
        }
        printf("\n");
    }
}

// Desenha o menu na tela
void menu_mostrar(void) {
    printf("Implementação do Algoritmo de Dijkstra\n");
    printf("Opções:\n");
    printf("\t1 - Adicionar um Grafo\n");
    printf("\t2 - Procurar os Menores Caminhos no Grafo\n");
    printf("\t0 - Sair do programa\n");
    printf("Digite sua opcao ");
}
