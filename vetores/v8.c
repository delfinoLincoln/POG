#include<stdio.h>
#include<stdlib.h>
#define N 8

int main()
{
    int i, v[N];
    printf("Digite 8 valores inteiros:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%d",&v[i]);
    }
    printf("\nMultiplos de 3:\n");
    for( i = 0; i < N; i++)
    {
        if ( v[i] % 3 == 0)
        {
            printf("%d\n", v[i]);
        }
    }
    printf("\n");
}