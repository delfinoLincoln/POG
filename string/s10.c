#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main()
{
    char str1[N], str2[N];
    printf("Digite uma string(ate 100 caracteres): ");
    gets(str1);
    printf("Digite outra string: ");
    gets(str2);
    strcat(str1,str2);
    printf("Strings concatenadas: %s\n",str1);
    
}