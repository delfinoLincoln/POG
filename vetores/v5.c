#include<stdio.h>
#include<stdlib.h>
#define N 10

int main()
{
    int i;
    float v[N];

    printf("Digite 10 valores reais:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%f", &v[i]);
    }
    printf("\nValores negativos digitados:\n");
    for( i = 0; i < N; i++)
    {
        if ( v[i] < 0)
        {
            printf("%.2f\n",v[i]);
        }
    }
    printf("\n");
}