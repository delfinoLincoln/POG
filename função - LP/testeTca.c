#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOME 100
#define MAX_HABILIDADE 50
#define MAX_JUTSUS 20
#define MAX_NINJAS 100
#define MAX_CLAS 50
#define MAX_JUTSUS_GERAL 100
#define MAX_MISSOES 50
#define MAX_PARTICIPANTES 10

// Enums para os tipos
typedef enum {
    ESTUDANTE, GENIN, CHUNIN, JOUNIN, KAGE, ANBU, TOKUBETSU_JOUNIN
} NivelHierarquico;

typedef enum {
    FOGO, AGUA, TERRA, VENTO, RAIO, COMPOSTO
} Elemento;

typedef enum {
    NINJUTSU, TAIJUTSU, GENJUTSU
} TipoJutsu;

typedef enum {
    D, C, B, A, S
} DificuldadeMissao;

typedef enum {
    PENDENTE, EM_ANDAMENTO, CONCLUIDA
} StatusMissao;

// Estrutura para Jutsu
typedef struct {
    char nome[MAX_NOME];
    TipoJutsu tipo;
    Elemento elemento;
    int custo_chakra;
    int poder_ataque;
} Jutsu;

// Estrutura para Clã
typedef struct {
    char nome[MAX_NOME];
    char habilidades[MAX_HABILIDADE];
    int eh_kekkei_genkai;
} Cla;

// Estrutura para Ninja
typedef struct {
    char nome[MAX_NOME];
    NivelHierarquico nivel;
    int chakra;
    Cla cla;
    Elemento afinidade_elemento;
    Elemento elementos_dominados[6];
    int num_elementos_dominados;
    Jutsu jutsus[MAX_JUTSUS];
    int num_jutsus;
} Ninja;

// Estrutura para Missão
typedef struct {
    char titulo[MAX_NOME];
    Ninja lider;
    DificuldadeMissao dificuldade;
    StatusMissao status;
    Ninja participantes[MAX_PARTICIPANTES];
    int num_participantes;
} Missao;

// Arrays globais para armazenamento
Ninja ninjas[MAX_NINJAS];
int num_ninjas = 0;

Cla clas[MAX_CLAS];
int num_clas = 0;

Jutsu jutsus_geral[MAX_JUTSUS_GERAL];
int num_jutsus_geral = 0;

Missao missoes[MAX_MISSOES];
int num_missoes = 0;

// Funções de conversão para strings
const char* nivel_para_string(NivelHierarquico nivel) {
    switch(nivel) {
        case ESTUDANTE: return "Estudante";
        case GENIN: return "Genin";
        case CHUNIN: return "Chunin";
        case JOUNIN: return "Jounin";
        case KAGE: return "Kage";
        case ANBU: return "ANBU";
        case TOKUBETSU_JOUNIN: return "Tokubetsu Jounin";
        default: return "Desconhecido";
    }
}

const char* elemento_para_string(Elemento elemento) {
    switch(elemento) {
        case FOGO: return "Fogo";
        case AGUA: return "Água";
        case TERRA: return "Terra";
        case VENTO: return "Vento";
        case RAIO: return "Raio";
        case COMPOSTO: return "Composto";
        default: return "Desconhecido";
    }
}

const char* tipo_jutsu_para_string(TipoJutsu tipo) {
    switch(tipo) {
        case NINJUTSU: return "Ninjutsu";
        case TAIJUTSU: return "Taijutsu";
        case GENJUTSU: return "Genjutsu";
        default: return "Desconhecido";
    }
}

const char* dificuldade_para_string(DificuldadeMissao dificuldade) {
    switch(dificuldade) {
        case D: return "D";
        case C: return "C";
        case B: return "B";
        case A: return "A";
        case S: return "S";
        default: return "Desconhecido";
    }
}

const char* status_para_string(StatusMissao status) {
    switch(status) {
        case PENDENTE: return "Pendente";
        case EM_ANDAMENTO: return "Em Andamento";
        case CONCLUIDA: return "Concluída";
        default: return "Desconhecido";
    }
}

