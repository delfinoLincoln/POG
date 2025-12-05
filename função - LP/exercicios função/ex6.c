#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


int soma(int a, int b);
int sub(int a, int b);
int multi(int a, int b);
int divisao(int a, int b);
int fatorial(int n);



int main()
{
    system("cls");

    int opcao;
    int n1, n2;
    do
    {
        system("cls");

        printf("\n====MENU====\n");
        printf("(1) - SOMA\n");
        printf("(2) - SUBTRACAO\n");
        printf("(3) - MULTIPLICACAO\n");
        printf("(4) - DIVISAO\n");
        printf("(5) - FATORIAL\n");
        printf("(0) - SAIR\n");
        printf("\n** Escolha uma opcao: \n");
        scanf("%d",&opcao);
        switch(opcao)
        {
            case 1:
            printf("voce escolheu soma!\n\n");
            printf("Digite 2 valores: ");
            scanf("%d %d", &n1, &n2);
            printf("Resultado: %d\n", soma(n1, n2));
            break;

            case 2:
            printf("voce escolheu subtracao!\n\n");
            printf("Digite 2 valores: ");
            scanf("%d %d", &n1, &n2);
            printf("Resultado: %d\n", sub(n1, n2));
            break;

            case 3:
            printf("voce escolheu multiplicacao!\n\n");
            printf("Digite 2 valores: ");
            scanf("%d %d", &n1, &n2);
            printf("Resultado: %d\n", multi(n1, n2));
            break;

            case 4:
            printf("voce escolheu divisao!\n\n");
            printf("Digite 2 valores: ");
            scanf("%d %d", &n1, &n2);
            printf("Resultado: %d\n", divisao(n1, n2));
            break;

            case 5:
            printf("voce escolheu fatorial!\n\n");
            printf("Digite um valor: ");
            scanf("%d",&n1);
            printf("Resultado: %d\n",fatorial(n1));
            break;

            case 0:
            printf("saindo...\n\n");
            exit(0);

            default:
            printf("\nopcao invalida!\n\n");
        }
        system("pause");
    }
    while(opcao != 0);
    


}

int soma(int a, int b)
{
    int resultado = a + b;
    return resultado;
}

int sub(int a, int b)
{
    int resultado = a - b;
    return resultado;
}

int multi(int a, int b)
{
    int resultado = a * b;
    return resultado;
}
int divisao(int a, int b)
{
    int resultado = a / b;
    return resultado;
}
int fatorial(int n)
{
    int i, resultado = 1;
    for(i = 1; i <= n; i++)
    {
        resultado *= i;
    }
    return resultado;
}