#include<stdio.h>

int main()
{
    int i, n, primo;
    printf("Digite um valor inteiro positivo: ");
    scanf("%d",&n);

    for(i = 2; i <= n; i++)
    {
        if ( n % i == 0)
        {
            primo++;
        }
        if (n==1 || primo >=1)
        {
            printf("Numero composto!\n");
        }
        else
        {
            printf("Numero primo!\n");
        }
    }
}