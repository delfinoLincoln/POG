#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main()
{
    char str[N];
    int i, a = 0;
    printf("Digite uma string(ate 100 caracteres): ");
    gets(str);
    for(i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'A')
        {
            a++;
        }
    }
    printf("Quantidade de vogais A: %d\n",a);
    
    return 0;
}