#include <stdio.h>
int main(){
 typedef struct{
    int id;
    char senha[30], nome[30];
} guardar;

int quantidade, vet;

FILE *arq;
arq = fopen("guardar.txt", "a");
if  (arq == NULL)
{
    printf("NAO FOI POSSIVEL ABRIR ARQUIVO.");
} else




printf("Quantas senhas sera guardada?\n");
scanf("%d%*c", &quantidade);

guardar teste[quantidade];

for (vet=0;vet<quantidade;vet++)
{
    printf("Nome do Site: %d\n", vet + 1);
    fgets(teste[vet].nome,30,stdin);
    fflush(stdin);
    printf("Agora diga a senha:\n");
    fgets(teste[vet].senha,30,stdin);
    fflush(stdin);
}
 for (vet=0;vet<quantidade;vet++)
{
    fprintf(arq,"%s",teste[vet].nome);
    fprintf(arq,"%s",teste[vet].senha);
    fprintf(arq,"%d", vet+1);
}




return 0;
}
