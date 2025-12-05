#include<stdio.h>
#include<stdlib.h>
#define L 10
#define C 10

int main()
{
    int matriz[L][C];
    int i, j;
    printf("Preencha a matriz %dx%d: ", L, C);
    for(i = 0; i < L; i++)
    {
        for( j = 0; j < C; j++)
        {
            printf("Elemento [%d][%d]: ", i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
    printf("Matriz preenchida!\n");
    return 0;
}