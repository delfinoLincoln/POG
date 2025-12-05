#include<stdio.h>
#include<stdlib.h>
#define N 15

int main()
{
    int i, v[N], cont = 0;
    printf("Digite 15 valores inteiros:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%d",&v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%d\n",v[i]);
        if (v[i] < 0)
        {
            cont++;
        }
    }
    printf("Quantidade de valores negativos: %d\n",cont);
}