#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define N 100

int main()
{
    char str[N];
    int i;
    printf("Digite uma string(ate 100 caracteres): ");
    gets(str);
    for(i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
    printf("Palavra alterada para o minusculo: %s\n",str);
}