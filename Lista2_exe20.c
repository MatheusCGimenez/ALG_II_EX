#include <stdio.h>

int main() {
    FILE *produtos = fopen("produtos.csv", "r");
    if (!produtos) {
        printf("Erro: Nao foi possivel abrir o arquivo 'produtos.csv'.\n");
        return 1;
    }
    
    char linha[200];
    fgets(linha, 200, produtos);

    printf("--- PRODUTOS CUJA DESCRICAO INICIA COM 'M' ---\n");
    while (fgets(linha, 200, produtos)) {
        char desc[41];
        sscanf(linha, "%*[^,],%[^,]", desc);
        if (desc[0] == 'M' || desc[0] == 'm') {
            printf("%s", linha);
        }
    }
    
    fclose(produtos);
    return 0;
}