#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 10
#define TAM 100

typedef struct
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct
{
    int hora;
    int minuto;
} THora;

typedef struct
{
    char *nome_curso;
    int ano_curso;
    char *nickname;
} TCurso;

typedef struct
{
    int gols;
    int assistencias;
    int c_amarelos;
    int c_vermelhos;
    int faltas;
    int minutos_jogados;
} TIndividual;

typedef struct
{
    int codigo;
    THora horario_partida;
    TData data_partida;
    char *local;
    char *adversario;
} TPartida;

typedef struct
{
    char *nome_jogador;
    int n_camisa;
    TCurso turma;
    TData data_nascimento;
    int qnt_partidas;
    TPartida *partidas;
    TIndividual *estatisticas;
} TJogador;

int main()
{
    TJogador *jogadores = NULL;
    TPartida *partidas = NULL;
    int qnt_jogadores;
    int qnt_partidas;
    char straux[1000];
    int i, j, k;

    printf("Digite o numero de jogadores que deseja adicionar: ");
    scanf("%d", &qnt_jogadores);

    printf("Digite a quantidade de partidas que serao disputadas: ");
    scanf("%d", &qnt_partidas);

    jogadores = (TJogador *)malloc(qnt_jogadores * sizeof(TJogador));
    if (jogadores == NULL)
    {
        printf("erro de alocacao\n");
        return 1;
    }

    partidas = (TPartida *)malloc(qnt_partidas * sizeof(TPartida));
    if (partidas == NULL)
    {
        printf("erro de alocacao\n");
        free(jogadores);
        return 1;
    }

    for (i = 0; i < qnt_jogadores; i++)
    {
        printf("Digite o nome do jogador %d: ", i + 1);
        scanf("%s", &straux);
        gets(straux);
        fflush(stdin);

        jogadores[i].nome_jogador = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(jogadores[i].nome_jogador, straux);

        int data_valida = 0;
        while (!data_valida)
        {
            printf("Digite a data de nascimento (DD MM AAAA) do jogador %d: ", i + 1);
            if (scanf("%d %d %d", &jogadores[i].data_nascimento.dia,
                      &jogadores[i].data_nascimento.mes,
                      &jogadores[i].data_nascimento.ano) != 3)
            {
                printf("data invalida!\n");
            }
        

            int d = jogadores[i].data_nascimento.dia;
            int m = jogadores[i].data_nascimento.mes;
            int a = jogadores[i].data_nascimento.ano;

            data_valida = 1;
            if (m < 1 || m > 12)
                data_valida = 0;
            else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d < 1 || d > 31))
                data_valida = 0;
            else if ((m == 4 || m == 6 || m == 9 || m == 11) && (d < 1 || d > 30))
                data_valida = 0;
            else if (m == 2)
            {
                int bissexto = (a % 400 == 0) || (a % 4 == 0 && a % 100 != 0);
                if (d < 1 || d > (bissexto ? 29 : 28))
                    data_valida = 0;
            }

            if (!data_valida)
                printf("Data invalida! ");
        }

        printf("Digite o curso do jogador %d: ", i + 1);
        scanf("%s", &straux);
        gets(straux);
        fflush(stdin);
        jogadores[i].turma.nome_curso = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(jogadores[i].turma.nome_curso, straux);

        printf("Digite o ano do curso do jogador %d: ", i + 1);
        scanf("%d", &jogadores[i].turma.ano_curso);

        printf("digite o nickname do jogador %d: ", i + 1);
        scanf("%s", &straux);
        gets(straux);
        fflush(stdin);
        jogadores[i].turma.nickname = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(jogadores[i].turma.nickname, straux);

        printf("digite o numero da camisa do jogador %d: ", i + 1);
        scanf("%d", &jogadores[i].n_camisa);

        jogadores[i].estatisticas = (TIndividual *)malloc(qnt_partidas * sizeof(TIndividual));
        for (j = 0; j < qnt_partidas; j++)
        {
            jogadores[i].estatisticas[j].gols = 0;
            jogadores[i].estatisticas[j].assistencias = 0;
            jogadores[i].estatisticas[j].c_amarelos = 0;
            jogadores[i].estatisticas[j].c_vermelhos = 0;
            jogadores[i].estatisticas[j].faltas = 0;
            jogadores[i].estatisticas[j].minutos_jogados = 0;
        }
    }

    for (k = 0; k < qnt_partidas; k++)
    {
        printf("digite o codigo da partida %d: ", k + 1);
        scanf("%d", &partidas[k].codigo);
        int data_valida = 0;
        while (!data_valida)
        {
            printf("digite a data da partida %d (DD MM AAAA): ", k + 1);
            if (scanf("%d %d %d", &partidas[k].data_partida.dia,
                      &partidas[k].data_partida.mes,
                      &partidas[k].data_partida.ano) != 3)
            {
                printf("data invalida\n");
            }

            int d = partidas[k].data_partida.dia;
            int m = partidas[k].data_partida.mes;
            int a = partidas[k].data_partida.ano;

            data_valida = 1;
            if (m < 1 || m > 12)
                data_valida = 0;
            else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d < 1 || d > 31))
                data_valida = 0;
            else if ((m == 4 || m == 6 || m == 9 || m == 11) && (d < 1 || d > 30))
                data_valida = 0;
            else if (m == 2)
            {
                int bissexto = (a % 400 == 0) || (a % 4 == 0 && a % 100 != 0);
                if (d < 1 || d > (bissexto ? 29 : 28))
                    data_valida = 0;
            }

            if (!data_valida)
                printf("data invalida! ");
        }

        printf("digite o local da partida %d: ", k + 1);
        scanf("%s", &straux);
        gets(straux);
        fflush(stdin);
        partidas[k].local = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(partidas[k].local, straux);

        printf("digite o nome do adversario da partida %d: ", k + 1);
        scanf("%s", &straux);
        gets(straux);
        fflush(stdin);
        partidas[k].adversario = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(partidas[k].adversario, straux);
    }

    for (k = 0; k < qnt_partidas; k++)
    {
        printf(" ESTATISTICAS - PARTIDA %d\n", k + 1);
        for (i = 0; i < qnt_jogadores; i++)
        {
            printf("\nJogador: %s (numero %d)\n", jogadores[i].nome_jogador, jogadores[i].n_camisa);

            printf("Minutos jogados: ");
            scanf("%d", &jogadores[i].estatisticas[k].minutos_jogados);

            printf("Gols: ");
            scanf("%d", &jogadores[i].estatisticas[k].gols);

            printf("Assistencias: ");
            scanf("%d", &jogadores[i].estatisticas[k].assistencias);

            printf("Faltas: ");
            scanf("%d", &jogadores[i].estatisticas[k].faltas);

            do
            {
                printf("Cartoes amarelos (max 2): ");
                scanf("%d", &jogadores[i].estatisticas[k].c_amarelos);
                if (jogadores[i].estatisticas[k].c_amarelos > 2)
                    printf("ERRO: Maximo 2 cartoes amarelos!\n");
            } while (jogadores[i].estatisticas[k].c_amarelos > 2);

            do
            {
                printf("Cartoes vermelhos (max 1): ");
                scanf("%d", &jogadores[i].estatisticas[k].c_vermelhos);
                if (jogadores[i].estatisticas[k].c_vermelhos > 1)
                    printf("ERRO: Maximo 1 cartao vermelho!\n");
            } while (jogadores[i].estatisticas[k].c_vermelhos > 1);
        }
    }

    printf(" RELATORIO ");
    for (i = 0; i < qnt_jogadores; i++)
    {
        printf(" JOGADOR %d: %s\n", i + 1, jogadores[i].nome_jogador);
        printf("Data de nascimento: %02d/%02d/%04d\n",
               jogadores[i].data_nascimento.dia,
               jogadores[i].data_nascimento.mes,
               jogadores[i].data_nascimento.ano);
        printf("Curso: %s - %d ano\n", jogadores[i].turma.nome_curso, jogadores[i].turma.ano_curso);
        printf("Nickname: %s\n", jogadores[i].turma.nickname);
        printf("Numero da camisa: %d\n", jogadores[i].n_camisa);

        for (j = 0; j < qnt_partidas; j++)
        {
            printf(" PARTIDA %d\n", j + 1);
            printf("Codigo: %d\n", partidas[j].codigo);
            printf("Data: %02d/%02d/%04d\n",
                   partidas[j].data_partida.dia,
                   partidas[j].data_partida.mes,
                   partidas[j].data_partida.ano);
            printf("Local: %s\n", partidas[j].local);
            printf("Adversario: %s\n", partidas[j].adversario);

            printf("Estatisticas:\n");
            printf("  Minutos jogados: %d\n", jogadores[i].estatisticas[j].minutos_jogados);
            printf("  Gols: %d\n", jogadores[i].estatisticas[j].gols);
            printf("  Assistencias: %d\n", jogadores[i].estatisticas[j].assistencias);
            printf("  Faltas: %d\n", jogadores[i].estatisticas[j].faltas);
            printf("  Cartoes amarelos: %d\n", jogadores[i].estatisticas[j].c_amarelos);
            printf("  Cartoes vermelhos: %d\n", jogadores[i].estatisticas[j].c_vermelhos);
        }
    }

    for (i = 0; i < qnt_jogadores; i++)
    {
        free(jogadores[i].nome_jogador);
        free(jogadores[i].turma.nome_curso);
        free(jogadores[i].turma.nickname);
        free(jogadores[i].estatisticas);
    }
    free(jogadores);

    for (k = 0; k < qnt_partidas; k++)
    {
        free(partidas[k].local);
        free(partidas[k].adversario);
    }
    free(partidas);

    return 0;

}