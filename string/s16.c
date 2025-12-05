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
    if (tolower(str[0] == 'b'))
    {
        printf("String comeca com 'b'!\n");
    }
    else
    {
        printf("String nao comeca com 'b'!\n");
    }
    
    return 0;
}