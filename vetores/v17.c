#include<stdio.h>
#include<stdlib.h>
#define N 10

int main()
{
    int i, cont = 0;
    float v[N], soma = 0, media;
    printf("Digite 10 valores:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%f",&v[i]);
        soma += v[i];
    }

    media = soma / N;
    printf("\nValores digitados:\n");
    for( i = 0; i < N; i++)
    {
        printf("%.2f\n",v[i]);
        if ( v[i] > media)
        {
            cont++;
        }
    }
    printf("\nMedia calculada: %.2f\n", media);
    printf("Quantidade de valores acima da media: %d\n",cont);
}
