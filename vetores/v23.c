#include<stdio.h>
#include<stdlib.h>
#define N 10

int main()
{
    int i, cont = 0;
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
        if (v[i] >= 20)
        {
            cont++;
        }
    }
    printf("Quantidade de valores acima de 20.0: %d\n",cont);
}