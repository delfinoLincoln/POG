#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char strAux[100], *novo;
    printf("Nome da musica: ");
    gets(strAux);
    fflush(stdin);
    novo = (char *) malloc ((strlen(strAux) + 1) * sizeof(char));
    strcpy(novo, strAux);
    puts(novo);
    free(novo);
    return 0;
}