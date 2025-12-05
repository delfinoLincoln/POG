/*
  SISTEMA DE REGISTRO - ESQUADRA FUTSAL
  Versao: 1.0
  Autor: (seu nome aqui)
  Enunciado resumido: cadastrar jogadores, partidas e estatisticas, com validacoes

  Arquitetura:
  - structures: TData, THora, TCurso, TIndividual, TPartida, TJogador
  - funcoes principais:
      cadastrarJogadores, cadastrarPartidas, registrarEstatisticas, imprimirRelatorio
      validarData, validarHora, lerStringDinamica

  Observacoes:
  - Todas as strings sao alocadas dinamicamente (malloc) como pedido.
  - Leitura de linhas usa um buffer temporario e entao e copiada para area dinamica.
  - Codigo escrito para compilar em ambientes compatíveis com C89/C99.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* estruturas */
typedef struct { int dia, mes, ano; } TData;
typedef struct { int hora, minuto; } THora;

typedef struct {
    char *nome_curso;
    int ano_curso;
    char *nickname;
} TCurso;

typedef struct {
    int minutos_jogados;
    int gols;
    int assistencias;
    int faltas;
    int c_amarelos;
    int c_vermelhos;
    int cod_partida; /* referencia a partida (codigo unico) */
} TIndividual;

typedef struct {
    int codigo;
    THora horario_partida;
    TData data_partida;
    char *local;
    char *adversario;
    char *responsavel; /* quem registrou incidentes */
} TPartida;

typedef struct {
    char *nome_jogador;
    TData data_nascimento;
    TCurso turma;
    int n_camisa;
    int qnt_partidas;
    TIndividual *estatisticas; /* vetor com tamanho qnt_partidas */
    int rankingTop14; /* campo pedido */
} TJogador;

/* prototipos */
int validarData(int d, int m, int a);
int validarHora(int h, int min);
char *lerStringDinamica(void);

TJogador *cadastrarJogadores(int qnt_jogadores, int qnt_partidas);
TPartida *cadastrarPartidas(int qnt_partidas);
void registrarEstatisticas(TJogador *jogadores, int qnt_jogadores, TPartida *partidas, int qnt_partidas);
void imprimirRelatorio(TJogador *jogadores, int qnt_jogadores, TPartida *partidas, int qnt_partidas);

/* implementacoes */

int validarData(int d, int m, int a) {
    if (a < 1900 || a > 3000) return 0;
    if (m < 1 || m > 12) return 0;
    if (d < 1) return 0;
    int bissexto = (a % 400 == 0) || (a % 4 == 0 && a % 100 != 0);
    if (m == 2) return (d <= (bissexto ? 29 : 28));
    if (m==4||m==6||m==9||m==11) return (d <= 30);
    return (d <= 31);
}

int validarHora(int h, int min) {
    if (h < 0 || h > 23) return 0;
    if (min < 0 || min > 59) return 0;
    return 1;
}

/* Le uma linha inteira do stdin e retorna uma copia alocada dinamicamente.
   O caller deve dar free depois. */
char *lerStringDinamica(void) {
    char buffer[512];
    /* usa " " no scanf para pular espacos inicias e %511[^
] para ler ate newline */
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        /* erro ou EOF */
        buffer[0] = '\0';
    }
    /* remove eventual \n no final */
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') buffer[len-1] = '\0';
    /* aloca e copia */
    char *s = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    if (!s) { printf("Erro malloc\n"); exit(1); }
    strcpy(s, buffer);
    return s;
}

TJogador *cadastrarJogadores(int qnt_jogadores, int qnt_partidas) {
    int i, j;
    TJogador *vet = (TJogador *)malloc(qnt_jogadores * sizeof(TJogador));
    if (!vet) { printf("Erro alocar jogadores\n"); exit(1); }

    for (i = 0; i < qnt_jogadores; i++) {
        printf("\n--- Cadastro do jogador %d de %d ---\n", i+1, qnt_jogadores);
        printf("Nome: ");
        /* limpar buffer antes */
        fflush(stdin);
        vet[i].nome_jogador = NULL;
        vet[i].nome_jogador = lerStringDinamica();

        /* Data de nascimento */
        while (1) {
            printf("Data de nascimento (DD MM AAAA): ");
            int d,m,a;
            if (scanf("%d %d %d", &d, &m, &a) != 3) {
                printf("Entrada invalida. Tente novamente.\n");
                while (getchar() != '\n');
                continue;
            }
            while (getchar() != '\n');
            if (!validarData(d,m,a)) {
                printf("Data invalida. Tente novamente.\n");
                continue;
            }
            vet[i].data_nascimento.dia = d;
            vet[i].data_nascimento.mes = m;
            vet[i].data_nascimento.ano = a;
            break;
        }

        /* Turma */
        printf("Nome do curso: ");
        vet[i].turma.nome_curso = lerStringDinamica();
        printf("Ano do curso (numero inteiro): ");
        if (scanf("%d", &vet[i].turma.ano_curso) != 1) { vet[i].turma.ano_curso = 0; }
        while (getchar() != '\n');
        printf("Nickname: ");
        vet[i].turma.nickname = lerStringDinamica();

        /* Numero da camisa */
        printf("Numero da camisa: ");
        if (scanf("%d", &vet[i].n_camisa) != 1) vet[i].n_camisa = 0;
        while (getchar() != '\n');

        /* rankingTop14 */
        printf("RankingTop14 (0 para nao, 1 para sim): ");
        if (scanf("%d", &vet[i].rankingTop14) != 1) vet[i].rankingTop14 = 0;
        while (getchar() != '\n');

        /* aloca vetor de estatisticas com qnt_partidas entries e inicializa */
        vet[i].qnt_partidas = qnt_partidas;
        vet[i].estatisticas = (TIndividual *)malloc(qnt_partidas * sizeof(TIndividual));
        if (!vet[i].estatisticas) { printf("Erro alocar estatisticas\n"); exit(1); }
        for (j = 0; j < qnt_partidas; j++) {
            vet[i].estatisticas[j].minutos_jogados = 0;
            vet[i].estatisticas[j].gols = 0;
            vet[i].estatisticas[j].assistencias = 0;
            vet[i].estatisticas[j].faltas = 0;
            vet[i].estatisticas[j].c_amarelos = 0;
            vet[i].estatisticas[j].c_vermelhos = 0;
            vet[i].estatisticas[j].cod_partida = -1; /* inicial */
        }
    }
    return vet;
}

