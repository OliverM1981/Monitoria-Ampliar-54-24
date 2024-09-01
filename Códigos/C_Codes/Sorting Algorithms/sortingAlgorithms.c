#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int bubbleSort(int arr[], int n) {
    int i, j, temp, iterations = 0;
    for (i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca de elementos
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                iterations++;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
    return iterations;
}

int selectionSort(int arr[], int n) {
    int i, j, min_idx, temp, iterations = 0;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            // Troca de elementos
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            iterations++;
        }
    }
    return iterations;
}

int insertionSort(int arr[], int n) {
    int i, key, j, iterations = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            iterations++;
        }
        arr[j + 1] = key;
        if (j + 1 != i) {
            iterations++;
        }
    }
    return iterations;
}

int shellSort(int arr[], int n) {
    int gap, i, j, temp, iterations = 0;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
                iterations++;
            }
            arr[j] = temp;
            if (j != i) {
                iterations++;
            }
        }
    }
    return iterations;
}

void generateRandomNumbers(int *arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Números entre 0 e 99
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int mainMenu() {
    int choice;
    printf("=== MENU PRINCIPAL ===\n");
    printf("1. Gerar Lista\n");
    printf("2. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &choice);
    return choice;
}

int sortingMenu() {
    int choice;
    printf("\n=== MENU DE ORDENAÇÃO ===\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Shell Sort\n");
    printf("5. Voltar ao Menu Principal\n");
    printf("Escolha um método de ordenação: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int mainChoice, sortChoice;
    int *arr = NULL;
    int n = 0;

    while (1) {
        mainChoice = mainMenu();

        if (mainChoice == 1) {
            printf("Digite a quantidade de números aleatórios que deseja na lista: ");
            scanf("%d", &n);

            // Verificação de entrada
            if (n <= 0) {
                printf("Quantidade inválida. Por favor, insira um número positivo.\n");
                continue;
            }

            arr = (int *)malloc(n * sizeof(int));
            if (arr == NULL) {
                printf("Erro na alocação de memória!\n");
                exit(EXIT_FAILURE);
            }

            generateRandomNumbers(arr, n);
            printf("Lista gerada:\n");
            printArray(arr, n);

            while (1) {
                sortChoice = sortingMenu();

                if (sortChoice == 5) {
                    // Voltar ao menu principal
                    break;
                }

                int *arrCopy = (int *)malloc(n * sizeof(int));
                if (arrCopy == NULL) {
                    printf("Erro na alocação de memória!\n");
                    free(arr);
                    exit(EXIT_FAILURE);
                }

                for (int i = 0; i < n; i++) {
                    arrCopy[i] = arr[i];
                }

                int iterations = 0;

                switch (sortChoice) {
                    case 1:
                        iterations = bubbleSort(arrCopy, n);
                        printf("\nLista ordenada com Bubble Sort:\n");
                        break;
                    case 2:
                        iterations = selectionSort(arrCopy, n);
                        printf("\nLista ordenada com Selection Sort:\n");
                        break;
                    case 3:
                        iterations = insertionSort(arrCopy, n);
                        printf("\nLista ordenada com Insertion Sort:\n");
                        break;
                    case 4:
                        iterations = shellSort(arrCopy, n);
                        printf("\nLista ordenada com Shell Sort:\n");
                        break;
                    default:
                        printf("Opção inválida. Tente novamente.\n");
                        free(arrCopy);
                        continue;
                }

                printArray(arrCopy, n);
                printf("Total de iterações realizadas: %d\n", iterations);

                free(arrCopy);
            }

            free(arr);
            arr = NULL;

        } else if (mainChoice == 2) {
            printf("Encerrando o programa. Até mais!\n");
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
