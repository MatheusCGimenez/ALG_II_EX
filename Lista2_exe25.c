#include <stdio.h>

int main() {
    double preco_ini, preco_fim, percentual;

    printf("PRECO INICIAL DA FAIXA: ");
    scanf("%lf", &preco_ini);
    printf("PRECO FINAL DA FAIXA: ");
    scanf("%lf", &preco_fim);
    printf("PERCENTUAL DE DESCONTO: ");
    scanf("%lf", &percentual);

    if (preco_ini > preco_fim) {
        double temp = preco_ini;
        preco_ini = preco_fim;
        preco_fim = temp;
    }

    FILE *origem = fopen("produtos.csv", "r");
    FILE *temporario = fopen("tmp.csv", "w");

    if (!origem || !temporario) {
        printf("Erro: Falha ao abrir arquivos para aplicar desconto.\n");
        return 1;
    }

    char linha[200];
    fgets(linha, 200, origem);
    fputs(linha, temporario);

    while (fgets(linha, 200, origem)) {
        int cod;
        char desc[41];
        double preco;
        sscanf(linha, "%d,%[^,],%lf", &cod, desc, &preco);

        if (preco >= preco_ini && preco <= preco_fim) {
            preco = preco * (1.0 - percentual / 100.0);
        }

        fprintf(temporario, "%d,%s,%.2f\n", cod, desc, preco);
    }

    fclose(origem);
    fclose(temporario);

    remove("produtos.csv");
    rename("tmp.csv", "produtos.csv");

    printf("DESCONTO DE %.2f%% APLICADO COM SUCESSO.\n", percentual);
    return 0;
}