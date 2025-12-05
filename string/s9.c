#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main()
{
    char str[N];
    int tam, i;

    printf("Digite uma string(ate 100 caracteres): ");
    gets(str);
    tam = strlen(str);
    printf("\nPalavra invertida:\n");
    for(i = tam - 1; i >= 0; i--)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}