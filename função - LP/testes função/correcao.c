#include<stdio.h>           //biblioteca para funções de entrada e saida
#include<stdlib.h>          //biblioteca responsável pela manipulação de alocação/desalocação de memoria
#include<string.h>          //biblioteca de  string()
#include<ctype.h>           //biblioteca para manipulação de caracteres
#include<stdbool.h>         //biblioteca true/false
#include<windows.h>         //biblioteca para interação com SO windows
#include<unistd.h>          //biblioteca para interação com SO unix 
#include<conio.h>           //biblioteca de manipulação do console(entrada e saida)

/* macros */
#define CLS (_WIN32 ? system("cls") : system ("clear"));        //limpa a tela em SOs windows e linux
#define SPAUSE                                              \
    printf("Pressione qualquer tecla para continuar. . ."); \
    getch(); // pausa o programa

/* structs */

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
}TCurso;

typedef struct {
    int minutos_jogados;
    int gols;
    int assistencias;
    int faltas;
    int cartoes_amarelos;
    int cartoes_vermelhos;
} THistorico;

typedef struct {
    char *nome_jogador;
    TData data_nascimento;
    int numero_camisa;
    int rank_top14;
    TCurso turma;
    THistorico historico;
} TJogador;

typedef struct {
    TData data_partida;
    THora hora_partida;
    TJogador *jogadores;
    int qtd_jogadores;
    int codigo_partida;
    char *local_partida;
    char *adversario;
} TPartida;

/* funções */
void menu();
void opcaoMenu(int opcao);
void mostrarTitulo(char *str);
void apagarTitulo(int len);
void cadastrarJogador(TJogador **jogadores, int *qtd_jogadores);
void incluirPartidas(TJogador **jogadores, TPartida **partidas, int *qtd_jogadores, int *qtd_partidas);
void listarJogadores(TJogador *jogadores, int *qtd_jogadores);
void listarPartidas(TPartida *partidas, int *qtd_partidas);

#define TEMP 100
#define maxJogadores 50

int main() 
{
    CLS
    mostrarTitulo("=== BEM VINDO AO SISTEMA ESQUADRA FUTSAL ===");
    apagarTitulo(strlen("=== BEM VINDO AO SISTEMA ESQUADRA FUTSAL ===\n"));
    int opcao = 1;

    do {
        menu();
        scanf("%d",&opcao);
        fflush(stdin);
        CLS;
        opcaoMenu(opcao);
    } while(opcao != 0); // corrigido para sair com 0
}

void mostrarTitulo(char *str) {
    for(int i = 0; str[i] != '\0'; i++){
        printf("%c", str[i]);
        Sleep(TEMP);
    }
}
void apagarTitulo(int len) {
    for(int i = 0; i < len; i++){
        printf("\b \b");
        Sleep(TEMP);
    }
}
void menu() {
    printf("======MENU======\n\n");
    printf("(1) - CADASTRAR PARTIDA\n");
    printf("(2) - CADASTRAR JOGADOR\n");
    printf("(3) - LISTAR PARTIDAS\n");
    printf("(4) - LISTAR JOGADORES\n");
    printf("(0) - SAIR\n");
    printf("** Escolha uma opcao: \n");
}

void opcaoMenu(int opcao) {
    TJogador *jogadores = NULL;
    TPartida *partidas = NULL;
    int qtd_partidas = 0;
    int qtd_jogadores = 0;

    switch(opcao) {
        case 1:
            incluirPartidas(&jogadores, &partidas, &qtd_jogadores, &qtd_partidas);
            break;
        case 2: 
            cadastrarJogador(&jogadores, &qtd_jogadores);
            break;
        case 3:
            listarPartidas(partidas, &qtd_partidas);
            break;
        case 4:
            listarJogadores(jogadores, &qtd_jogadores);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("opcao invalida!\n");
            break;
    }
    if(opcao != 0) 
    SPAUSE
}


