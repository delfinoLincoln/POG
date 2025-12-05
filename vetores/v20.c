#include<stdio.h>
#include<stdlib.h>
#define N 10

int main()
{
    int i,pos_maior;
    float v[N],maior = 0;
    printf("Digite 10 valores:\n");
    for( i = 0; i < N; i++)
    {
        printf("Posicao %d: \n", i);
        scanf("%f",&v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%.2f\n",v[i]);
        if ( v[i] > maior)
        {
            maior = v[i];
            pos_maior = i;
        }
    }
    printf("Maior valor: %.2f\n",maior);
    printf("Posicao do maior valor: %d\n",pos_maior );
}