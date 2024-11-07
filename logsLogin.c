#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

typedef enum { INFO, ERRO, AVISO, SUCESSO} TipoAcao;

typedef enum {FINANCEIRO, RH, PROJETO, MARKETING, VENDAS, GERENCIA, TI} Departamento;


typedef struct{
    char nome [50];
    char senha [10];
    Departamento departamento;
    int isAdmin;
}Usuario;

void registrarLog(TipoAcao tipo, const char *acao){
    FILE *arquivo =  fopen("C:/Users/mauri/OneDrive/Documentos/Monitoria/Ampliar 54-24/Git/Monitoria-Ampliar-54-24/log.txt", "a+");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    time_t agora = time(NULL);
    struct tm *data_e_hora_atual = localtime(&agora);
    char data_e_hora_str[20];
    strftime(data_e_hora_str, sizeof(data_e_hora_str), "%d/%m/%Y %H:%M:%S", data_e_hora_atual);

    const char *acao_str;
    switch (tipo) {
        case INFO: acao_str = "INFO"; break;
        case ERRO: acao_str = "ERRO"; break;
        case AVISO: acao_str = "AVISO"; break;
        case SUCESSO: acao_str = "SUCESSO"; break;
    }

    // Adiciona uma nova linha no final de cada registro
    fprintf(arquivo, "[%s] [%s] %s\n", data_e_hora_str, acao_str, acao);
    fclose(arquivo);
}


int autenticarAdmin(){
    char senha [10];
    printf(" Insira a senha de administrador: ");
    scanf("%s", senha);
    fflush(stdin);

    if(strcmp(senha, "admin") == 0){
       registrarLog(3, " Admin logado com sucesso");
       return 1;
    }else {
        registrarLog(1, " Tentativa de acesso admin inv?lida");  
        return 0;
    }

}

void cadastrarUsuarios( Usuario  *usuarios, int *qtd){
    if(!autenticarAdmin()){
        registrarLog(2,"Usu?rio n o possui permiss?o de admin");
        return;
    } 
    
    Usuario novoUsuario;
    printf("Insira o nome do usu?rio: ");
    scanf("%s", novoUsuario.nome);
    fflush(stdin);
    printf("Digite a senha do usu?rio: ");
    scanf("%s", novoUsuario.senha);
    fflush(stdin);
    printf("Departamentos\n 0-FINANCEIRO\n 1-RH\n 2-PROJETO\n 3-MARKETING\n 4-VENDAS\n 5-GERENCIA\n 6-TI)");
    printf("\nQual ? o departamento: ");
    scanf("%d",(int *) &novoUsuario.departamento);
    fflush(stdin);
    if(novoUsuario.departamento == 5 || novoUsuario.departamento == 6){
        novoUsuario.isAdmin = 1;
    }

    usuarios[(*qtd)++] = novoUsuario;
    registrarLog(3, "Usu?rio cadastrado com sucesso");

}

void acessarModulo(Usuario *usuario, int qtd){
    char nome [50], senha[10];
    unsigned short int encontrouUsuario = 0;
    unsigned short int departamentoAcesso, i;

    printf("Qual departamento voc? ira acessar? \n");
    printf("0-FINANCEIRO\n 1-RH\n 2-PROJETO\n 3-MARKETING\n 4-VENDAS\n 5-GERENCIA\n 6-TI");
    printf("\n Departamento: ");
    scanf("%u",&departamentoAcesso);
    fflush(stdin);
    printf("Insira o nome do usu?rio: ");
    scanf("%s",nome);
    fflush(stdin);


    for( i = 0; i < qtd && encontrouUsuario == 0; i++){
        if(strcmp(usuario[i].nome, nome)==0){
            encontrouUsuario = 1;

            if(encontrouUsuario == 1 && usuario[i].departamento == departamentoAcesso){
            printf("Digite a senha: ");
            scanf("%s",senha);
            fflush(stdin);
            if(strcmp(usuario[i].senha, senha) == 0){
                registrarLog(3, "Acesso ao modulo realizado com sucesso");
            }else{
                registrarLog(1, "Senha incorreta");
            }
        }else {
            registrarLog(1, "Departamento inválido para este usuário");
        }

    }
    return;
 }

    if(!encontrouUsuario){
        registrarLog(0, "Usuário não cadastrado");
    }

}

void listarUsuarios( Usuario *usuarios, int qtd){
    printf("Lista de  Usu?rios:\n");
    for(int i = 0; i < qtd; i++){
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Departamento: %d\n\n", usuarios[i].departamento);
    }


}

int main(){
    setlocale(LC_ALL, "Portuguese");
    Usuario usuario[100];
    int  qtd = 0;
    int opcao;
    
    while(1){
        printf("\n1. Cadastrar usuário \n2. Acessar  modulo \n3. Listar usu?rios \n 4. Sair \n Digite sua op??o: ");
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
            cadastrarUsuarios(usuario, &qtd);
            break;

            case 2:
            acessarModulo(usuario,qtd);
            break;

            case 3:
            listarUsuarios(usuario, qtd);
            break;

            case  4:
            registrarLog(2, "Sess?o encerrada");
            printf("Saindo do sistema...\n");
            return 0;
            break;

            default:
            printf("Op??o invalida\n");

        }
    }
}


