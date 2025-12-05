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
    int i, j;

    printf("Digite o numero de jogadores que deseja adicionar: ");    
    scanf("%d", &qnt_jogadores);
    fflush(stdin);

    printf("Digite a quantidade de partidas que serao disputadas: ");
    scanf("%d", &qnt_partidas);
    fflush(stdin);

    // ALOCAÇÃO CORRETA - ESSE ERA O PRINCIPAL ERRO!
    jogadores = (TJogador*)malloc(qnt_jogadores * sizeof(TJogador));
    if (jogadores == NULL) {
        printf("Erro de alocacao!\n");
        return 1;
    }

    for(i = 0; i < qnt_jogadores; i++)
    {
        printf("\n--- Jogador %d ---\n", i + 1);
        
        printf("Digite o nome do jogador: ");
        gets(strAux);
        fflush(stdin);
        jogadores[i].nome_jogador = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(jogadores[i].nome_jogador, strAux);

        printf("Digite a data de nascimento (DD MM AAAA): ");
        scanf("%d %d %d", &jogadores[i].data_nascimento.dia, 
                          &jogadores[i].data_nascimento.mes,
                          &jogadores[i].data_nascimento.ano);
        fflush(stdin);

        printf("Digite o curso do jogador: ");
        gets(strAux);
        fflush(stdin);
        jogadores[i].turma.nome_curso = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(jogadores[i].turma.nome_curso, strAux);

        printf("Digite o ano do curso: ");
        scanf("%d", &jogadores[i].turma.ano_curso);
        fflush(stdin);

        printf("Digite o nickname: ");
        gets(strAux);
        fflush(stdin);
        jogadores[i].turma.nickname = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(jogadores[i].turma.nickname, strAux);

        printf("Digite o numero da camisa: ");
        scanf("%d", &jogadores[i].n_camisa);
        fflush(stdin);

        // ALOCAR AS PARTIDAS E ESTATÍSTICAS - ISSO TAVA FALTANDO!
        jogadores[i].qnt_partidas = qnt_partidas;
        jogadores[i].partidas = (TPartida*)malloc(qnt_partidas * sizeof(TPartida));
        jogadores[i].estatisticas = (TIndividual*)malloc(qnt_partidas * sizeof(TIndividual));
    }

    // AGORA PREENCHE AS PARTIDAS
    for(i = 0; i < qnt_partidas; i++)
    {
        printf("\n--- Partida %d ---\n", i + 1);
        
        for(j = 0; j < qnt_jogadores; j++)
        {
            printf("\nPara o jogador %s:\n", jogadores[j].nome_jogador);
            
            printf("Digite o codigo da partida: ");
            scanf("%d", &jogadores[j].partidas[i].codigo);
            fflush(stdin);
            
            // AQUI VOCÊ PODE ADICIONAR OS OUTROS CAMPOS DA PARTIDA...
            // jogadores[j].partidas[i].horario_partida, etc.
        }
    }

    // LIBERAR MEMÓRIA NO FINAL
    for(i = 0; i < qnt_jogadores; i++) {
        free(jogadores[i].nome_jogador);
        free(jogadores[i].turma.nome_curso);
        free(jogadores[i].turma.nickname);
        free(jogadores[i].partidas);
        free(jogadores[i].estatisticas);
    }
    free(jogadores);

    return 0;
}