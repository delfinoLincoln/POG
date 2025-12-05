#include<stdio.h>
#include<stdlib.h>
#define N 8

int main()
{
    int i, v[N], cont = 0;
    printf("Digite 8 valores:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%d", &v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%d\n",v[i]);
        if (v[i] % 2 == 0 && v[i] % 3 == 0)
        {
            cont++;
        }
    }
    printf("Quantidade de numeros divisiveis por 2 e 3 ao mesmo tempo: %d\n",cont);
}