// Funções de conversão de string para enum
NivelHierarquico string_para_nivel(const char* str) {
    if (strcmp(str, "Estudante") == 0) return ESTUDANTE;
    if (strcmp(str, "Genin") == 0) return GENIN;
    if (strcmp(str, "Chunin") == 0) return CHUNIN;
    if (strcmp(str, "Jounin") == 0) return JOUNIN;
    if (strcmp(str, "Kage") == 0) return KAGE;
    if (strcmp(str, "ANBU") == 0) return ANBU;
    if (strcmp(str, "Tokubetsu Jounin") == 0) return TOKUBETSU_JOUNIN;
    return ESTUDANTE;
}

Elemento string_para_elemento(const char* str) {
    if (strcmp(str, "Fogo") == 0) return FOGO;
    if (strcmp(str, "Água") == 0) return AGUA;
    if (strcmp(str, "Terra") == 0) return TERRA;
    if (strcmp(str, "Vento") == 0) return VENTO;
    if (strcmp(str, "Raio") == 0) return RAIO;
    if (strcmp(str, "Composto") == 0) return COMPOSTO;
    return FOGO;
}

// Funções CRUD para Ninjas
void criar_ninja() {
    if (num_ninjas >= MAX_NINJAS) {
        printf("Limite máximo de ninjas atingido!\n");
        return;
    }

    Ninja novo_ninja;
    
    printf("\n=== CRIAR NOVO NINJA ===\n");
    printf("Nome: ");
    scanf(" %[^\n]", novo_ninja.nome);
    
    printf("\nNíveis disponíveis:\n");
    printf("0 - Estudante\n1 - Genin\n2 - Chunin\n3 - Jounin\n4 - Kage\n5 - ANBU\n6 - Tokubetsu Jounin\n");
    printf("Nível: ");
    int nivel;
    scanf("%d", &nivel);
    novo_ninja.nivel = (NivelHierarquico)nivel;
    
    printf("Chakra (0-100): ");
    scanf("%d", &novo_ninja.chakra);
    
    printf("\nElementos disponíveis:\n");
    printf("0 - Fogo\n1 - Água\n2 - Terra\n3 - Vento\n4 - Raio\n5 - Composto\n");
    printf("Afinidade elemental: ");
    int elemento;
    scanf("%d", &elemento);
    novo_ninja.afinidade_elemento = (Elemento)elemento;
    
    printf("Nome do clã: ");
    scanf(" %[^\n]", novo_ninja.cla.nome);
    
    printf("Habilidades do clã: ");
    scanf(" %[^\n]", novo_ninja.cla.habilidades);
    
    printf("É Kekkei Genkai? (1-Sim, 0-Não): ");
    scanf("%d", &novo_ninja.cla.eh_kekkei_genkai);
    
    novo_ninja.num_jutsus = 0;
    novo_ninja.num_elementos_dominados = 1;
    novo_ninja.elementos_dominados[0] = novo_ninja.afinidade_elemento;
    
    ninjas[num_ninjas++] = novo_ninja;
    printf("Ninja criado com sucesso!\n");
}

void listar_ninjas() {
    printf("\n=== LISTA DE NINJAS ===\n");
    for (int i = 0; i < num_ninjas; i++) {
        printf("\n%d. %s\n", i+1, ninjas[i].nome);
        printf("   Nível: %s\n", nivel_para_string(ninjas[i].nivel));
        printf("   Chakra: %d\n", ninjas[i].chakra);
        printf("   Clã: %s\n", ninjas[i].cla.nome);
        printf("   Afinidade: %s\n", elemento_para_string(ninjas[i].afinidade_elemento));
        printf("   Jutsus conhecidos: %d\n", ninjas[i].num_jutsus);
    }
}

void atualizar_ninja() {
    listar_ninjas();
    
    if (num_ninjas == 0) return;
    
    int indice;
    printf("\nDigite o número do ninja para atualizar: ");
    scanf("%d", &indice);
    indice--;
    
    if (indice < 0 || indice >= num_ninjas) {
        printf("Índice inválido!\n");
        return;
    }
    
    printf("\n=== ATUALIZAR NINJA ===\n");
    printf("Nome atual: %s\nNovo nome: ", ninjas[indice].nome);
    scanf(" %[^\n]", ninjas[indice].nome);
    
    printf("Chakra atual: %d\nNovo chakra: ", ninjas[indice].chakra);
    scanf("%d", &ninjas[indice].chakra);
    
    printf("Ninja atualizado com sucesso!\n");
}

