#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5

int main()
{
    int i;
    float v[N];

    srand(time(NULL));
    printf("Valores sorteados:\n");
    for( i = 0; i < N; i++)
    {
        v[i] = (rand() % 99);
        printf("%.2f\n", v[i]);
    }
    printf("\nValores maiores que 10.0:\n");
    for( i = 0; i < N; i++)
    {
        if (v[i] > 10)
        {
            printf("%.2f\n",v[i]);
        }
    }
    printf("\n");


}