#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main()
{
    char str[N];
    char copia[N];
    
    printf("Digite uma string(ate 100 caracteres): ");
    gets(str);
    strcpy(copia,str);
    printf("String copiada: %s",copia);
}