/* cadastra partidas; retorna vetor alocado */
TPartida *cadastrarPartidas(int qnt_partidas) {
    int k;
    TPartida *vet = (TPartida *)malloc(qnt_partidas * sizeof(TPartida));
    if (!vet) { printf("Erro alocar partidas\n"); exit(1); }

    for (k = 0; k < qnt_partidas; k++) {
        printf("\n--- Cadastro da partida %d de %d ---\n", k+1, qnt_partidas);
        printf("Codigo unico (inteiro): ");
        if (scanf("%d", &vet[k].codigo) != 1) vet[k].codigo = k+1;
        while (getchar() != '\n');

        while (1) {
            printf("Data da partida (DD MM AAAA): ");
            int d,m,a;
            if (scanf("%d %d %d", &d, &m, &a) != 3) {
                printf("Entrada invalida. Tente novamente.\n");
                while (getchar() != '\n');
                continue;
            }
            while (getchar() != '\n');
            if (!validarData(d,m,a)) { printf("Data invalida.\n"); continue; }
            vet[k].data_partida.dia = d; vet[k].data_partida.mes = m; vet[k].data_partida.ano = a;
            break;
        }

        while (1) {
            printf("Horario (HH MM): ");
            int h,min;
            if (scanf("%d %d", &h, &min) != 2) { printf("Entrada invalida.\n"); while(getchar()!='\n'); continue; }
            while (getchar()!='\n');
            if (!validarHora(h,min)) { printf("Hora invalida.\n"); continue; }
            vet[k].horario_partida.hora = h; vet[k].horario_partida.minuto = min;
            break;
        }

        printf("Local: ");
        vet[k].local = NULL;
        vet[k].local = lerStringDinamica();

        printf("Adversario: ");
        vet[k].adversario = lerStringDinamica();

        printf("Responsavel por incidentes (nome): ");
        vet[k].responsavel = lerStringDinamica();
    }
    return vet;
}

void registrarEstatisticas(TJogador *jogadores, int qnt_jogadores, TPartida *partidas, int qnt_partidas) {
    int k,i;
    for (k = 0; k < qnt_partidas; k++) {
        printf("\n--- Estatisticas - Partida %d (codigo %d) ---\n", k+1, partidas[k].codigo);
        for (i = 0; i < qnt_jogadores; i++) {
            printf("\nJogador: %s (camisa %d)\n", jogadores[i].nome_jogador, jogadores[i].n_camisa);
            jogadores[i].estatisticas[k].cod_partida = partidas[k].codigo;

            printf("Minutos jogados: "); if (scanf("%d", &jogadores[i].estatisticas[k].minutos_jogados) != 1) jogadores[i].estatisticas[k].minutos_jogados = 0; while(getchar()!='\n');
            printf("Gols: "); if (scanf("%d", &jogadores[i].estatisticas[k].gols) != 1) jogadores[i].estatisticas[k].gols = 0; while(getchar()!='\n');
            printf("Assistencias: "); if (scanf("%d", &jogadores[i].estatisticas[k].assistencias) != 1) jogadores[i].estatisticas[k].assistencias = 0; while(getchar()!='\n');
            printf("Faltas: "); if (scanf("%d", &jogadores[i].estatisticas[k].faltas) != 1) jogadores[i].estatisticas[k].faltas = 0; while(getchar()!='\n');

            do {
                printf("Cartoes amarelos (0-2): ");
                if (scanf("%d", &jogadores[i].estatisticas[k].c_amarelos) != 1) jogadores[i].estatisticas[k].c_amarelos = 0;
                while(getchar()!='\n');
                if (jogadores[i].estatisticas[k].c_amarelos < 0 || jogadores[i].estatisticas[k].c_amarelos > 2) printf("Valor invalido!\n");
            } while(jogadores[i].estatisticas[k].c_amarelos < 0 || jogadores[i].estatisticas[k].c_amarelos > 2);

            do {
                printf("Cartoes vermelhos (0-1): ");
                if (scanf("%d", &jogadores[i].estatisticas[k].c_vermelhos) != 1) jogadores[i].estatisticas[k].c_vermelhos = 0;
                while(getchar()!='\n');
                if (jogadores[i].estatisticas[k].c_vermelhos < 0 || jogadores[i].estatisticas[k].c_vermelhos > 1) printf("Valor invalido!\n");
            } while(jogadores[i].estatisticas[k].c_vermelhos < 0 || jogadores[i].estatisticas[k].c_vermelhos > 1);
        }
    }
}

