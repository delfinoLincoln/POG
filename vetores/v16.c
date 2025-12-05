#include<stdio.h>
#include<stdlib.h>
#define N 6

int main()
{
    int i, v[N], maior, menor;
    printf("Digite 6 valores inteiros:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%d", &v[i]);
    }
    maior = menor = v[0];
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%d\n",v[i]);
        if (v[i] > maior)
        {
            maior = v[i];
        }
        if (v[i] < menor)
        {
            menor = v[i];
        }
    }
    printf("Maior valor: %d\n",maior);
    printf("Menor valor: %d\n",menor);
    printf("Diferenca: %d\n", maior - menor);
}