void excluir_ninja() {
    listar_ninjas();
    
    if (num_ninjas == 0) return;
    
    int indice;
    printf("\nDigite o número do ninja para excluir: ");
    scanf("%d", &indice);
    indice--;
    
    if (indice < 0 || indice >= num_ninjas) {
        printf("Índice inválido!\n");
        return;
    }
    
    for (int i = indice; i < num_ninjas - 1; i++) {
        ninjas[i] = ninjas[i + 1];
    }
    num_ninjas--;
    printf("Ninja excluído com sucesso!\n");
}

// Funções CRUD para Clãs
void criar_cla() {
    if (num_clas >= MAX_CLAS) {
        printf("Limite máximo de clãs atingido!\n");
        return;
    }

    Cla novo_cla;
    
    printf("\n=== CRIAR NOVO CLÃ ===\n");
    printf("Nome do clã: ");
    scanf(" %[^\n]", novo_cla.nome);
    
    printf("Habilidades características: ");
    scanf(" %[^\n]", novo_cla.habilidades);
    
    printf("É Kekkei Genkai? (1-Sim, 0-Não): ");
    scanf("%d", &novo_cla.eh_kekkei_genkai);
    
    clas[num_clas++] = novo_cla;
    printf("Clã criado com sucesso!\n");
}

void listar_clas() {
    printf("\n=== LISTA DE CLÃS ===\n");
    for (int i = 0; i < num_clas; i++) {
        printf("\n%d. %s\n", i+1, clas[i].nome);
        printf("   Habilidades: %s\n", clas[i].habilidades);
        printf("   Tipo: %s\n", clas[i].eh_kekkei_genkai ? "Kekkei Genkai" : "Técnica Tradicional");
    }
}

// Funções CRUD para Jutsus
void criar_jutsu() {
    if (num_jutsus_geral >= MAX_JUTSUS_GERAL) {
        printf("Limite máximo de jutsus atingido!\n");
        return;
    }

    Jutsu novo_jutsu;
    
    printf("\n=== CRIAR NOVO JUTSU ===\n");
    printf("Nome do jutsu: ");
    scanf(" %[^\n]", novo_jutsu.nome);
    
    printf("\nTipos disponíveis:\n");
    printf("0 - Ninjutsu\n1 - Taijutsu\n2 - Genjutsu\n");
    printf("Tipo: ");
    int tipo;
    scanf("%d", &tipo);
    novo_jutsu.tipo = (TipoJutsu)tipo;
    
    printf("\nElementos disponíveis:\n");
    printf("0 - Fogo\n1 - Água\n2 - Terra\n3 - Vento\n4 - Raio\n5 - Composto\n");
    printf("Elemento: ");
    int elemento;
    scanf("%d", &elemento);
    novo_jutsu.elemento = (Elemento)elemento;
    
    printf("Custo de chakra (0-100): ");
    scanf("%d", &novo_jutsu.custo_chakra);
    
    printf("Poder de ataque (0-100): ");
    scanf("%d", &novo_jutsu.poder_ataque);
    
    jutsus_geral[num_jutsus_geral++] = novo_jutsu;
    printf("Jutsu criado com sucesso!\n");
}

void listar_jutsus() {
    printf("\n=== LISTA DE JUTSUS ===\n");
    for (int i = 0; i < num_jutsus_geral; i++) {
        printf("\n%d. %s\n", i+1, jutsus_geral[i].nome);
        printf("   Tipo: %s\n", tipo_jutsu_para_string(jutsus_geral[i].tipo));
        printf("   Elemento: %s\n", elemento_para_string(jutsus_geral[i].elemento));
        printf("   Custo de Chakra: %d\n", jutsus_geral[i].custo_chakra);
        printf("   Poder de Ataque: %d\n", jutsus_geral[i].poder_ataque);
    }
}

