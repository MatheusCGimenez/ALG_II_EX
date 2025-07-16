#include <stdio.h>

int main() {
    double valor_referencia;
    printf("VALOR DE REFERENCIA: ");
    scanf("%lf", &valor_referencia);

    FILE *arquivo_recebimentos = fopen("recebimentos.csv", "r");
    if (!arquivo_recebimentos) {
        printf("Erro: Nao foi possivel abrir o arquivo 'recebimentos.csv'.\n");
        return 1;
    }

    char linha[200];
    fgets(linha, 200, arquivo_recebimentos);

    printf("\n--- RECEBIMENTOS COM VALOR MENOR QUE R$ %.2f ---\n", valor_referencia);
    while (fgets(linha, 200, arquivo_recebimentos)) {
        double valor_lido;
        sscanf(linha, "%*[^,],%lf", &valor_lido);
        if (valor_lido < valor_referencia) {
            printf("%s", linha);
        }
    }

    fclose(arquivo_recebimentos);
    return 0;
}