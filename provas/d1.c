#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} TData;

typedef struct {
    int codigo;
    TData data;
    char *local;
    char *adversario;
} TPartida;

typedef struct {
    char *nome_curso;
    int ano_curso;
    char *nickname;
} TTurma;

typedef struct {
    int gols;
    int assistencias;
    int faltas;
    int c_amarelos;
    int c_vermelhos;
    int minutos_jogados;
    TPartida partida;
} TEstatistica;

typedef struct {
    char *nome;
    TData data_nascimento;
    TTurma turma;
    int n_camisa;
    int ranking;
    int qtd_partidas;
    TEstatistica *estatisticas;
} TJogador;

int main() {
    TJogador *jogadores = NULL;
    int qnt_jogador, qnt_partidas;
    char strAux[1000];
    int i, j, k;
    int codigo_valido;

    printf("Digite o numero de jogadores: ");
    scanf("%d", &qnt_jogador);
    fflush(stdin);

    printf("Digite o numero de partidas: ");
    scanf("%d", &qnt_partidas);
    fflush;

    // Alocar memoria para os jogadores
    jogadores = (TJogador*)malloc(qnt_jogador * sizeof(TJogador));
    if (jogadores == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }

    // Cadastrar jogadores
    for(i = 0; i < qnt_jogador; i++) {
        printf("nome do jogador %d: ", i + 1);
        gets(strAux);
        jogadores[i].nome = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(jogadores[i].nome, strAux);

        printf("data de nascimento do jogador %d: ", i + 1);
        scanf("%d %d %d", &jogadores[i].data_nascimento.dia, 
                          &jogadores[i].data_nascimento.mes, 
                          &jogadores[i].data_nascimento.ano);
        fflush(stdin);

        printf("qual o curso do jogador %d? ", i + 1);
        gets(strAux);
        jogadores[i].turma.nome_curso = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(jogadores[i].turma.nome_curso, strAux);

        printf("Ano do curso: ");
        scanf("%d", &jogadores[i].turma.ano_curso);
        getchar();

        printf("Digite o nickname do jogador %d ", i + 1);
        gets(strAux);
        jogadores[i].turma.nickname = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(jogadores[i].turma.nickname, strAux);

        printf("Digite o numero da camisa do jogador %d: ", i + 1);
        scanf("%d", &jogadores[i].n_camisa);
        fflush(stdin);

        printf("Diga uma posicao para o jogador %d no ranking: ", i + 1);
        scanf("%d", &jogadores[i].ranking);
        fflush(stdin);

        jogadores[i].qtd_partidas = qnt_partidas;
        jogadores[i].estatisticas = (TEstatistica*)malloc(qnt_partidas * sizeof(TEstatistica));
    }

    for(j = 0; j < qnt_partidas; j++)
    {
        printf("partida %d\n", j + 1);
        
        // Validar codigo unico
        do {
            codigo_valido = 1;
            printf("Codigo da partida: ");
            scanf("%d", &jogadores[0].estatisticas[j].partida.codigo);
            getchar();

            // Verificar se o codigo ja existe
            for(k = 0; k < j; k++) {
                if (jogadores[0].estatisticas[j].partida.codigo == jogadores[0].estatisticas[k].partida.codigo) {
                    printf("ERRO: Codigo ja existe! Digite um codigo unico.\n");
                    codigo_valido = 0;
                    break;
                }
            }
        } while (!codigo_valido);

        printf("digite a data da partida %d: ", j + 1);
        scanf("%d %d %d", &jogadores[0].estatisticas[j].partida.data.dia, 
                          &jogadores[0].estatisticas[j].partida.data.mes, 
                          &jogadores[0].estatisticas[j].partida.data.ano);
        getchar();

        printf("Local: ");
        gets(strAux);
        jogadores[0].estatisticas[j].partida.local = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(jogadores[0].estatisticas[j].partida.local, strAux);

        printf("Adversario: ");
        gets(strAux);
        jogadores[0].estatisticas[j].partida.adversario = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(jogadores[0].estatisticas[j].partida.adversario, strAux);

        // Copiar dados da partida para todos os jogadores
        for(i = 1; i < qnt_jogador; i++) {
            jogadores[i].estatisticas[j].partida.codigo = jogadores[0].estatisticas[j].partida.codigo;
            jogadores[i].estatisticas[j].partida.data = jogadores[0].estatisticas[j].partida.data;
            
            jogadores[i].estatisticas[j].partida.local = (char*)malloc((strlen(jogadores[0].estatisticas[j].partida.local) + 1) * sizeof(char));
            strcpy(jogadores[i].estatisticas[j].partida.local, jogadores[0].estatisticas[j].partida.local);
            
            jogadores[i].estatisticas[j].partida.adversario = (char*)malloc((strlen(jogadores[0].estatisticas[j].partida.adversario) + 1) * sizeof(char));
            strcpy(jogadores[i].estatisticas[j].partida.adversario, jogadores[0].estatisticas[j].partida.adversario);
        }

        // Cadastrar estatisticas por jogador
        for(i = 0; i < qnt_jogador; i++) {
            printf("\n=== ESTATISTICAS - %s (Partida %d) ===\n", jogadores[i].nome, j + 1);
            
            printf("Minutos jogados: ");
            scanf("%d", &jogadores[i].estatisticas[j].minutos_jogados);
            getchar();

            printf("Gols: ");
            scanf("%d", &jogadores[i].estatisticas[j].gols);
            getchar();

            printf("Assistencias: ");
            scanf("%d", &jogadores[i].estatisticas[j].assistencias);
            getchar();

            printf("Faltas: ");
            scanf("%d", &jogadores[i].estatisticas[j].faltas);
            getchar();

            // Validar cartoes amarelos (maximo 2 por partida)
            do {
                printf("Cartoes amarelos (max 2): ");
                scanf("%d", &jogadores[i].estatisticas[j].c_amarelos);
                getchar();
                
                if(jogadores[i].estatisticas[j].c_amarelos > 2) {
                    printf("ERRO: Um jogador nao pode ter mais de 2 cartoes amarelos por partida!\n");
                }
            } while(jogadores[i].estatisticas[j].c_amarelos > 2);

            // Validar cartoes vermelhos (maximo 1 por partida)
            do {
                printf("Cartoes vermelhos (max 1): ");
                scanf("%d", &jogadores[i].estatisticas[j].c_vermelhos);
                getchar();
                
                if(jogadores[i].estatisticas[j].c_vermelhos > 1) {
                    printf("ERRO: Um jogador nao pode ter mais de 1 cartao vermelho por partida!\n");
                }
            } while(jogadores[i].estatisticas[j].c_vermelhos > 1);
        }
    }

    // Mostrar relatorio
    printf("\n\n=== RELATORIO COMPLETO - ESQUADRA FUTSAL ===\n");
    for(i = 0; i < qnt_jogador; i++) {
        printf("\n=== JOGADOR %d: %s ===\n", i + 1, jogadores[i].nome);
        printf("Data de nascimento: %02d/%02d/%04d\n", 
               jogadores[i].data_nascimento.dia,
               jogadores[i].data_nascimento.mes,
               jogadores[i].data_nascimento.ano);
        printf("Curso: %s - %d ano\n", jogadores[i].turma.nome_curso, jogadores[i].turma.ano_curso);
        printf("Nickname: %s\n", jogadores[i].turma.nickname);
        printf("Numero da camisa: %d\n", jogadores[i].n_camisa);
        printf("Ranking: %d\n", jogadores[i].ranking);
        
        for(j = 0; j < qnt_partidas; j++) {
            printf("\n--- PARTIDA %d ---\n", j + 1);
            printf("Codigo: %d\n", jogadores[i].estatisticas[j].partida.codigo);
            printf("Data: %02d/%02d/%04d\n", 
                   jogadores[i].estatisticas[j].partida.data.dia,
                   jogadores[i].estatisticas[j].partida.data.mes,
                   jogadores[i].estatisticas[j].partida.data.ano);
            printf("Local: %s\n", jogadores[i].estatisticas[j].partida.local);
            printf("Adversario: %s\n", jogadores[i].estatisticas[j].partida.adversario);
            
            printf("Estatisticas:\n");
            printf("  Minutos jogados: %d\n", jogadores[i].estatisticas[j].minutos_jogados);
            printf("  Gols: %d\n", jogadores[i].estatisticas[j].gols);
            printf("  Assistencias: %d\n", jogadores[i].estatisticas[j].assistencias);
            printf("  Faltas: %d\n", jogadores[i].estatisticas[j].faltas);
            printf("  Cartoes amarelos: %d\n", jogadores[i].estatisticas[j].c_amarelos);
            printf("  Cartoes vermelhos: %d\n", jogadores[i].estatisticas[j].c_vermelhos);
        }
        printf("------------------------\n");
    }

    // Liberar memoria
    for(i = 0; i < qnt_jogador; i++) {
        free(jogadores[i].nome);
        free(jogadores[i].turma.nome_curso);
        free(jogadores[i].turma.nickname);
        
        for(j = 0; j < qnt_partidas; j++) {
            free(jogadores[i].estatisticas[j].partida.local);
            free(jogadores[i].estatisticas[j].partida.adversario);
        }
        free(jogadores[i].estatisticas);
    }
    free(jogadores);

    return 0;
}