#include <stdio.h>

int main() {
    FILE *origem = fopen("produtos.csv", "r");
    FILE *temporario = fopen("tmp.csv", "w");

    if (!origem || !temporario) {
        printf("Erro: Falha ao abrir arquivos para exclusao.\n");
        return 1;
    }

    char linha[200];
    fgets(linha, 200, origem);
    fputs(linha, temporario);

    while (fgets(linha, 200, origem)) {
        double valor;
        sscanf(linha, "%*[^,],%*[^,],%lf", &valor);
        if (valor <= 200.0) {
            fputs(linha, temporario);
        }
    }

    fclose(origem);
    fclose(temporario);

    remove("produtos.csv");
    rename("tmp.csv", "produtos.csv");

    printf("PRODUTOS COM PRECO SUPERIOR A R$ 200.00 FORAM EXCLUIDOS.\n");
    return 0;
}