void imprimirRelatorio(TJogador *jogadores, int qnt_jogadores, TPartida *partidas, int qnt_partidas) {
    int i,j;
    printf("\n\n********** RELATORIO FINAL **********\n");
    for (i = 0; i < qnt_jogadores; i++) {
        printf("\nJOGADOR %d: %s\n", i+1, jogadores[i].nome_jogador);
        printf("Data de nascimento: %02d/%02d/%04d\n", jogadores[i].data_nascimento.dia, jogadores[i].data_nascimento.mes, jogadores[i].data_nascimento.ano);
        printf("Curso: %s - %d ano\n", jogadores[i].turma.nome_curso, jogadores[i].turma.ano_curso);
        printf("Nickname: %s\n", jogadores[i].turma.nickname);
        printf("Numero da camisa: %d\n", jogadores[i].n_camisa);
        printf("RankingTop14: %s\n", jogadores[i].rankingTop14 ? "SIM" : "NAO");

        for (j = 0; j < qnt_partidas; j++) {
            printf("\n  PARTIDA %d (codigo %d):\n", j+1, partidas[j].codigo);
            printf("    Data: %02d/%02d/%04d  Hora: %02d:%02d\n", partidas[j].data_partida.dia, partidas[j].data_partida.mes, partidas[j].data_partida.ano, partidas[j].horario_partida.hora, partidas[j].horario_partida.minuto);
            printf("    Local: %s\n", partidas[j].local);
            printf("    Adversario: %s\n", partidas[j].adversario);
            printf("    Responsavel: %s\n", partidas[j].responsavel);

            printf("    Estatisticas do jogador nesta partida:\n");
            printf("      Minutos jogados: %d\n", jogadores[i].estatisticas[j].minutos_jogados);
            printf("      Gols: %d\n", jogadores[i].estatisticas[j].gols);
            printf("      Assistencias: %d\n", jogadores[i].estatisticas[j].assistencias);
            printf("      Faltas: %d\n", jogadores[i].estatisticas[j].faltas);
            printf("      Cartoes amarelos: %d\n", jogadores[i].estatisticas[j].c_amarelos);
            printf("      Cartoes vermelhos: %d\n", jogadores[i].estatisticas[j].c_vermelhos);
        }
    }
}

/* main: fluxo principal que usa as funcoes */
int main(void) {
    int qnt_jogadores = 0, qnt_partidas = 0;
    printf("Sistema Esquadra Futsal - Cadastro e Relatorio\n");

    while (1) {
        printf("\nDigite o numero de jogadores a cadastrar: ");
        if (scanf("%d", &qnt_jogadores) != 1) { printf("Entrada invalida\n"); while(getchar()!='\n'); continue; }
        while(getchar()!='\n');
        if (qnt_jogadores > 0) break; else printf("Valor deve ser maior que 0\n");
    }

    while (1) {
        printf("Digite a quantidade de partidas: ");
        if (scanf("%d", &qnt_partidas) != 1) { printf("Entrada invalida\n"); while(getchar()!='\n'); continue; }
        while(getchar()!='\n');
        if (qnt_partidas > 0) break; else printf("Valor deve ser maior que 0\n");
    }

    TJogador *jogadores = cadastrarJogadores(qnt_jogadores, qnt_partidas);
    TPartida *partidas = cadastrarPartidas(qnt_partidas);
    registrarEstatisticas(jogadores, qnt_jogadores, partidas, qnt_partidas);
    imprimirRelatorio(jogadores, qnt_jogadores, partidas, qnt_partidas);

    /* liberar memoria */
    int i, j;
    for (i = 0; i < qnt_jogadores; i++) {
        free(jogadores[i].nome_jogador);
        free(jogadores[i].turma.nome_curso);
        free(jogadores[i].turma.nickname);
        free(jogadores[i].estatisticas);
    }
    free(jogadores);

    for (j = 0; j < qnt_partidas; j++) {
        free(partidas[j].local);
        free(partidas[j].adversario);
        free(partidas[j].responsavel);
    }
    free(partidas);

    return 0;
}
