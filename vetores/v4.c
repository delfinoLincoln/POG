#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 8

int main()
{
    int i, v[N];
    srand(time(NULL));
    printf("Valores sorteados:\n");
    for( i = 0; i < N; i++)
    {
        v[i] = (rand() % 99);
        printf(" %d\n",v[i]);
    }
    printf("\nValores triplicados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%d\n", v[i] * 3);
    }
    printf("\n");
}