#include <stdio.h>

int main() {
    FILE *arquivo;
    int numero = 12345;

    // Abre o arquivo em modo de escrita binária
    arquivo = fopen("exemplo.bin", "wb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Escreve o inteiro no arquivo
    fwrite(&numero, sizeof(int), 1, arquivo);

    // Fecha o arquivo
    fclose(arquivo);

    printf("Dados gravados com sucesso!\n");
    return 0;
}