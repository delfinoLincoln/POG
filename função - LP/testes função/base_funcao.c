#include<stdio.h>           //biblioteca para funções de entrada e saida
#include<stdlib.h>          //biblioteca responsável pela manipulação de alocação/desalocação de memoria
#include<string.h>          //biblioteca de  string()
#include<ctype.h>           //biblioteca para manipulação de caracteres
#include<stdbool.h>         //biblioteca true/false
#include<windows.h>         //biblioteca para interação com SO windows
#include<unistd.h>          //biblioteca para interação com SO unix 
#include<conio.h>           //biblioteca de manipulação do console(entrada e saida)

/*  declaração dos macros  */
#define CLS (_WIN32 ? system("cls") : system("clear"));
#define SPAUSE                                              \
    printf("Pressione qualquer tecla para continuar. . ."); \
    getch(); // pausa o programa

/*<declaração das estruturas>*/
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
    TData data_partida;
    THora hora_partida;
    int codigo_partida;
    char *local_partida;
    char *adversario;
}TPartida;

typedef struct 
{
    char *nome_curso;
    int ano_curso;
}TCurso;


typedef struct
{
    char *nome_jogador;
    TData data_nascimento;
    int numero_camisa;
    int rank_top14;
    TCurso turma;
}TJogador;

typedef struct
{
    int minutos_jogados;
    int gols;
    int assistencias;
    int faltas;
    int cartoes_amarelos;
    int cartoes_vermelhos;
}THistorico;

/* <declaração das funções> */
void menu();                    //imprime as opções do menu
void opcaoMenu(int opcao);      //solicita ao usuário que escolha uma opção
void mostrarTitulo(char *str);  //imprime uma mensagem de inicio
void apagarTitulo(int len);     //apaga a mensagem de inicio
void cadastrarJogadores();      //função responsável por cadastrar jogadores
void cadastrarPartidas();
void listarPartidas();
void listarJogadores();
void validarData();
void validarHora();
void validarCartoes();
void validarEstatisticas();

#define TEMP 100                //tempo(milissegundos) necessários para imprimir e apagar titulo;
#define maxJogadores 50

int NumPartidas = 0;
int numJogadores = 0;

int main()
{
    mostrarTitulo("=== BEM VINDO AO SISTEMA ESQUADRA FUTSAL ===");
    apagarTitulo(strlen("=== BEM VINDO AO SISTEMA ESQUADRA FUTSAL ===\n"));
    int opcao = 1;
    while(opcao != 0)
    {
    menu();
    scanf("%d",&opcao);
    fflush(stdin);
    CLS
    opcaoMenu(opcao);
    }
}
void mostrarTitulo(char *str)
{
    for(int i = 0; str[i] != '\0'; i++){
        printf("%c", str[i]);
        Sleep(TEMP);
    }
}
void apagarTitulo(int len)
{
    for(int i = 0; i < len; i++){
        printf("\b \b");
        Sleep(TEMP);
    }
}

void menu()
{

        printf("\n======MENU======\n");
        printf("(1) - CADASTRAR PARTIDA\n");
        printf("(2) - CADASTRAR JOGADOR\n");
        printf("(3) - LISTAR PARTIDAS\n");
        printf("(4) - LISTAR JOGADORES\n");
        printf("(0) - SAIR\n");
        printf("** Escolha uma opcao: \n");
}
void opcaoMenu(int opcao)
{
    TJogador *jogadores = NULL;
    TPartida *partidas = NULL;
    int qtd_partidas = 0;
    int qtd_jogadores = 0;
    switch(opcao)
    {
        case 1:
            cadastrarPartidas(jogadores, qtd_partidas);
            break;

        case 2: 
            cadastrarJogadores(partidas, qtd_partidas);
            break;

        case 3:
            listarPartidas(partidas, qtd_partidas);
            break;
        
        case 4:
            listarJogadores(jogadores, qtd_jogadores);
            break;

        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("opcao invalida!\n");
            break;
    }
    SPAUSE
}
void cadastrarJogadores()
{
    
}
void cadastrarPartidas();
void listarPartidas();
void listarJogadores();
void validarData();
void validarHora();
void validarCartoes();
void validarEstatisticas();
