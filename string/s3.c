#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main()
{
    char str1[N], str2[N];
    int tam1, tam2;

    printf("Digite uma string(ate 100 caracteres): ");
    gets(str1);
    printf("Digite outra string: ");
    gets(str2);

    tam1 = strlen(str1);
    tam2 = strlen(str2);

    if (tam1 > tam2)
    {
        printf("String 1 maior que string 2!\n");
    }
    else if (tam1 == tam2)
    {
        printf("String com mesmo tamanho!\n");
    }
    else
    {
        printf("String 2 maior que string 1!\n");
    }
    
    
    
}