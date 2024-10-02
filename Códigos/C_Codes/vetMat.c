#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int diasDoMes [31];
float medidas [10];
char nome [20];
int teleSena [5][5];

struct veiculo
{
    char fabricante [15];
    unsigned short int anoFabricacao;
    char combustivel [15];
    float torque;
    bool estaLocado;


};
struct veiculo Veiculo;
struct veiculo Veiculo2;
struct veiculo Veiculo3;

int main(){
    Veiculo.estaLocado = true;
    strcpy(Veiculo.combustivel, "Total Flex");
    strcpy(Veiculo2.combustivel, "Eletrico");


}