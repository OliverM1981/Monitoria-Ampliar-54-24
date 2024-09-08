#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Estrutura para Tabela de Dispersão (Hash)
typedef struct {
    int chave;
    int valor;
} TabelaHash;

TabelaHash* tabelaHash[TABLE_SIZE];

// Funções para Tabela Hash
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
    return -1; // Valor não encontrado
}

// Função de Busca Sequencial
int buscaSequencial(int* lista, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == valor) {
            return i; // Retorna a posição do valor
        }
    }
    return -1; // Valor não encontrado
}

// Função de Busca Binária
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
    return -1; // Valor não encontrado
}

// Função para criar uma lista
void criarLista(int* lista, int tamanho) {
    printf("Digite os %d elementos da lista:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &lista[i]);
    }
}

// Função para imprimir a lista
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
    int lista[100];
    int tamanho = 0;
    int opcao, valor, resultado;
    
    // Inicializando a tabela de dispersão (hash) vazia
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabelaHash[i] = NULL;
    }

    do {
        imprimirLista(lista, tamanho);
        printf("\nMenu:\n");
        printf("1. Criar Lista\n");
        printf("2. Busca Sequencial\n");
        printf("3. Busca Binária\n");
        printf("4. Inserir em Tabela Hash\n");
        printf("5. Buscar em Tabela Hash\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Quantos elementos deseja adicionar na lista? ");
                scanf("%d", &tamanho);
                criarLista(lista, tamanho);
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
                printf("Digite o valor para busca binária (lista precisa estar ordenada): ");
                scanf("%d", &valor);
                resultado = buscaBinaria(lista, valor, 0, tamanho - 1);
                if (resultado != -1) {
                    printf("Valor encontrado na posição %d.\n", resultado);
                } else {
                    printf("Valor não encontrado.\n");
                }
                break;

            case 4:
                printf("Digite a chave e o valor para inserir na tabela hash: ");
                int chave;
                scanf("%d %d", &chave, &valor);
                inserirHash(chave, valor);
                printf("Valor inserido com sucesso.\n");
                break;

            case 5:
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

    return 0;
}
