#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 6

int main()
{
    int i, v[N];
    srand(time(NULL));
    printf("Valores sorteados:\n");
    for( i = 0; i < N; i++)
    {
        v[i] = (rand() % 99);
        printf("%d\n",v[i]);
    }
    printf("\nValores pares:\n");
    for( i = 0; i < N; i++)
    {
        if ( v[i] % 2 == 0)
        {
            printf("%d\n",v[i]);
        }
    }
    printf("\n");
}