#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define N 10
#define TAM 100

typedef struct 
{
    int dia;
    int mes;
    int ano;
}TData;

typedef struct
{
    int hora;
    int minuto;
}THora;

typedef struct
{
    char *nome_curso;
    int ano_curso;
    char *nickname;
}TCurso;

typedef struct
{
    int gols;
    int assistencias;
    int c_amarelos;
    int c_vermelhos;
    int faltas;
    int minutos_jogados;
}TIndividual;

typedef struct 
{
    int codigo;
    THora horario_partida;
    TData data_partida;
    char *local;
    char *adversario;
}TPartida;

typedef struct
{
    char *nome_jogador;
    int n_camisa;
    TCurso turma;
    TData data_nascimento;
    int ranking_top14;
    int qnt_partidas;
    TPartida *partidas;
    TIndividual *estatisticas;
}TJogador;

int main()
{
    TJogador *jogadores = NULL;
    int qnt_jogadores;
    int qnt_partidas;
    char strAux[1000];
    int i, j, k;
    int codigo_valido;

    printf("Digite o numero de jogadores que deseja adicionar: ");    
    scanf("%d",&qnt_jogadores);

    printf("Digite a quantidade de partidas que serao disputadas: ");
    scanf("%d",&qnt_partidas);

    jogadores = (TJogador*)malloc((strlen(strAux) + 1) * sizeof(char));
    for(i = 0; i < qnt_jogadores; i++)
    if (jogadores == NULL)
    {
        printf("Erro de alocacao!\n");
        return 1;
    }

    for(i = 0; i < qnt_jogadores; i++)
    {
        printf("Digite o nome do jogador %d: ", i + 1);
        scanf("%s",&jogadores[i].nome_jogador);
        gets(strAux);
        fflush(stdin);
        jogadores[i].nome_jogador = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(jogadores[i].nome_jogador,strAux);

        printf("Digite a data de nascimento(DD/MM/AAAA) do jogador %d: ", i + 1);
        scanf("%d%d%d", &jogadores[i].data_nascimento.dia, 
                        &jogadores[i].data_nascimento.mes,
                        &jogadores[i].data_nascimento.ano);
        fflush(stdin);

        printf("Digite o curso do jogador %d: ", i + 1);
        gets(strAux);;
        fflush(stdin);
        jogadores[i].turma.nome_curso = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(jogadores[i].turma.nome_curso,strAux);

        printf("Digite o ano do curso do jogador %d: ", i + 1);
        scanf("%d",&jogadores[i].turma.ano_curso);
        fflush(stdin);

        printf("Digite o nickname do jogador %d: ", i + 1);
        gets(strAux);
        fflush(stdin);
        jogadores[i].turma.nickname = (char*)malloc((strlen(strAux) + 1) * sizeof(char));

        printf("Digite o numero da camisa do jogador %d: ", i + 1);
        scanf("%d",&jogadores[i].n_camisa);
        fflush(stdin);
    }
}    
    