// Funções CRUD para Missões
void criar_missao() {
    if (num_missoes >= MAX_MISSOES) {
        printf("Limite máximo de missões atingido!\n");
        return;
    }

    Missao nova_missao;
    
    printf("\n=== CRIAR NOVA MISSÃO ===\n");
    printf("Título da missão: ");
    scanf(" %[^\n]", nova_missao.titulo);
    
    // Selecionar líder
    listar_ninjas();
    if (num_ninjas == 0) {
        printf("É necessário ter ninjas cadastrados!\n");
        return;
    }
    
    int indice_lider;
    printf("Digite o número do ninja líder: ");
    scanf("%d", &indice_lider);
    indice_lider--;
    
    if (indice_lider < 0 || indice_lider >= num_ninjas) {
        printf("Índice inválido!\n");
        return;
    }
    nova_missao.lider = ninjas[indice_lider];
    
    printf("\nDificuldades disponíveis:\n");
    printf("0 - D\n1 - C\n2 - B\n3 - A\n4 - S\n");
    printf("Dificuldade: ");
    int dificuldade;
    scanf("%d", &dificuldade);
    nova_missao.dificuldade = (DificuldadeMissao)dificuldade;
    
    nova_missao.status = PENDENTE;
    nova_missao.num_participantes = 0;
    
    missoes[num_missoes++] = nova_missao;
    printf("Missão criada com sucesso!\n");
}

void listar_missoes() {
    printf("\n=== LISTA DE MISSÕES ===\n");
    for (int i = 0; i < num_missoes; i++) {
        printf("\n%d. %s\n", i+1, missoes[i].titulo);
        printf("   Líder: %s\n", missoes[i].lider.nome);
        printf("   Dificuldade: %s\n", dificuldade_para_string(missoes[i].dificuldade));
        printf("   Status: %s\n", status_para_string(missoes[i].status));
        printf("   Participantes: %d\n", missoes[i].num_participantes);
    }
}

// Funções para salvar em arquivo
void salvar_dados() {
    FILE *arquivo = fopen("ninjas.txt", "w");
    if (arquivo) {
        for (int i = 0; i < num_ninjas; i++) {
            fprintf(arquivo, "%s|%d|%d|%s|%s|%d|%d\n",
                   ninjas[i].nome,
                   ninjas[i].nivel,
                   ninjas[i].chakra,
                   ninjas[i].cla.nome,
                   ninjas[i].cla.habilidades,
                   ninjas[i].cla.eh_kekkei_genkai,
                   ninjas[i].afinidade_elemento);
        }
        fclose(arquivo);
    }
    
    arquivo = fopen("jutsus.txt", "w");
    if (arquivo) {
        for (int i = 0; i < num_jutsus_geral; i++) {
            fprintf(arquivo, "%s|%d|%d|%d|%d\n",
                   jutsus_geral[i].nome,
                   jutsus_geral[i].tipo,
                   jutsus_geral[i].elemento,
                   jutsus_geral[i].custo_chakra,
                   jutsus_geral[i].poder_ataque);
        }
        fclose(arquivo);
    }
    
    arquivo = fopen("missoes.txt", "w");
    if (arquivo) {
        for (int i = 0; i < num_missoes; i++) {
            fprintf(arquivo, "%s|%s|%d|%d|%d\n",
                   missoes[i].titulo,
                   missoes[i].lider.nome,
                   missoes[i].dificuldade,
                   missoes[i].status,
                   missoes[i].num_participantes);
        }
        fclose(arquivo);
    }
    
    printf("Dados salvos com sucesso!\n");
}

