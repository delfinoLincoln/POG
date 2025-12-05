#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main()
{
    char str[N];
    int space = 0, i;

    printf("Digite uma frase(ate 100 caracteres): ");
    gets(str);
    
    for( i = 0; str[i] != '\n' && str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            space++;
        }
    }
    printf("Essa frase possui %d espacos!\n",space);
}