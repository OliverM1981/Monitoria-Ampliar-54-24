#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10
int i, j;
int size = 0;
int graph[MAX];
int adjacencyMatrix[MAX][MAX];
int option = 1;

int graphSize();
void drawGraph();
void drawAdjacencyMatrix();
void insertEdge();
void removeEdge();
void showMenu();

int main() {
	setlocale(LC_ALL, "Portuguese");

    while (size <= 0 || size > MAX) {
        size = graphSize();
        if (size <= 0 || size > MAX) {
            system("cls");
            printf("Escolha um valor entre 1 e %d!\n\n", MAX);
        } else {
            for (i = 0; i < size; i++) {
                graph[i] = i;
            }
        }
    }
    while (option != 0) {
        system("cls");
        drawGraph();
        drawAdjacencyMatrix();
        showMenu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                insertEdge();
                break;
            case 2:
                removeEdge();
                break;
            default: ;
        }
    }
    system("Pause");
    return 0;
}

int graphSize() {
    int size;
    printf("Escolha a quantidade de vértices do grafo: ");
    scanf("%d", &size);
    fflush(stdin);
    return size;
}

void drawGraph() {
    printf("Listas de vértices\n[ ");
    for ( i = 0; i < size; i++) {
        printf("%d ", graph[i]);
    }
    printf("]");
}

void drawAdjacencyMatrix() {

    printf("\n\n  ");
    for (i = 0; i< size ; i++) {
    	
		printf(" %d", i);	
    	
	}
    i = 0;
	printf("\n");
    for ( i = 0; i < size; i++) {
    	printf("%d|", i);
        for ( j = 0; j < size; j++) {
            if( i == j)
            {
                printf("  ");
            }else
            {
                printf(" %d", adjacencyMatrix[i][j]);
            }

        }
        printf("|\n");
    }
    printf("\n\n");
}

void insertEdge() {
    int vertex1, vertex2;
    system("cls");
    printf("Escolha o vértice de origem entre 0 a %d: ", size - 1);
    scanf("%d", &vertex1);
    fflush(stdin);
    printf("Escolha o vértice de destino entre 0 a %d: ", size - 1);
    scanf("%d", &vertex2);
    fflush(stdin);
    if( vertex1 == vertex2)
    {
        printf("\nImpossivel criar aresta (conexão) pois a origem e o destino coincidem!\n\n");
        return;
    }

    if (vertex1 > size - 1 || vertex2 > size - 1 || vertex1 < 0 || vertex2 < 0) {
        printf("\nOs valores precisam estar entre 0 e %d\n\n", size - 1);
        system("pause");
    } else {
        adjacencyMatrix[vertex1][vertex2] = 1;
       
    }
}

// Remover aresta
void removeEdge() {
    int vertex1, vertex2;
    system("cls");
    printf("Escolha o vértice de origem entre 0 a %d: ", size - 1);
    scanf("%d", &vertex1);
    fflush(stdin);
    printf("Escolha o vértice de destino entre 0 a %d: ", size - 1);
    scanf("%d", &vertex2);
    fflush(stdin);
    if( vertex1 == vertex2)
    {
        printf("\nImpossivel remover aresta (conexão) pois a origem e o destino coincidem!\n\n");
        return;
    }

    if (vertex1 > size - 1 || vertex2 > size - 1 || vertex1 < 0 || vertex2 < 0) {
        printf("\nOs valores precisam estar entre 0 e %d\n\n", size - 1);
        system("pause");
    } else {
        adjacencyMatrix[vertex1][vertex2] = 0;
        
    }
}


void showMenu() {
    printf("\n***Matriz de Adjacências***\n");
    printf("1 - Inserir aresta\n");
    printf("2 - Remover aresta\n");
    printf("0 - Sair\n");
    printf("Escolha uma op��o: ");
}