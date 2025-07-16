#include <stdio.h>

int main() {
    FILE *produtos = fopen("produtos.csv", "r");
    if (!produtos) {
        printf("Erro: Nao foi possivel abrir o arquivo 'produtos.csv'.\n");
        return 1;
    }

    char linha[200];
    fgets(linha, 200, produtos);

    printf("\n--- PRODUTOS COM PRECO INFERIOR A R$ 15.00 ---\n");
    while (fgets(linha, 200, produtos)) {
        double valor;
        sscanf(linha, "%*[^,],%*[^,],%lf", &valor);
        if (valor < 15.0) {
            printf("%s", linha);
        }
    }

    fclose(produtos);
    return 0;
}