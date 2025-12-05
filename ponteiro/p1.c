#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *vetor = NULL;
    int tamanho, novo_tamanho, i;

    printf("Digite o tamanho inicial: ");
    scanf("%d",&tamanho);

    vetor = (int*) malloc(tamanho * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro de alocacao!\n");
        return 1;
    }

    for(i = 0; i < tamanho; i++)
    {
        printf("Vetor[%d]: ",i);
        scanf("%d",&vetor[i]);
    }
    printf("Digite o novo tamanho do vetor: ");
    scanf("%d",&novo_tamanho);

    int *temp = (int*) realloc(vetor, novo_tamanho * sizeof(int));
    if (temp == NULL)
    {
        printf("Erro ao redimensionar!\n");
        free(vetor);
        return 1;
    }
    //vetor = temp;

    // Se o vetor aumentou, inicializa os novos elementos
    if (novo_tamanho > tamanho)
    {
        for(i = 0; i < novo_tamanho; i++)
        {
            printf("vetor[%d]: ",i);
            scanf("%d",&vetor[i]);
        }
    }

    printf("Conteudo do vetor:\n");
    for(i = 0; i < novo_tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    return 0;
}