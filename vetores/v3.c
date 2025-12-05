#include<stdio.h>
#include<stdlib.h>
#define N 7

int main()
{
    int i, v[N];

    printf("Digite 7 valores:\n");
    for(i = 0; i < N; i++)
    {
        printf("Elemento %d: \n", i + 1);
        scanf("%d",&v[i]);
    }
    printf("\nElementos com seus respectivos indices:\n");
    for(i = 0; i < N; i++)
    {
        printf("Indice [%d] = %d\n",i,v[i]);   
    }
    printf("\n");
}