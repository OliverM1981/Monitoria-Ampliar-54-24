#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void manipularArquivo(const char *arquivo_entrada, const char *arquivo_saida){
    FILE *entrada =  fopen(arquivo_entrada, "r");
    FILE *saida = fopen(arquivo_saida, "w");
    
   if (entrada == NULL || saida == NULL){
    printf("Erro ao abrir arquivo!\n");
    exit(1);
   }
    char c;
    while ((c = fgetc(entrada)) != EOF) {
        fputc(toupper(c), saida);
    }

    fclose(entrada);
    fclose(saida);

}

int main (){

    manipularArquivo("arquivo_entrada.txt","arquivo_saida.txt");

}