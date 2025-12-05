#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main()
{
    int comp;
    char str1[N],str2[N];

    printf("Digite uma string(ate 100 caracteres): ");
    gets(str1);
    printf("Digite outra string: ");
    gets(str2);

    comp = strcmp(str1,str2);
    if (comp == 0)
    {
        printf("Strings iguais!\n");
    }
    else
    {
        printf("Strings diferentes!\n");
    }
    
}