void cadastrarJogador(TJogador **jogadores, int *qtd_jogadores) {
    while(1)
    {
        if(*qtd_jogadores == 0){
            *jogadores = (TJogador*)malloc(1 * sizeof(TJogador));
        } else{
            *jogadores = (TJogador*)realloc(*jogadores, (*qtd_jogadores + 1) * sizeof(TJogador));
        }

        char strAux[100];

        CLS
        printf("Nome do jogador: ");
        gets(strAux);
        (*jogadores)[*qtd_jogadores].nome_jogador = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy((*jogadores)[*qtd_jogadores].nome_jogador, strAux);

        printf("Data de nascimento (DD MM AAAA): ");
        scanf("%d%d%d", &(*jogadores)[*qtd_jogadores].data_nascimento.dia, &(*jogadores)[*qtd_jogadores].data_nascimento.mes, &(*jogadores)[*qtd_jogadores].data_nascimento.ano);
        fflush(stdin);

        bool check;
        do{
            check = true;
            printf("Numero da camisa: ");
            scanf("%d", &(*jogadores)[*qtd_jogadores].numero_camisa);
            fflush(stdin);

            for(int i = 0; i < *qtd_jogadores; i++){
                if((*jogadores)[i].numero_camisa == (*jogadores)[*qtd_jogadores].numero_camisa){
                    check = false;
                    printf("\n** Erro! Numero ja cadastrado! **\n\n");
                    break;
                }
            }
        } while(!check);

        printf("Rank: ");
        scanf("%d", &(*jogadores)[*qtd_jogadores].rank_top14);
        fflush(stdin);

        printf("\nNome do curso: ");
        gets(strAux);
        (*jogadores)[*qtd_jogadores].turma.nome_curso = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy((*jogadores)[*qtd_jogadores].turma.nome_curso, strAux);
    
        printf("Ano do curso: ");
        scanf("%d", &(*jogadores)[*qtd_jogadores].turma.ano_curso);
        fflush(stdin);
    
        printf("\nHistorico do jogador:\n");
    
        printf("- Minutos jogados: ");
        scanf("%d", &(*jogadores)[*qtd_jogadores].historico.minutos_jogados);
        fflush(stdin);
    
        printf("- Gols: ");
        scanf("%d", &(*jogadores)[*qtd_jogadores].historico.gols);
        fflush(stdin);
    
        printf("- Assistencias: ");
        scanf("%d", &(*jogadores)[*qtd_jogadores].historico.assistencias);
        fflush(stdin);
    
        printf("- Faltas: ");
        scanf("%d", &(*jogadores)[*qtd_jogadores].historico.faltas);
        fflush(stdin);
    
        do{
            printf("- Cartoes amarelos: ");
            scanf("%d", &(*jogadores)[*qtd_jogadores].historico.cartoes_amarelos);
            fflush(stdin);

            if((*jogadores)[*qtd_jogadores].historico.cartoes_amarelos < 0 || (*jogadores)[*qtd_jogadores].historico.cartoes_amarelos > 2){
                printf("\n** Erro! Numero invalido! **\n\n");
            }
        } while((*jogadores)[*qtd_jogadores].historico.cartoes_amarelos < 0 || (*jogadores)[*qtd_jogadores].historico.cartoes_amarelos > 2);

        if((*jogadores)[*qtd_jogadores].historico.cartoes_amarelos == 2)
        {
            (*jogadores)[*qtd_jogadores].historico.cartoes_vermelhos = 1;
            printf("o jogador recebeu um vermelho pelos 2 amarelos!\n");
            SPAUSE
        } else
        {
            do{
                printf("- Cartoes vermelhos: ");
                scanf("%d", &(*jogadores)[*qtd_jogadores].historico.cartoes_vermelhos);
                fflush(stdin);

                if((*jogadores)[*qtd_jogadores].historico.cartoes_vermelhos < 0 || (*jogadores)[*qtd_jogadores].historico.cartoes_vermelhos > 1){
                    printf("\n** Erro! Numero invalido! **\n\n");
                }
            } while((*jogadores)[*qtd_jogadores].historico.cartoes_vermelhos < 0 || (*jogadores)[*qtd_jogadores].historico.cartoes_vermelhos > 1);
        }

        (*qtd_jogadores)++;

        CLS
        printf("Jogador cadastrado com sucesso!!!\n\n");
        SPAUSE

        char opSn;
        do{
            system("cls");
            printf("** Deseja cadastrar mais um jogador (S/N)? ");
            scanf("%c", &opSn);
            fflush(stdin);
    
            opSn = tolower(opSn);
            if (opSn != 's' && opSn != 'n'){
                printf("**Erro! Opcao inexistente!**\n\n");
            }
        } while (opSn != 's' && opSn != 'n');

        if(opSn == 'n'){
            break;
        }
    }
}

