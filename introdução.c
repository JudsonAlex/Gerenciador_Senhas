#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

FILE *arq;

typedef struct{
    char login[30];
    char senha[30];
    char nome[30];
    int id;

}acesso;


void gravar_funcao(acesso estrutura){

    

    arq = fopen("dados.bin", "ab");
    if (arq == NULL)
    {
        printf("Nao foi possivel criar o arquivo!\n");
        return ;
    }

    printf("Ola! vamos iniciar\n\n");
    printf("Identificador:\n");
    scanf("%s", estrutura.nome);
    printf("Login:\n");
    scanf("%s", &estrutura.login);
    printf("Senha:\n");
    scanf("%s", estrutura.senha);

    fwrite(&estrutura, sizeof(acesso),1, arq);

    fclose(arq);

    printf("\nDados Salvos com sucesso!\n\n");
    printf("Pressione qualquer tecla para voltar ao menu Iniciar");
    getch();
    system("cls");
}

void ler_funcao(acesso ler){


    arq = fopen("dados.bin", "rb");
    if (arq == NULL)
    {
        printf("Nao foi possivel ler dados.\n");
    }

    int i = 0;
    while (fread(&ler, sizeof(acesso), 1, arq))
    {
        i++;
        printf("Identificador %d: %s\n",i, ler.nome);
        printf("Login: %s\n", ler.login);
        printf("Senha: %s\n\n", ler.senha);
    }
    printf("Total de senhas salvas: %d\n\n", i);
    printf("Pressione qualquer tecla para voltar ao menu Iniciar\n\n");
        getch();
        system("cls");
    
    fclose(arq);

}

void modificar_funcao(acesso modificar){

    arq = fopen("dados.bin", "rb+");
    if (arq == NULL)
    {
        printf("Nao foi possivel ler dados.\n");
    }

    int i = 0;
    while (fread(&modificar, sizeof(acesso), 1, arq))
    {
        i++;
        printf("Identificador %d: %s\n",i, modificar.nome);
        printf("Login: %s\n", modificar.login);
        printf("Senha: %s\n\n", modificar.senha);
    }
    printf("Total de senhas salvas: %d\n\n", i);

    int ind = 0;

    printf("Escolha o numero da senha que deseja alterar:\n");
    scanf("%d%*c", &ind);
    ind--;
    printf("Novo Indentificador\n");
    scanf("%s", modificar.nome);
    printf("Novo login:\n");
    scanf("%s", modificar.login);
    printf("Nova senha:\n");
    scanf("%s", modificar.senha);
    fseek(arq, (ind *sizeof(acesso)), SEEK_SET);
    fwrite(&modificar, sizeof(acesso),1 , arq);

    fclose(arq);
    printf("\n\nDados alterados com sucesso!\n\n");
    printf("Pressione qualquer tecla para voltar ao menu Iniciar\n");
    getch();
    system("cls");

    

    


}


int main(){
    int a;
    acesso gravar_main;

    printf("\nBem vindo ao Gerenciador de Senhas V1.0\n\n");

while (a != 0){

    
    printf("Escolha a opcao desejada\n\n");
    printf("1: Guardar senhas\n");
    printf("2: Ver senhas salvas\n");
    printf("3: Editar senhas\n");
    printf("4: Excluir senhas\n");
    printf("5: Gerar senha\n");
    printf("0: Sair\n");
    scanf("%d%*c", &a);
    system("cls");
    printf("\n\nOpcao selecionada %d: Carregando...\n", a);
    Sleep(1000); // pra da um efeito de carregamento dos dados
    system("cls");

    switch (a)
    {
    case 1:
        gravar_funcao(gravar_main);
        break;
    
    case 2:
    ler_funcao(gravar_main);
        break;
    
    case 3:
    modificar_funcao(gravar_main);
        break;
    
    case 4:
    printf("Em breve.\n");
    Sleep(1500);
    system("cls");
        break;

    case 5:
    printf("Disponivel na proxima atualizacao\n");
    Sleep(1500);
    system("cls");
        break;
    }

    
    } if (a == 0){
    printf("Ate breve!\n\n");
    printf("Fechando...\n");
    Sleep(1000);
    
    }

    return 0;
}