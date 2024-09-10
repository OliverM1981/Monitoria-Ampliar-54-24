#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TABLE_SIZE 10
#define INDEX_SIZE 5

typedef struct {
    int chave;
    int valor;
} TabelaHash;

TabelaHash* tabelaHash[TABLE_SIZE];

typedef struct {
    int* lista;
    int tamanho;
} Indexador;


int funcaoHash(int chave) {
    return chave % TABLE_SIZE;
}

void inserirHash(int chave, int valor) {
    int index = funcaoHash(chave);
    while (tabelaHash[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
    }
    tabelaHash[index] = (TabelaHash*) malloc(sizeof(TabelaHash));
    tabelaHash[index]->chave = chave;
    tabelaHash[index]->valor = valor;
}

int buscarHash(int chave) {
    int index = funcaoHash(chave);
    while (tabelaHash[index] != NULL) {
        if (tabelaHash[index]->chave == chave) {
            return tabelaHash[index]->valor;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1;
}


int buscaSequencial(int* lista, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == valor) {
            return i;
        }
    }
    return -1;
}

// Função de Busca Sequencial Indexada
int buscaSequencialIndexada(Indexador* indexador, int valor) {
    int* lista = indexador->lista;
    int tamanho = indexador->tamanho;

    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == valor) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int* lista, int valor, int inicio, int fim) {
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (lista[meio] == valor) {
            return meio;
        } else if (lista[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

void quicksort(int* lista, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = lista[fim];
        int i = inicio - 1;
        for (int j = inicio; j < fim; j++) {
            if (lista[j] <= pivo) {
                i++;
                int temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
        int temp = lista[i + 1];
        lista[i + 1] = lista[fim];
        lista[fim] = temp;
        int pivoIndex = i + 1;
        quicksort(lista, inicio, pivoIndex - 1);
        quicksort(lista, pivoIndex + 1, fim);
    }
}

void criarLista(int* lista, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        lista[i] = rand() % 100 + 1;
    }
}

void imprimirLista(int* lista, int tamanho) {
    if (tamanho == 0) {
        printf("Lista vazia\n");
        return;
    }
    printf("Lista: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Portuguese");
    int lista[100];
    int listaAux[100];
    int tamanho = 0;
    int opcao, valor, resultado;

    for (int i = 0; i < TABLE_SIZE; i++) {
        tabelaHash[i] = NULL;
    }

    Indexador indexador;
    indexador.lista = NULL;
    indexador.tamanho = 0;

    do {
        imprimirLista(lista, tamanho);
        printf("\nMenu:\n");
        printf("1. Criar Lista\n");
        printf("2. Busca Sequencial\n");
        printf("3. Busca Sequencial Indexada\n");
        printf("4. Busca Binária\n");
        printf("5. Inserir em Tabela Hash\n");
        printf("6. Buscar em Tabela Hash\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Quantos elementos deseja adicionar na lista?: ");
                scanf("%d", &tamanho);
                criarLista(lista, tamanho);

                if (indexador.lista != NULL) {
                    free(indexador.lista);
                }
                indexador.lista = (int*) malloc(tamanho * sizeof(int));
                for (int i = 0; i < tamanho; i++) {
                    indexador.lista[i] = lista[i];
                }
                indexador.tamanho = tamanho;
                break;

            case 2:
                printf("Digite o valor para busca sequencial: ");
                scanf("%d", &valor);
                resultado = buscaSequencial(lista, tamanho, valor);
                if (resultado != -1) {
                    printf("Valor encontrado na posição %d.\n", resultado);
                } else {
                    printf("Valor não encontrado.\n");
                }
                break;

            case 3:
                printf("Digite o valor para busca sequencial indexada: ");
                scanf("%d", &valor);
                resultado = buscaSequencialIndexada(&indexador, valor);
                if (resultado != -1) {
                    printf("Valor encontrado na posição %d.\n", resultado);
                } else {
                    printf("Valor não encontrado.\n");
                }
                break;

            case 4:
                printf("Digite o valor para busca binária: ");
                scanf("%d", &valor);

                // Criar uma cópia da lista e ordenar
                for (int i = 0; i < tamanho; i++) {
                    listaAux[i] = lista[i];
                }
                quicksort(listaAux, 0, tamanho - 1);

                // Exibir lista ordenada
                printf("Lista ordenada: ");
                imprimirLista(listaAux, tamanho);

                resultado = buscaBinaria(listaAux, valor, 0, tamanho - 1);
                if (resultado != -1) {
                    printf("Valor encontrado na posição %d da lista ordenada.\n", resultado);
                } else {
                    printf("Valor não encontrado.\n");
                }
                break;

            case 5:
                printf("Digite a chave e o valor para inserir na tabela hash: ");
                int chave;
                scanf("%d %d", &chave, &valor);
                inserirHash(chave, valor);
                printf("Valor inserido com sucesso.\n");
                break;

            case 6:
                printf("Digite a chave para buscar na tabela hash: ");
                scanf("%d", &chave);
                resultado = buscarHash(chave);
                if (resultado != -1) {
                    printf("Valor encontrado: %d\n", resultado);
                } else {
                    printf("Chave não encontrada.\n");
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    // Liberação da memória alocada
    free(indexador.lista);
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (tabelaHash[i] != NULL) {
            free(tabelaHash[i]);
        }
    }

    return 0;
}