#include<stdio.h>
#include<stdlib.h>
#define N 6

int main()
{
    int i, cont = 0;
    float v[N];

    printf("Digite 6 valores:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%f",&v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%.2f\n",v[i]);
        if ( v[i] < 0)
        {
            cont++;
        }
    }
    printf("Quantidade de valores abaixo de 0: %d\n",cont);
}