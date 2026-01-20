#include<stdio.h>
#include<stdlib.h>

int funcao(int n1, int n2);

int main()
{
    system("CLS");
    int n1, n2, maior;
    printf("Digite dois valores inteiros: ");
    scanf("%d %d", &n1, &n2);
    maior = funcao(n1,n2);
    printf("O maior valor eh: %d", maior);
    return 0;
}

int funcao(int n1, int n2)
{
    if (n1 > n2)
    {
        return n1;
    }
    else
    {
        return n2;
    }
}