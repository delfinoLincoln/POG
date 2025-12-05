#include<stdio.h>
#include<stdlib.h.>
#define N 10

int main()
{
    int i, v[N], procurado, encontrado = 0;
    printf("Digite 10 valores inteiros:\n");
    for( i = 0; i < N; i++)
    {
        printf("Posicao %d: \n", i);
        scanf("%d",&v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%d\n",v[i]);
    }
    printf("\nDigite um valor a ser procurado:\n");
    scanf("%d",&procurado);
    for( i = 0; i < N; i++)
    {
        if (v[i] == procurado)
        {
            printf("Valor encontrado na posicao %d\n",i);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
    {
        printf("Valor nao encontrado dentre os 10 digitados\n");
    }   
}