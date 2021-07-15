#include <stdio.h>
#include <conio.h>

FILE *arq;

typedef struct{
    char login[30];
    char senha[30];
    char nome[30];
    int id;

}acesso;

void guardar(acesso teste){
    
    arq = fopen("celulares.txt", "a");
    if (arq == NULL)
    {
        printf("NAO FOI POSSSIVEL ABRIR O ARQUIVO\n");
    } else

    printf("Nome:\n");
    scanf("%s", &teste.nome);
    printf("Login:\n");
    scanf("%s", &teste.login);
    printf("Senha\n");
    scanf("%s", &teste.senha);

    fprintf(arq,"%s\n",teste.nome);
    fprintf(arq,"%s\n",teste.login);
    fprintf(arq,"%s\n\n", teste.senha);

    printf("\nDADOS GUARDADOS COM SUCESSO!\n\n");
    
    fclose(arq);
}

int main(){

    int a;
    acesso gravar;
while (a != 0){

    printf(" ______________________\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|       Bem vindo      |\n");
    printf("|                      |\n");
    printf("|    Escolha a opcao:  |\n");
    printf("|                      |\n");
    printf("|  1: Guardar Senhas   |\n");
    printf("|  2: Excluir Senhas   |\n");
    printf("|  3: Editar Senhas    |\n");
    printf("|   4: Gerar Senha     |\n");
    printf("|   5: Ler senhas      |\n");
    printf("|                      |\n");
    printf("|                      |\n");
    printf("|______________________|\n");
    scanf("%d%*c", &a);

    switch (a){
    case (1):
        guardar(gravar);
        break;
    
    default:
        break;
    }

    
} if (a == 0){
    printf("Obrigado, ate breve!\n\n");
    printf("Pressione qualquer tecla para fechar.\n");
    getch();
    return 1;
    }

    return 0;
}