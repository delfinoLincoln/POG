#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main()
{
    char nome[N];
    char sobrenome[N];

    printf("Digite um nome: ");
    gets(nome);
    printf("Digite um sobrenome: ");
    gets(sobrenome);
    strcat(nome, " ");
    strcat(nome,sobrenome);
    printf("Nome completo: %s\n",nome);
}