void incluirPartidas(TJogador **jogadores, TPartida **partidas, int *qtd_jogadores, int *qtd_partidas){
    if(*qtd_partidas == 0){
        *partidas = (TPartida*)malloc(1 * sizeof(TPartida));
    } else{
        *partidas = (TPartida*)realloc(*partidas, (*qtd_partidas + 1) * sizeof(TPartida));
    }

    char strAux[100];

    system("cls");
    printf("Data da partida (DD MM AAAA): ");
    scanf("%d%d%d", &(*partidas)[*qtd_partidas].data_partida.dia, &(*partidas)[*qtd_partidas].data_partida.mes, &(*partidas)[*qtd_partidas].data_partida.ano);
    fflush(stdin);

    printf("Hora da partida (HH MM): ");
    scanf("%d%d", &(*partidas)[*qtd_partidas].hora_partida.hora, &(*partidas)[*qtd_partidas].hora_partida.minuto);
    fflush(stdin);

    printf("Local da partida: ");
    gets(strAux);
    (*partidas)[*qtd_partidas].local_partida = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy((*partidas)[*qtd_partidas].local_partida, strAux);

    printf("Adversario: ");
    gets(strAux);
    (*partidas)[*qtd_partidas].adversario = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy((*partidas)[*qtd_partidas].adversario, strAux);

    (*partidas)[*qtd_partidas].qtd_jogadores = 0;

    if(*qtd_jogadores == 0){
        printf("\nNao ha jogadores cadastrados!\n");
        printf("Voce sera redirecionado para cadastrar um jogador.");
        system("pause");

        cadastrarJogador(jogadores, qtd_jogadores);
    }

    if(*qtd_jogadores < 7){
        do{
            printf("\nNao ha jogadores suficientes cadastrados!\n");
            printf("Voce sera redirecionado para cadastrar mais jogadores.");
            system("pause");
    
            cadastrarJogador(jogadores, qtd_jogadores);
        } while(*qtd_jogadores < 7);
        
    } else if(*qtd_jogadores > 7){
        (*partidas)[*qtd_partidas].jogadores = (TJogador*)malloc(14 * sizeof(TJogador));

        int numJogador;
        char opSn = 's';

        while((*partidas)[*qtd_partidas].qtd_jogadores < 14 && opSn == 's'){
            bool check;
            do{
                check = true;
                listarJogadores(*jogadores, qtd_jogadores);
    
                printf("Qual jogador deseja selecionar para a partida (1-%d)? ", *qtd_jogadores);
                scanf("%d", &numJogador);
                fflush(stdin);
                numJogador--;
    
                for(int i = 0; i < (*partidas)[*qtd_partidas].qtd_jogadores; i++){
                    if((*partidas)[*qtd_partidas].jogadores[i].numero_camisa == (*jogadores)[numJogador].numero_camisa){
                        check = false;
                        printf("\n** Erro! Jogador ja selecionado! **\n\n");
                        break;
                    }
                }
            } while(!check);

            if(numJogador < 0 || numJogador >= *qtd_jogadores){
                printf("**ERRO! Numero invalido!**\n");
            } else{
                (*partidas)[*qtd_partidas].jogadores[(*partidas)[*qtd_partidas].qtd_jogadores] = (*jogadores)[numJogador];
                (*partidas)[*qtd_partidas].qtd_jogadores++;
            }

            if((*partidas)[*qtd_partidas].qtd_jogadores >= 7){
                printf("** Deseja adicionar mais um jogador (S/N)? ");
                scanf("%c", &opSn);
                fflush(stdin);

                opSn = tolower(opSn);
                if (opSn != 's' && opSn != 'n'){
                    printf("**Erro! Opcao inexistente!**\n\n");
                    opSn = 'n';
                }
            }
        }
    } else{
        (*partidas)[*qtd_partidas].jogadores = (*jogadores);
    }

    (*qtd_partidas)++;

    CLS
    printf("Partida cadastrada com sucesso!!!\n\n");
    SPAUSE
}

void listarPartidas(TPartida *partidas, int *qtd_partidas){
    if(*qtd_partidas == 0){
        printf("Nao ha partidas cadastradas!\n");
        SPAUSE
        return;
    }

    CLS
    for(int i = 0; i < *qtd_partidas; i++){
        printf("\n*** Partida [%d] ***\n", i + 1);

        printf("Data da partida: %02d/%02d/%04d\n", partidas[i].data_partida.dia, partidas[i].data_partida.mes, partidas[i].data_partida.ano);
        printf("Hora da partida: %02d:%02d\n", partidas[i].hora_partida.hora, partidas[i].hora_partida.minuto);
        printf("Local da partida: %s\n", partidas[i].local_partida);
        printf("Adversario: %s\n\n", partidas[i].adversario);

        printf("Jogadores selecionados:\n");
        for(int j = 0; j < partidas[i].qtd_jogadores; j++){
            printf("- %s (Camisa %d)\n", partidas[i].jogadores[j].nome_jogador, partidas[i].jogadores[j].numero_camisa);
        }
    }
    printf("\n");
}

void listarJogadores(TJogador *jogadores, int *qtd_jogadores){
    if(*qtd_jogadores == 0)
    {
        printf("Nao ha jogadores cadastrados!\n");
        SPAUSE
        return;
    }

    CLS
    for(int i = 0; i < *qtd_jogadores; i++){
        printf("\n*** Jogador [%d] ***\n", i + 1);

        printf("Nome: %s\n", jogadores[i].nome_jogador);
        printf("Data de nascimento: %02d/%02d/%04d\n", jogadores[i].data_nascimento.dia, jogadores[i].data_nascimento.mes, jogadores[i].data_nascimento.ano);
        printf("Numero da camisa: %d\n", jogadores[i].numero_camisa);
        printf("Rank: %d\n\n", jogadores[i].rank_top14);

        printf("Curso: %s\n", jogadores[i].turma.nome_curso);
        printf("Ano do curso: %d\n\n", jogadores[i].turma.ano_curso);

        printf("Historico:\n");
        printf("- Minutos jogados: %d\n", jogadores[i].historico.minutos_jogados);
        printf("- Gols: %d\n", jogadores[i].historico.gols);
        printf("- Assistencias: %d\n", jogadores[i].historico.assistencias);
        printf("- Faltas: %d\n", jogadores[i].historico.faltas);
        printf("- Cartoes amarelos: %d\n", jogadores[i].historico.cartoes_amarelos);
        printf("- Cartoes vermelhos: %d\n", jogadores[i].historico.cartoes_vermelhos);
    }
    printf("\n");
}