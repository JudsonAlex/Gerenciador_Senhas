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
        printf("NAO FOI POSSIVEL ABRIR ARQUIVO!\n");
        getchar();
        printf("\e[H\e[2J");
        return ;
    }

    printf("\n\n");
    printf("\033[32mIdentificador:\033[m\n");
    scanf("%[^\n]%*c", estrutura.nome);
    printf("\033[32mLogin:\033[m\n");
    scanf("%[^\n]%*c", estrutura.login);
    printf("\033[32mSenha:\033[m\n");
    scanf("%[^\n]%*c", estrutura.senha);

    fwrite(&estrutura, sizeof(acesso),1, arq);

    fclose(arq);
}

void ler_funcao(acesso ler){
    

    arq = fopen("dados.bin", "rb");
    if (arq == NULL)
    {
        printf("NAO FOI POSSIVEL ABRIR ARQUIVO!\n");
        getchar();
        printf("\e[H\e[2J");
        return;
    }

    int i = 0;
    printf("\n\n");
    while (fread(&ler, sizeof(acesso), 1, arq))
    {
        i++;
        printf("Identificador \033[1;34m%d\033[m: \033[33m%s\n\033[m",i, ler.nome);
        printf("Login: \033[33m%s\n\033[m", ler.login);
        printf("Senha: \033[33m%s\n\n\033[m", ler.senha);
    } 
    if (i == 0)
    {
        printf("\033[31mNAO EXISTE SENHAS SALVAS\n\n\033[m");
        printf("Pressione \033[33mENTER\033[m para voltar ao menu Iniciar\n");
        getchar();
        printf("\e[H\e[2J");
        return;
    }
    

    printf("Total de senhas salvas: \033[1;34m%d\033[m\n\n", i);
    printf("Pressione \033[33mENTER\033[m para voltar ao menu Iniciar\n\n");
        
    fclose(arq);
    getchar();
    printf("\e[H\e[2J");
}

void modificar_funcao(acesso modificar){

    arq = fopen("dados.bin", "rb+");
    if (arq == NULL)
    {
        printf("NAO FOI POSSIVEL ABRIR ARQUIVO!\n");
        getchar();
        printf("\e[H\e[2J");
        return;
    }

    int i = 0;
    printf("\n\n");
    while (fread(&modificar, sizeof(acesso), 1, arq))
    {
        i++;
        printf("Identificador \033[1;34m%d\033[m: \033[33m%s\033[m\n",i, modificar.nome);
        printf("Login: \033[33m%s\033[m\n", modificar.login);
        printf("Senha: \033[33m%s\033[m\n\n", modificar.senha);
    }
    if (i == 0)
    {
        printf("\033[31mNENHUMA SENHA PARA EDITAR\n\n\033[m");
        printf("Pressione \033[33mENTER\033[m para voltar ao menu Iniciar\n");
        getchar();
        printf("\e[H\e[2J");
        return;
    } else
    
    printf("Total de senhas salvas: \033[1;34m%d\033[m\n\n", i);

    int ind = 0;

    printf("Escolha o numero da senha que deseja alterar: ");
    scanf("%d%*c", &ind);
    if (ind > 0 && ind <= i)
    {
        ind--;
    printf("Novo Indentificador\n");
    scanf("%[^\n]%*c", modificar.nome);
    printf("Novo login:\n");
    scanf("%[^\n]%*c", modificar.login);
    printf("Nova senha:\n");
    scanf("%[^\n]%*c", modificar.senha);
    fseek(arq, (ind *sizeof(acesso)), SEEK_SET);
    fwrite(&modificar, sizeof(acesso),1 , arq);

    fclose(arq);
    printf("\n\n\033[32mDados alterados com sucesso!\033[m\n\n");
    printf("Pressione \033[33mENTER\033[m para voltar ao menu Iniciar\n");
    getchar();
    printf("\e[H\e[2J");

    } else
    {
        printf("\n\033[31mNumero da senha incorreta!\n\n\033[m");
        printf("Pressione \033[33mENTER\033[m para voltar ao menu Iniciar\n");
        getchar();
        printf("\e[H\e[2J");

    }
    

    
    
}

char gerador_senha(char vetor[], int n_char){
    int i, c;
    printf("Opcoes de senhas:\n");
    printf("[1]-> Apenas numeros\n");
    printf("[2]-> Apenas Letras Maiusculas\n");
    printf("[3]-> Apenas Letras Minusculas\n");
    printf("[4]-> Letras Maiusc. + Minusc.\n");
    printf("[5]-> Letras + Numeros\n");
    printf("[6]-> Letras + Numeros + Caracteres especiais\n");
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
    printf("\nSENHA GERADA:\n\033[32m");
    for(i=0;i<n_char;i++){
        printf("%c",vetor[i]);
    }
    printf("\n\n\033[mPressione \033[33mENTER\033[m para voltar ao menu Iniciar\n");
    printf("\033[m");
    getchar();
    printf("\e[H\e[2J");
}

