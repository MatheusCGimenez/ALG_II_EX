#include <stdio.h>

int main() {
    FILE *produtos = fopen("produtos.csv", "w");
    if (!produtos) {
        printf("Erro: Nao foi possivel criar o arquivo 'produtos.csv'.\n");
        return 1;
    }

    fprintf(produtos, "COD,DESCRICAO,PRECO\n");
    fclose(produtos);

    printf("Arquivo 'produtos.csv' criado com sucesso.\n");
    return 0;
}