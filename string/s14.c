#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 100

int main()
{
    char str[N];
    int i;
    printf("Digite uma string(ate 100 caracteres): ");
    gets(str);
    for(i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
    printf("Palavra alterada para maiusculo: %s\n",str);

}