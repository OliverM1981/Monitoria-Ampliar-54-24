#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define ACELERATION_G 9.81
#define PI 3.141592653589793 // Definição de PI usando #define

// Definição do enum cores
enum cores {
    RED = 0,
    GREEN = 1,
    BLUE = 2
};

// Função para verificar se a aceleração é alta
bool is_high_acceleration(double acceleration) {
    return acceleration > ACELERATION_G;
}

// Função para retornar a cor associada com base na aceleração
enum cores get_color_based_on_acceleration(double acceleration) {
    if (acceleration < ACELERATION_G) {
        return GREEN; // Aceleração baixa é associada à cor GREEN
    } else if (acceleration == ACELERATION_G) {
        return BLUE;  // Aceleração igual à constante é associada à cor BLUE
    } else {
        return RED;   // Aceleração alta é associada à cor RED
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
char projeto[] = "Ampliar Tecnologias";

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    srand((unsigned int)time(NULL));

    colours = RED;
    printf("Cor selecionada: %d\n", colours);

    u.numero = 42;
    printf("Valor da union (numero): %d\n", u.numero);

    u.decimal = 3.14f;
    printf("Valor da union (decimal): %.2f\n", u.decimal);

    u.letra = 'A';
    printf("Valor da union (letra): %c\n", u.letra);

    Pessoa.idade = 25;
    strcpy(Pessoa.nome, "João Silva");
    Pessoa.estatura = 1.75f;
    printf("Pessoa:\n");
    printf("Idade: %d\n", Pessoa.idade);
    printf("Nome: %s\n", Pessoa.nome);
    printf("Estatura: %.2f\n", Pessoa.estatura);

    strcpy(Livro1.titulo, "O Guia do Mochileiro das Galáxias");
    strcpy(Livro1.autor, "Douglas Adams");
    Livro1.ano_publicacao = 1979;
    Livro1.preco = 29.90f;
    printf("Livro:\n");
    printf("Título: %s\n", Livro1.titulo);
    printf("Autor: %s\n", Livro1.autor);
    printf("Ano de publicação: %d\n", Livro1.ano_publicacao);
    printf("Preço: %.2f\n", Livro1.preco);

    serie = 12345;
    printf("Número da série: %hu\n", serie);
    printf("Valor máximo de 32 bits: %lu\n", max32);
    printf("Valor de PI_F: %.7f\n", PI_F);
    printf("Valor de PI: %.15f\n", PI);
    printf("Projeto: %s\n", projeto);

    double acceleration = 12.5;

    if (is_high_acceleration(acceleration)) {
        printf("A aceleração de %.2f é alta.\n", acceleration);
    } else {
        printf("A aceleração de %.2f não é alta.\n", acceleration);
    }

    enum cores color = get_color_based_on_acceleration(acceleration);

    switch (color) {
        case RED:
            printf("A cor associada à aceleração é RED.\n");
            break;
        case GREEN:
            printf("A cor associada à aceleração é GREEN.\n");
            break;
        case BLUE:
            printf("A cor associada à aceleração é BLUE.\n");
            break;
        default:
            printf("Cor desconhecida.\n");
            break;
    }

    printf("Números aleatórios:\n");
    for (int i = 0; i < 5; ++i) {
        int random_number = rand() % 100; // Número aleatório entre 0 e 99
        printf("%d ", random_number);
    }
    printf("\n");

    return 0;
}