void deletar(acesso senha){
    int size = 0,i,s_delete;
    arq = fopen("dados.bin","r");
    if (arq == NULL)
    {
        printf("NAO FOI POSSIVEL ABRIR ARQUIVO!\n");
        getchar();
        printf("\e[H\e[2J");
        return;
    }
    
    while (fread(&senha,sizeof(acesso),1,arq))
    {
        printf("\nIdentificador \033[1;34m%d\033[m: \033[33m%s\033[m\n",size+1, senha.nome);
        printf("Login: \033[33m%s\033[m\n", senha.login);
        printf("Senha: \033[33m%s\033[m\n\n", senha.senha);
        size++;
    }
    if (size == 0)
    {
        printf("\033[31mNAO EXISTE SENHAS PARA SEREM EXCLUIDAS\n\n\033[m");
        printf("Pressione \033[33mENTER\033[m para voltar ao menu Iniciar\n");
        getchar();
        printf("\e[H\e[2J");
        return;
    } else
    
    fclose(arq);
    acesso lista_senha[size];
    arq = fopen("dados.bin","rb");
    for(i=0;i<size;i++){
        fread(&lista_senha[i],sizeof(acesso),1,arq);
    }
    fclose(arq);
    printf("\n\033[31mDigite a senha que voce deseja apagar:\033[m ");
    scanf("%d%*c",&s_delete);

    if (s_delete > 0 && s_delete <= i)
    {
        s_delete--;
    arq = fopen("dados.bin","wb");
    for(i=0;i<size;i++){
        if(i!=s_delete){
            fwrite(&lista_senha[i],sizeof(acesso),1,arq);
        }
    }
    printf("\nSenha apagada!\n\n");
    printf("Pressione \033[33mENTER\033[m para voltar ao menu Iniciar\n");
    getchar();
    printf("\e[H\e[2J");

    fclose(arq);
    } else
    {
        printf("\n\033[31mNumero da senha incorreta!\n\n\033[m");
        printf("Pressione \033[33mENTER\033[m para voltar ao menu Iniciar\n");
        getchar();
        printf("\e[H\e[2J");
    
    }
    
}

int main(){

   

    int a, controler = 1;
    acesso gravar_main;

    system("title Gerenciador de Senhas V1.4");
    printf("\n\033[7;34m Bem vindo ao Gerenciador de Senhas V1.4 \033[m\n\n");
    int n;
    char vet[n];
    char decisao;

    while (controler){

        printf("Escolha a opcao desejada\n\n");
        printf("1: Guardar senhas\n");
        printf("2: Ver senhas salvas\n");
        printf("3: Editar senhas\n");
        printf("4: Excluir senhas\n");
        printf("5: Gerar senha\n");
        printf("6: Creditos\n");
        printf("0: Sair\n");
        scanf("%d%*c", &a);
        printf("\e[H\e[2J");

        switch(a)
        {
            case 0:
                controler = 0;
                printf("\nAte a proxima \xF0\x9F\x98\x98\n");
                break;
            case 1:
            do
            {
                gravar_funcao(gravar_main);
                printf("\nAdicionar nova senha? S/N\n");
                scanf("%c%*c", &decisao);
                printf("\e[H\e[2J");
                if (decisao == 'n' || decisao == 'N')
                {
                    printf("\n\033[32mDados Salvos com sucesso!\033[m\n\n");
                    printf("Pressione \033[33mENTER\033[m para voltar ao menu Iniciar\n");
                    getchar();
                    printf("\e[H\e[2J");
                    decisao = 0;
                }

            } while (decisao);
                break;

            case 2:
            ler_funcao(gravar_main);
                break;
            
            case 3:
            modificar_funcao(gravar_main);
                break;
            
            case 4:
            deletar(gravar_main);
                break;

            case 5:
                printf("Quantos caracteres?\n");
                scanf("%d",&n);
                printf("\e[H\e[2J");
                srand((unsigned)time(NULL));
                gerador_senha(vet,n);
                show_senha(vet,n);
                break;
            
            case 6:
            
                printf("Criado com muito amor por:\n\n\033[34mRodrigo Soares\033[m\n\033[36mJudson Alexsander\n\n\033[m");
                printf("Pressione \033[33mENTER\033[m para voltar ao menu Iniciar\n\n");
                getchar();
                printf("\e[H\e[2J");
                break;
        }
    }

    return 0;
}