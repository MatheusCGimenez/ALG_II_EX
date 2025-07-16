#include <stdio.h>

int existe_produto(int cod);

int main() {
    int cod;
    char desc[41];
    double preco;

    printf("CODIGO DO PRODUTO: ");
    scanf("%d", &cod);

    if (existe_produto(cod)) {
        printf("ERRO: Codigo de produto ja cadastrado.\n");
        return 0;
    }

    printf("DESCRICAO: ");
    scanf(" %40[^\n]", desc);
    printf("PRECO: ");
    scanf("%lf", &preco);

    FILE *p = fopen("produtos.csv", "a");
    if (!p) {
        printf("ERRO: Nao foi possivel abrir o arquivo 'produtos.csv'.\n");
        return 1;
    }

    fprintf(p, "%d,%s,%.2f\n", cod, desc, preco);
    fclose(p);
    
    printf("PRODUTO INCLUIDO COM SUCESSO.\n");
    return 0;
}

int existe_produto(int cod) {
    FILE *p = fopen("produtos.csv", "r");
    if (!p) {
        return 0;
    }
    
    char linha[200];
    fgets(linha, 200, p);
    
    while (fgets(linha, 200, p)) {
        int c;
        sscanf(linha, "%d,", &c);
        if (c == cod) {
            fclose(p);
            return 1;
        }
    }
    
    fclose(p);
    return 0;
}