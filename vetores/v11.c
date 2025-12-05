#include<stdio.h>
#include<stdlib.h>
#define N 10

int main()
{
    int i, v[N],soma;
    printf("Digite 10 valores:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%d",&v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        soma += v[i];
    }
    printf("Soma: %d",v[i]);
}