#include<stdio.h>

int soma(int a, int b);
int sub(int a, int b);

int main()
{
    int a, b, r;
    printf("Digite dois inteiros: ");
    scanf("%d %d",&a, &b);
    r = soma(a,b);
    printf("Soma: %d\n", r);
    r = sub(a,b);
    printf("Subtracao: %d\n", r);
    return 0;
}

int soma(int a, int b)
{
    int r = a + b;
    return r;
}

int sub(int a, int b)
{
    int r = a - b;
    return r; 
}
