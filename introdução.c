#include <stdio.h>
#include <time.h>
#include <stdlib.h>


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

    printf("\n\n");
    printf("\033[32mIdentificador:\033[m\n");
    scanf("%s", estrutura.nome);
    printf("\033[32mLogin:\033[m\n");
    scanf("%s", estrutura.login);
    printf("\033[32mSenha:\033[m\n");
    scanf("%s%*c", estrutura.senha);

    fwrite(&estrutura, sizeof(acesso),1, arq);

    fclose(arq);

    printf("\n\033[32mDados Salvos com sucesso!\033[m\n\n");
    printf("Pressione \033[33mENTER\033[m para voltar ao menu Iniciar\n");
    getchar();
    printf("\e[H\e[2J");
    
}

void ler_funcao(acesso ler){
    

    arq = fopen("dados.bin", "rb");
    if (arq == NULL)
    {
        printf("Nao foi possivel ler dados.\n");
        return;
    }

    int i = 0;
    printf("\n\n");
    while (fread(&ler, sizeof(acesso), 1, arq))
    {
        i++;
        printf("Identificador %d: %s\n",i, ler.nome);
        printf("Login: %s\n", ler.login);
        printf("Senha: %s\n\n", ler.senha);
    }

    printf("Total de senhas salvas: %d\n\n", i);
    printf("Pressione \033[33mENTER\033[m para voltar ao menu Iniciar\n\n");
        
    fclose(arq);
    getchar();
    printf("\e[H\e[2J");
}

void modificar_funcao(acesso modificar){

    arq = fopen("dados.bin", "rb+");
    if (arq == NULL)
    {
        printf("Nao foi possivel ler dados.\n");
        return;
    }

    int i = 0;
    printf("\n\n");
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
    scanf("%s%*c", modificar.senha);
    fseek(arq, (ind *sizeof(acesso)), SEEK_SET);
    fwrite(&modificar, sizeof(acesso),1 , arq);

    fclose(arq);
    printf("\n\n\033[32mDados alterados com sucesso!\033[m\n\n");
    printf("Pressione \033[33mENTER\033[m para voltar ao menu Iniciar\n");
    getchar();
    printf("\e[H\e[2J");

    
    
}

char gerador_senha(char vetor[], int n_char){
    int i, c;
    printf("Opções de senhas:\n");
    printf("[1]-> Apenas números\n");
    printf("[2]-> Apenas Letras Maiúsculas\n");
    printf("[3]-> Apenas Letras Minúsculas\n");
    printf("[4]-> Letras Maiúsc. + Minúsc.\n");
    printf("[5]-> Letras + Números\n");
    printf("[6]-> Letras + Números + Caracteres especiais\n");
    int choice;
    scanf("%d%*c",&choice);
    switch(choice){
        case 1:
            for(i=0;i<n_char;i++){
                vetor[i] = '0'+(char)(rand()%10);
            }
                break;
        case 2:
            for(i=0;i<n_char;i++){
                vetor[i] = 'A'+(char)(rand()%26);
            }
                break;
        case 3:
            for(i=0;i<n_char;i++){
                vetor[i] = 'a'+(char)(rand()%26);
            }
                break;
        case 4:
            i = 0;
            while(i <= n_char){
                
                c = 'A' +(int)(rand()%57);
                if((65<=c)&&(c<=90) || (97<=c)&&(c<=122)){
                    
                    vetor[i] = (char)c;
                    i++;
                }
                
            }
            break;
        case 5:
            i = 0;
            
            while(i <= n_char){
                c = '0' +(int)(rand()%57);
                if((48<=c)&&(c<=57) || (65<=c) && (c<=90) || (97<=c)&&(c<=122)){
                    
                    vetor[i] = (char)c;
                    i++;
                }
                
            }
            break;
        case 6:
            for(i=0;i<n_char;i++){
                vetor[i] = '!'+(char)(rand()%93);
            }
                break;
            
}

}
void show_senha(char vetor[], int n_char){
    int i;
    printf("SENHA GERADA:\n\033[32m");
    for(i=0;i<n_char;i++){
        printf("%c",vetor[i]);
    }
    printf("\033[m");
    getchar();
    printf("\e[H\e[2J");
}

int main(){
    int a, controler = 1;
    acesso gravar_main;

    printf("\nBem vindo ao Gerenciador de Senhas V1.0\n\n");

    while (controler){

        printf("Escolha a opcao desejada\n\n");
        printf("1: Guardar senhas\n");
        printf("2: Ver senhas salvas\n");
        printf("3: Editar senhas\n");
        printf("4: Excluir senhas\n");
        printf("5: Gerar senha\n");
        printf("0: Sair\n");
        scanf("%d%*c", &a);
        printf("\e[H\e[2J");
        
        printf("\n\nOpcao selecionada %d", a);
        
        

        switch(a)
        {
            case 0:
                controler = 0;
                printf("\nAté a próxima \xF0\x9F\x98\x98\n");
                break;
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
            printf("Disponivel na proxima atualizacao\n");
            
            
                break;

            case 5:
                printf(" ");
                int n;
                char vet[n];
                printf("Quantos caracteres?\n");
                scanf("%d",&n);
                srand((unsigned)time(NULL));
                gerador_senha(vet,n);
                show_senha(vet,n);
                
                break;
            
        }

    }

    return 0;
}