// Funções para carregar do arquivo
void carregar_dados() {
    FILE *arquivo = fopen("ninjas.txt", "r");
    if (arquivo) {
        char linha[500];
        while (fgets(linha, sizeof(linha), arquivo) && num_ninjas < MAX_NINJAS) {
            char *token = strtok(linha, "|");
            strcpy(ninjas[num_ninjas].nome, token);
            
            token = strtok(NULL, "|");
            ninjas[num_ninjas].nivel = atoi(token);
            
            token = strtok(NULL, "|");
            ninjas[num_ninjas].chakra = atoi(token);
            
            token = strtok(NULL, "|");
            strcpy(ninjas[num_ninjas].cla.nome, token);
            
            token = strtok(NULL, "|");
            strcpy(ninjas[num_ninjas].cla.habilidades, token);
            
            token = strtok(NULL, "|");
            ninjas[num_ninjas].cla.eh_kekkei_genkai = atoi(token);
            
            token = strtok(NULL, "|");
            ninjas[num_ninjas].afinidade_elemento = atoi(token);
            
            num_ninjas++;
        }
        fclose(arquivo);
    }
    
    arquivo = fopen("jutsus.txt", "r");
    if (arquivo) {
        char linha[500];
        while (fgets(linha, sizeof(linha), arquivo) && num_jutsus_geral < MAX_JUTSUS_GERAL) {
            char *token = strtok(linha, "|");
            strcpy(jutsus_geral[num_jutsus_geral].nome, token);
            
            token = strtok(NULL, "|");
            jutsus_geral[num_jutsus_geral].tipo = atoi(token);
            
            token = strtok(NULL, "|");
            jutsus_geral[num_jutsus_geral].elemento = atoi(token);
            
            token = strtok(NULL, "|");
            jutsus_geral[num_jutsus_geral].custo_chakra = atoi(token);
            
            token = strtok(NULL, "|");
            jutsus_geral[num_jutsus_geral].poder_ataque = atoi(token);
            
            num_jutsus_geral++;
        }
        fclose(arquivo);
    }
    
    printf("Dados carregados com sucesso!\n");
}

// Menu principal
void menu_principal() {
    int opcao;
    
    do {
        printf("\n=== SISTEMA KONOHA - INFO25 ===\n");
        printf("1. Gerenciar Ninjas\n");
        printf("2. Gerenciar Clãs\n");
        printf("3. Gerenciar Jutsus\n");
        printf("4. Gerenciar Missões\n");
        printf("5. Salvar Dados\n");
        printf("6. Carregar Dados\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: {
                int sub_opcao;
                do {
                    printf("\n=== GERENCIAR NINJAS ===\n");
                    printf("1. Criar Ninja\n");
                    printf("2. Listar Ninjas\n");
                    printf("3. Atualizar Ninja\n");
                    printf("4. Excluir Ninja\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &sub_opcao);
                    
                    switch(sub_opcao) {
                        case 1: criar_ninja(); break;
                        case 2: listar_ninjas(); break;
                        case 3: atualizar_ninja(); break;
                        case 4: excluir_ninja(); break;
                    }
                } while (sub_opcao != 0);
                break;
            }
            case 2: {
                int sub_opcao;
                do {
                    printf("\n=== GERENCIAR CLÃS ===\n");
                    printf("1. Criar Clã\n");
                    printf("2. Listar Clãs\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &sub_opcao);
                    
                    switch(sub_opcao) {
                        case 1: criar_cla(); break;
                        case 2: listar_clas(); break;
                    }
                } while (sub_opcao != 0);
                break;
            }
            case 3: {
                int sub_opcao;
                do {
                    printf("\n=== GERENCIAR JUTSUS ===\n");
                    printf("1. Criar Jutsu\n");
                    printf("2. Listar Jutsus\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &sub_opcao);
                    
                    switch(sub_opcao) {
                        case 1: criar_jutsu(); break;
                        case 2: listar_jutsus(); break;
                    }
                } while (sub_opcao != 0);
                break;
            }
            case 4: {
                int sub_opcao;
                do {
                    printf("\n=== GERENCIAR MISSÕES ===\n");
                    printf("1. Criar Missão\n");
                    printf("2. Listar Missões\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &sub_opcao);
                    
                    switch(sub_opcao) {
                        case 1: criar_missao(); break;
                        case 2: listar_missoes(); break;
                    }
                } while (sub_opcao != 0);
                break;
            }
            case 5: salvar_dados(); break;
            case 6: carregar_dados(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

int main() {
    printf("Bem-vindo ao Sistema de Cadastro de Missões Ninjas da INFO25!\n");
    printf("Desenvolvido para Konoha - A Vila Oculta da Folha\n\n");
    
    menu_principal();
    
    return 0;
}