#include<stdio.h>
#include<stdlib.h>
#define N 5

int main()
{
    int i, v[N],produto = 1;
    printf("Digite 5 valores:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%d", &v[i]);
    }
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%d\n", v[i]);
        produto *= v[i];
    }
    printf("Produto dos elementos: %d\n", produto);
}