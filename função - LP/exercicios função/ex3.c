#include<stdio.h>
#include<stdlib.h>

int par(int a);

int main()
{
    system("CLS");

    int numero;
    printf("Digite um valor inteiro: ");
    scanf("%d", &numero);
    if (par(numero))
    {
        printf("%d eh par!\n", numero);
    }
    else
    {
        printf("%d eh impar!\n",numero);
    }

    return 0;
}

int par(int a)
{
    if (a % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}