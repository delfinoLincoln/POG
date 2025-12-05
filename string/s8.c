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
    if (tamanho > 0)
    {
        printf("Ultimo caracter digitado: %c\n",str[tamanho - 1]);
    }

    return 0;
}