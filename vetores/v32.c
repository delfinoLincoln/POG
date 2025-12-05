#include<stdio.h>
#include<stdlib.h>
#define N 10

int main()
{
    int i;
    float v[N], repetido = 0;

    printf("Digite 10 valores float:\n");
    for(i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%f",&v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%.2f\n",v[i]);
    }
    for( i = 0; i < N; i++)
    {
        if (v[i] == repetido)
        {
            printf("Valor repetido na posicao %d\n",i);
            break;
        }
    }
    if (!repetido)
    {
        printf("Nao ha valores repetidos\n");
    }
    
    return 0;
}