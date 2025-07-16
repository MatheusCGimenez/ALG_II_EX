#include <stdio.h>

int main() {
    double valor_inicial, valor_final;

    printf("VALOR INICIAL DA FAIXA: ");
    scanf("%lf", &valor_inicial);
    printf("VALOR FINAL DA FAIXA: ");
    scanf("%lf", &valor_final);

    if (valor_inicial > valor_final) {
        double temp = valor_inicial;
        valor_inicial = valor_final;
        valor_final = temp;
    }

    FILE *arquivo = fopen("recebimentos.csv", "r");
    if (!arquivo) {
        printf("Erro: Nao foi possivel abrir o arquivo 'recebimentos.csv'.\n");
        return 1;
    }

    char linha[200];
    fgets(linha, 200, arquivo);

    printf("\n--- RECEBIMENTOS ENTRE R$ %.2f E R$ %.2f ---\n", valor_inicial, valor_final);
    while (fgets(linha, 200, arquivo)) {
        double valor_lido;
        sscanf(linha, "%*[^,],%lf", &valor_lido);
        if (valor_lido >= valor_inicial && valor_lido <= valor_final) {
            printf("%s", linha);
        }
    }

    fclose(arquivo);
    return 0;
}