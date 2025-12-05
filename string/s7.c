#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main()
{
    char str[N];

    printf("Digite uma string(ate 100 caracteres): ");
    gets(str);

    printf("Primeira letra: %c\n",str[0]);
}