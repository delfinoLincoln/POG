#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>

typedef struct{
    int ano_curso;
    char *nome_curso;
    char *nickname;
}TTurma;

typedef struct{
    int dia;
    int mes;
    int ano;
}TData;

typedef struct{
    int hora;
    int minuto;
    int segundo;
}THora;

typedef struct{
    int codigo;
    TData data_partida;
    THora hora_partida;
    int minuto_partida;
    char *local;
    char *adversario;
}TPartida;

typedef struct{
    int minutos_jogados;
    int gols;
    int assist;
    int faltas;
    int c_amarelo;
    int c_vermelho;
}THistorico_individual;

typedef struct{
    char *nome;
    int n_camisa;
    int rankingtop;
    TData data_nascimento;
}TJogador;

int main()
{
    TJogador *vetJog;
    TPartida *vetPart;
    THistorico_individual *histo_indi;
    TTurma *turma;
    int num_partidas;
    char straux[1000];
    int i, j, k;
    int qnt_jog;

    printf("quantos jogadores voce deseja registrar? \n");
    scanf("%d", &qnt_jog);
    vetJog = (TJogador*)malloc(qnt_jog * sizeof(TJogador));

    for (i = 0; i < qnt_jog; i++)
    {
        printf("digite o nome do jogador %d: \n", i + 1);
        gets(straux);
        fflush(stdin);
        vetJog[i].nome = (char*)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(vetJog[i].nome, straux);

        printf("digite o dia de nascimento do jogador %d: \n", i + 1);
        scanf("%d", &vetJog[i].data_nascimento.dia);
        fflush(stdin);
        printf("digite o mes de nascimento do jogador %d: \n", i + 1);
        scanf("%d", &vetJog[i].data_nascimento.mes);
        fflush(stdin);
        printf("digite o ano de nascimento do jogador %d: \n", i + 1);
        scanf("%d", &vetJog[i].data_nascimento.ano);
        fflush(stdin);

        for (j = 0; j < j + 1; j++)
        {
            if (vetJog[i].data_nascimento.mes == 1 || vetJog[i].data_nascimento.mes == 3 || vetJog[i].data_nascimento.mes == 4 || vetJog[i].data_nascimento.mes == 7 || vetJog[i].data_nascimento.mes == 8 || vetJog[i].data_nascimento.mes == 10 || vetJog[i].data_nascimento.mes == 12 && vetJog[i].data_nascimento.dia < 0 || vetJog[i].data_nascimento.dia > 31)
            {
                printf("digite um dia valido: \n");
                scanf("%d", &vetJog[i].data_nascimento.dia);
                fflush(stdin);
            }
            else
            {
                break;
            }
        }

        while (1)
        {
            if (vetJog[i].data_nascimento.mes == 5 || vetJog[i].data_nascimento.mes == 6 || vetJog[i].data_nascimento.mes == 9 || vetJog[i].data_nascimento.mes == 11 && vetJog[i].data_nascimento.dia < 0 || vetJog[i].data_nascimento.dia > 30)
            {
                printf("digite um dia valido: \n");
                scanf("%d", &vetJog[i].data_nascimento.dia);
                fflush(stdin);
            }
            else
            {
                break;
            }
        }

        while (1)
        {
            if (vetJog[i].data_nascimento.mes < 0 || vetJog[i].data_nascimento.mes > 12)
            {
                printf("digite um mes valido: \n");
                scanf("%d", &vetJog[i].data_nascimento.mes);
                fflush(stdin);
            }
            else
            {
                break;
            }
        }

        printf("quantas partidas deseja registrar? \n");
        scanf("%d", &num_partidas);
        fflush(stdin);

        for (k = 0; k < num_partidas; k++)
        {
            printf("digite o codigo da partida %d: \n", k + 1);
            gets(straux);
            vetPart[k].codigo = (int*)malloc((strlen(straux) + 1) * sizeof(int));
            vetPart[k].codigo = straux;

            printf("digite o dia da partida %d: \n", k + 1);
            scanf("%d", &vetPart[i].data_partida.dia);
            fflush(stdin);

            printf("digite o mes da partida %d: \n", k + 1);
            scanf("%d", &vetPart[i].data_partida.mes);
            fflush(stdin);

            printf("digite o ano da partida %d: \n", k + 1);
            scanf("%d", &vetPart[i].data_partida.ano);
            fflush(stdin);

            while (1)
        {
            if (vetPart[i].data_partida.mes == 5 || vetPart[i].data_partida.mes == 6 || vetPart[i].data_partida.mes == 9 || vetPart[i].data_partida.mes == 11 && vetPart[i].data_partida.dia < 0 || vetPart[i].data_partida.dia > 30)
            {
                printf("digite um dia valido: \n");
                scanf("%d", &vetPart[i].data_partida.dia);
                fflush(stdin);
            }
            else
            {
                break;
            }
        }
            while (1)
        {
            if (vetPart[i].data_partida.mes == 1 || vetPart[i].data_partida.mes == 3 || vetPart[i].data_partida.mes == 4 || vetPart[i].data_partida.mes == 7 || vetPart[i].data_partida.mes == 8 || vetPart[i].data_partida.mes == 10 || vetPart[i].data_partida.mes == 12 && vetPart[i].data_partida.dia < 0 || vetPart[i].data_partida.dia > 31)
            {
                printf("digite um dia valido: \n");
                scanf("%d", &vetPart[i].data_partida.dia);
                fflush(stdin);
            }
            else
            {
                break;
            }
        }

        printf("digite o local da partida %d: \n", k + 1);
        gets(straux);
        fflush(stdin);
        vetPart[i].local = (char*)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(vetPart[k].local, straux);

        printf("digite o nome do adversario da partida %d: \n", k + 1);
        gets(straux);
        fflush(stdin);
        vetPart[i].adversario = (char*)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(vetPart[k].adversario, straux);

        
        }

        
    }
}
