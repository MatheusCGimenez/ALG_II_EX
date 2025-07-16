#include <stdio.h>

int main() {
    FILE *arquivo_clientes = fopen("clientes.csv", "a");
    if (arquivo_clientes == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo 'clientes.csv'.\n");
        return 1;
    }

    int cod;
    char nome[51], end[51], fone[21];

    printf("COD: ");
    scanf("%d", &cod);

    printf("NOME: ");
    scanf(" %50[^\n]", nome);

    printf("ENDERECO: ");
    scanf(" %50[^\n]", end);

    printf("FONE: ");
    scanf(" %20[^\n]", fone);

    fprintf(arquivo_clientes, "%d,%s,%s,%s\n", cod, nome, end, fone);
    fclose(arquivo_clientes);

    printf("CLIENTE CADASTRADO COM SUCESSO.\n");

    return 0;
}