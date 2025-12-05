#include<stdio.h>
#include<stdlib.h>
#define N 5

int main()
{
    int i;
    float v[N];

    printf("Digite 5 valores reais:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%f",&v[i]);
    }
    printf("\nValores digitados na ordem inversa:\n");
    for( i = 4; i >= 0; i--)
    {
        printf("%.2f\n",v[i]);
    }
    printf("\n");
}