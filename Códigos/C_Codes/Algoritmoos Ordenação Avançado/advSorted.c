#include <stdio.h>
#include <stdlib.h>

// Funções de ordenação
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

// Funções de apoio
void imprimirLista(int arr[], int n);
void criarLista(int **arr, int *n);
void menu(int *arr, int n);

int main() {
    int *arr = NULL;
    int n = 0;

    while (1) {
        imprimirLista(arr, n);
        menu(arr, n);
    }

    free(arr);  // Liberar memória alocada
    return 0;
}

// Função para imprimir a lista
void imprimirLista(int arr[], int n) {
    if (n == 0) {
        printf("Lista vazia\n");
    } else {
        printf("Lista atual: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

// Função para criar uma lista
void criarLista(int **arr, int *n) {
    printf("Quantos elementos deseja adicionar na lista? ");
    scanf("%d", n);
    
    *arr = (int *)malloc((*n) * sizeof(int));
    
    if (*arr == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    
    for (int i = 0; i < *n; i++) {

        ((*arr)[i]) = rand() % 100+1;
        
    }
}

// Função do menu
void menu(int *arr, int n) {
    int opcao;
    
    printf("\nMenu:\n");
    printf("1. Criar lista\n");
    printf("2. Ordenar por Merge Sort\n");
    printf("3. Ordenar por Quick Sort\n");
    printf("4. Ordenar por Heap Sort\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            criarLista(&arr, &n);
            break;
        case 2:
            if (n > 0) {
                mergeSort(arr, 0, n - 1);
                printf("Lista ordenada por Merge Sort.\n");
            } else {
                printf("Lista vazia. Crie a lista primeiro.\n");
            }
            break;
        case 3:
            if (n > 0) {
                quickSort(arr, 0, n - 1);
                printf("Lista ordenada por Quick Sort.\n");
            } else {
                printf("Lista vazia. Crie a lista primeiro.\n");
            }
            break;
        case 4:
            if (n > 0) {
                heapSort(arr, n);
                printf("Lista ordenada por Heap Sort.\n");
            } else {
                printf("Lista vazia. Crie a lista primeiro.\n");
            }
            break;
        case 0:
            free(arr);
            exit(0);
        default:
            printf("Opção inválida! Tente novamente.\n");
    }
}

// Implementação Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Implementação Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Implementação Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
