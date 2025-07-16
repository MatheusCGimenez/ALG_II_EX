#include <stdio.h>

int main() {
    int cod;
    printf("CODIGO DO CLIENTE A ALTERAR: ");
    scanf("%d", &cod);

    FILE *origem = fopen("clientes.csv", "r");
    FILE *temporario = fopen("tmp.csv", "w");

    if (!origem || !temporario) {
        printf("Erro ao tentar abrir os arquivos para alteracao.\n");
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
            char nome[51], end[51], fone[21];

            printf("NOVO NOME: ");
            scanf(" %50[^\n]", nome);
            printf("NOVO ENDERECO: ");
            scanf(" %50[^\n]", end);
            printf("NOVO FONE: ");
            scanf(" %20[^\n]", fone);

            fprintf(temporario, "%d,%s,%s,%s\n", c, nome, end, fone);
        } else {
            fputs(linha, temporario);
        }
    }

    fclose(origem);
    fclose(temporario);

    remove("clientes.csv");
    rename("tmp.csv", "clientes.csv");

    if (encontrado) {
        printf("CLIENTE ALTERADO COM SUCESSO.\n");
    } else {
        printf("CLIENTE COM CODIGO %d NAO ENCONTRADO.\n", cod);
    }

    return 0;
}