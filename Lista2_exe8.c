#include <stdio.h>

int main() {
    int cod_cliente;
    printf("CODIGO DO CLIENTE: ");
    scanf("%d", &cod_cliente);

    FILE *arquivo_recebimentos = fopen("recebimentos.csv", "r");
    if (!arquivo_recebimentos) {
        printf("Erro: Nao foi possivel abrir o arquivo 'recebimentos.csv'.\n");
        return 1;
    }

    char linha[200];
    fgets(linha, 200, arquivo_recebimentos);

    int encontrado = 0;
    printf("\n--- RECEBIMENTOS PARA O CLIENTE %d ---\n", cod_cliente);
    while (fgets(linha, 200, arquivo_recebimentos)) {
        int c;
        sscanf(linha, "%*[^,],%*[^,],%*[^,],%*[^,],%d", &c);
        if (cod_cliente == c) {
            printf("%s", linha);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum recebimento encontrado para este cliente.\n");
    }

    fclose(arquivo_recebimentos);
    return 0;
}