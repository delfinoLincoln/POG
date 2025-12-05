#include<stdio.h>
#include<stdlib.h>
#define N 7

int main()
{
    int i, v[N], max;
    printf("Digite 7 valores:\n");
    for(i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%d", &v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%d\n", v[i]);
        if ( v[i] > max)
        {
            max = v[i];
        }
    }
    printf("Valor maximo: %d\n", max);

}