#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//definição da estrutura para a data de nascimento
typedef struct
{
    int dia;
    int mes;
    int ano;    
} TDATA;

//definição da estrutura para o pet
typedef struct
{
    char *nome;
    TDATA data_nascimento;
    char *raca
} TPet;

#define MAX_LEN 2
#define MAX_STRLEN 100

int main()
{
    TPet vetPet[MAX_LEN];
    char strAux[MAX_STRLEN];
    int i;

    for(i = 0; i < MAX_LEN; i++)
    {
        printf("Digite o nome do pet %d: ", i + 1);
        gets(strAux);
        fflush(stdin);
        vetPet[i].nome = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(vetPet[i].nome, strAux);

        printf("Digite a raca do pet %d: ", i + 1);
        gets(strAux);
        fflush(stdin);
        vetPet[i].raca = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(vetPet[i].raca,strAux);

        printf("Digite a dia de nascimento do pet %d: ",i + 1);
        scanf("%d", &vetPet[i].data_nascimento.dia);
        fflush(stdin);
        printf("Digite a mes de nascimento do pet %d: ",i + 1);
        scanf("%d", &vetPet[i].data_nascimento.mes);
        fflush(stdin);
        printf("Digite a ano de nascimento do pet %d: ",i + 1);
        scanf("%d", &vetPet[i].data_nascimento.ano);
        fflush(stdin);
    }

    //printar toda struct
    for(i = 0; i < MAX_LEN; i++)
    {
        printf("\nPet %d:\n", i + 1);
        printf("Nome: %s\n",vetPet[i].nome);
        printf("Raca: %s\n",vetPet[i].raca);
        printf("Data de nascimento: %02d/%02d/%04d\n",
        vetPet[i].data_nascimento.dia,
        vetPet[i].data_nascimento.mes,
        vetPet[i].data_nascimento.ano
    );
    }
    free(vetPet);
}