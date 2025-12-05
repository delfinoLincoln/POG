#include <stdio.h>

int main() {
    FILE *arquivo;
    int numero_lido;

    // Abre o arquivo em modo de leitura binária
    arquivo = fopen("exemplo.bin", "rb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê o inteiro do arquivo
    fread(&numero_lido, sizeof(int), 1, arquivo);

    // Fecha o arquivo
    fclose(arquivo);

    printf("Numero lido: %d\n", numero_lido);
    return 0;
}