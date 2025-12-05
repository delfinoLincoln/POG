#include<stdio.h>
#include<stdlib.h>
#define N 12

int main()
{
    int i, v[N], cont = 0;
    printf("Digite 12 valores:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%d", &v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%d\n",v[i]);
        if (v[i] >= 10 && v[i] <= 50)
        {
            cont++;
        }
    }
    printf("Quantidade de valores entre 10 e 50: %d\n",cont);
}