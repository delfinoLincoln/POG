#include<stdio.h>
#include<stdlib.h>
#define N 6

int main()
{
    int i;
    float v[N], soma;

    printf("Digite 6 valores reais:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%f", &v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%.2f\n",v[i]);
        soma += v[i];
    }
    printf("Media final = %.2f", soma / N);

}