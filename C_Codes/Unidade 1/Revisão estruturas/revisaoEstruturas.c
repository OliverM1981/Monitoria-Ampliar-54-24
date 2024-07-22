#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define ACELERATION_G 9.81

// Definição do enum cores
enum cores {
    RED = 0,
    GREEN = 1,
    BLUE = 2
};

// Função para verificar se a aceleração é alta
bool is_high_acceleration(double acceleration) {
    // Define uma aceleração alta se for maior que a constante ACELERATION_G
    return acceleration > ACELERATION_G;
}

// Função para retornar a cor associada com base na aceleração
enum cores get_color_based_on_acceleration(double acceleration) {
    if (acceleration < ACELERATION_G) {
        return GREEN; // Aceleração baixa é associada à cor GREEN
    } else if (acceleration == ACELERATION_G) {
        return BLUE; // Aceleração igual à constante é associada à cor BLUE
    } else {
        return RED; // Aceleração alta é associada à cor RED
    }
}

// Declaração da variável do tipo enum cores
enum cores colours;

// Declaração da variável do tipo union
union {
    int numero;
    float decimal;
    char letra;
} u;

// Definição da struct pessoa
struct pessoa {
    int idade;
    char nome[30];
    float estatura;
};

// Declaração da variável do tipo struct pessoa
struct pessoa Pessoa;

// Definição de um typedef para Livro
typedef struct {
    char titulo[100];
    char autor[50];
    int ano_publicacao;
    float preco;
} Livro;

// Declaração de uma variável do tipo Livro
Livro Livro1;

// Declaração de variáveis de tipos diversos
unsigned short int serie;
unsigned long int max32 = 4294967295UL;
const float PI_F = 3.1415927f;
const double PI = 3.141592653589793;
double PI_DOUBLE = M_PI;
char projeto[] = {"Ampliar Tecnologias"};

int main(void) {
    //Definindo configurações de regionalidade
    setlocale(LC_ALL,"Portuguese");
    // Gerar números aleatórios
    // Inicializando o gerador de números aleatórios com uma semente apropriada
    srand((unsigned int)time(NULL));

    // Inicialização da variável do tipo enum cores
    colours = RED;
    // Exibindo o valor da variável colours
    printf("Cor selecionada: %d\n", colours); // RED tem valor 0

    // Inicialização da variável do tipo union
    u.numero = 42; // Atribuindo um valor ao membro 'numero' da union
    printf("Valor da union (numero): %d\n", u.numero);

    // Modificando o valor da union
    u.decimal = 3.14f; // Atribuindo um valor ao membro 'decimal' da union
    printf("Valor da union (decimal): %.2f\n", u.decimal);

    // Modificando o valor da union novamente
    u.letra = 'A'; // Atribuindo um valor ao membro 'letra' da union
    printf("Valor da union (letra): %c\n", u.letra);

    // Inicialização da variável do tipo struct pessoa
    Pessoa.idade = 25;
    strcpy(Pessoa.nome, "João Silva"); // Atribuindo um valor ao membro 'nome'
    Pessoa.estatura = 1.75f;
    // Exibindo os valores da struct pessoa
    printf("Pessoa:\n");
    printf("Idade: %d\n", Pessoa.idade);
    printf("Nome: %s\n", Pessoa.nome);
    printf("Estatura: %.2f\n", Pessoa.estatura);

    // Inicialização da variável do tipo Livro
    strcpy(Livro1.titulo, "O Guia do Mochileiro das Galáxias");
    strcpy(Livro1.autor, "Douglas Adams");
    Livro1.ano_publicacao = 1979;
    Livro1.preco = 29.90f;
    // Exibindo os valores do Livro
    printf("Livro:\n");
    printf("Título: %s\n", Livro1.titulo);
    printf("Autor: %s\n", Livro1.autor);
    printf("Ano de publicação: %d\n", Livro1.ano_publicacao);
    printf("Preço: %.2f\n", Livro1.preco);

    // Trabalhando com variáveis de tipos diversos
    serie = 12345;
    printf("Número da série: %hu\n", serie);
    printf("Valor máximo de 32 bits: %lu\n", max32);
    printf("Valor de PI_F: %.7f\n", PI_F);
    printf("Valor de PI: %.15f\n", PI);
    printf("Valor de PI_DOUBLE: %.15f\n", PI_DOUBLE);
    printf("Projeto: %s\n", projeto);

    // Trabalhando com a aceleração e cor
    double acceleration = 12.5; // Exemplo de valor de aceleração

    // Verificar se a aceleração é alta
    if (is_high_acceleration(acceleration)) {
        printf("A aceleração de %.2f é alta.\n", acceleration);
    } else {
        printf("A aceleração de %.2f não é alta.\n", acceleration);
    }

    // Obter a cor baseada na aceleração
    enum cores color = get_color_based_on_acceleration(acceleration);

    // Exibir a cor associada usando números diretamente
    switch (color) {
        case 0: // RED
            printf("A cor associada à aceleração é RED.\n");
            break;
        case 1: // GREEN
            printf("A cor associada à aceleração é GREEN.\n");
            break;
        case 2: // BLUE
            printf("A cor associada à aceleração é BLUE.\n");
            break;
        default:
            printf("Cor desconhecida.\n");
            break;
    }

    // Gerar e exibir 5 números aleatórios entre 0 e 99
    printf("Números aleatórios:\n");
    for (int i = 0; i < 5; ++i) {
        int random_number = rand() % 100; // Número aleatório entre 0 e 99
        printf("%d ", random_number);
    }
    printf("\n");

    return 0;
}
