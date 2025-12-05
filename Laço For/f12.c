#include<stdio.h>

int main()
{
    int i, n, div;
    printf("Digite um valor inteiro positivo: ");
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        if ( n % i == 0)
        {
            printf("%d\n",i);
            div++;
        }
    }
    printf("Numero digitado possui %d divisores",div);
}