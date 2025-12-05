#include<stdio.h>
#include<stdlib.h>
#define N 15

int main()
{
    int i, abaixo = 0, media = 0, acima = 0;
    float v[N];

    printf("Digite 15 valores:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%f",&v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%.2f\n",v[i]);
        if ( v[i] < 25)
        {
            abaixo++;
        }
        if ( v[i] == 25)
        {
            media++;
        }
        if (v[i] > 25)
        {
            acima++;
        }
    }
    printf("Valores abaixo de 25.0: %d\n",abaixo);
    printf("Valores na media de 25.0: %d\n",media);
    printf("Valores acima de 25.0: %d\n",acima);
}