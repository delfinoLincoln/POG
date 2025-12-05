#include<stdio.h>
#include<stdlib.h>
#define N 10

int main()
{
    int i, contador;
    float v[N];

    printf("Digite 10 valores:\n");
    for( i = 0; i < N; i++)
    {
        printf("Valor %d: \n", i + 1);
        scanf("%f",&v[i]);
    }
    printf("\nValores dentro de 5.0 e 15.0:\n");
    for(i = 0; i < N; i++)
    {
        if (v[i] >= 5 && v[i] <= 15)
        {
            printf("%.2f\n",v[i]);
            contador++;
        }
    }
    printf("Quantidade de numeros dentro do intervalo de 5.0 a 15.0: %d", contador);
    printf("\n");
}

    