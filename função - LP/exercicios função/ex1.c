#include<stdio.h>

int soma(int n1, int n2);

int main()
{
    int n1, n2, resultado;
    printf("Digite 2 valores inteiros: ");
    scanf("%d %d",&n1,&n2);
    resultado = soma(n1,n2);
    printf("Soma: %d\n", resultado);
}

int soma(int n1, int n2)
{
    return n1 + n2;
}