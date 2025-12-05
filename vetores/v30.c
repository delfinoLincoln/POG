#include<stdio.h>
#include<stdlib.h>
#define N 10

int main()
{
    int i, abaixo = 0, entre = 0, acima = 0;
    float v[N];

    printf("Digite 10 valores:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%f",&v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%.2f\n",v[i]);
        if ( v[i] < 10)
        {
            abaixo++;
        }
        else if (v[i] >= 10 && v[i] <= 50)
        {
            entre++;
        }
        else
        {
            acima++;
        }
    }
    printf("Quantidade de valores abaixo de 10.0: %d\n",abaixo);
    printf("Quantidade de valores entre 10 e 50: %d\n",entre);
    printf("Quantidade de valores acima de 50.0: %d\n",acima);
}