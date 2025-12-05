#include<stdio.h>
#include<stdlib.h>
#define N 10

int main()
{
    int i, v[N], par = 0, impar = 0;
    printf("Digite 10 valores inteiros:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%d",&v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%d\n",v[i]);
        if (v[i] % 2 == 0)
        {
            par++;
        }
        else
        {
            impar++;
        }
    }
    printf("Quantidade de valores pares: %d\n",par);
    printf("Quantidade de valores impares: %d\n",impar);
}