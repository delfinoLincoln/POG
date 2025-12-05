#include<stdio.h>
#include<stdlib.h>

int fatorial(int n);

int main()
{
    system("cls");
    int n, resultado;
    printf("Digite um valor inteiro: ");
    scanf("%d", &n);
    resultado = fatorial(n);
    printf("Resultado: %d", resultado);
    return 0;
}

int fatorial(int n)
{
    int i, resultado = 1;
    for(i = 1; i <= n; i++)
    {
        resultado *= i;
    }
    return resultado;
}