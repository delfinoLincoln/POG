#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str1[100] = "Ola, ";
    char str2[] = "mundo!";
    char copia[100];
    int comparacao;
    size_t tamanho; 

    // strcpy: copia str2 para copia
    strcpy(copia,str2);
    printf("Copia: %s\n",copia);

    // strcat: concatena str2 em str1
    strcat(str1," ");
    strcat(str1,str2);
    printf("Str1 apos strcat: %s\n",str1);

    // strcmp compara strl e copia
    comparacao = strcmp(str1,copia);
    if (comparacao == 0)
    {
        printf("strl e copia sao iguais\n");
    }
    else if ( comparacao < 0)
    {
        printf("Str1 vem antes de copia\n");
    }
    else
    {
        printf("str1 vem depois de copia\n");
    }

    // strlen: calcula o tamanho de str1
    tamanho = strlen(str1);
    printf("Tamanho de str1: %zu\n",tamanho);

    return 0;
}