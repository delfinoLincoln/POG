#include<stdio.h>
#include<stdlib.h>
#define N 8

int main()
{
    int i;
    float v[N], soma;
    printf("Digite 8 valores:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%f", &v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%.2f\n", v[i]);
        if ( v[i] >= 0)
        {
            soma += v[i];
        }
    }
    printf("Soma dos elementos: %.2f\n", soma);
}