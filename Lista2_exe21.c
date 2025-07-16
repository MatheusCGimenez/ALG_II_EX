#include <stdio.h>

int main() {
    int cod;
    printf("CODIGO DO PRODUTO A EXCLUIR: ");
    scanf("%d", &cod);

    FILE *origem = fopen("produtos.csv", "r");
    FILE *temporario = fopen("tmp.csv", "w");

    if (!origem || !temporario) {
        printf("Erro: Falha ao abrir os arquivos para exclusao.\n");
        return 1;
    }

    char linha[200];
    fgets(linha, 200, origem);
    fputs(linha, temporario);

    int encontrado = 0;
    while (fgets(linha, 200, origem)) {
        int c;
        sscanf(linha, "%d,", &c);
        if (c == cod) {
            encontrado = 1;
        } else {
            fputs(linha, temporario);
        }
    }

    fclose(origem);
    fclose(temporario);

    remove("produtos.csv");
    rename("tmp.csv", "produtos.csv");

    if (encontrado) {
        printf("PRODUTO EXCLUIDO COM SUCESSO.\n");
    } else {
        printf("AVISO: Produto com codigo %d nao foi encontrado.\n", cod);
    }

    return 0;
}