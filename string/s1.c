#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main()
{
    char str[N];
    int tamanho;

    printf("Digite uma string(ate 100 caracteres): ");
    gets(str);
    tamanho = strlen(str);
    printf("Quantidade de caracteres: %zu\n",tamanho);
}