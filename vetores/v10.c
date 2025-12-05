#include<stdio.h>
#include<stdlib.h>
#define N 7

int main()
{
    int i, v[N],soma;
    printf("Digite 7 valores:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%d",&v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        soma += v[i];
        printf("%d\n",v[i]);
    }
    printf("Media final = %d\n", v[i] / N);
}