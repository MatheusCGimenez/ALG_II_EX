#include <stdio.h>

int main() {
    FILE *produtos = fopen("produtos.csv", "r");
    if (!produtos) {
        printf("Erro: Nao foi possivel abrir o arquivo 'produtos.csv'.\n");
        return 1;
    }
    
    char linha[200];
    fgets(linha, 200, produtos);
    
    printf("--- PRODUTOS COM PRECO SUPERIOR A R$ 500.00 ---\n");
    while (fgets(linha, 200, produtos)) {
        double valor;
        sscanf(linha, "%*[^,],%*[^,],%lf", &valor);
        if (valor > 500) {
            printf("%s", linha);
        }
    }
    
    fclose(produtos);
    return 0;
}