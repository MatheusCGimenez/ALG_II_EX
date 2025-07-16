#include <stdio.h>
#include <ctype.h>

int main() {
    char letra_inicial;
    double preco_min, preco_max;

    printf("DIGITE A LETRA INICIAL DA DESCRICAO: ");
    scanf(" %c", &letra_inicial);
    letra_inicial = toupper(letra_inicial);

    printf("PRECO MINIMO: ");
    scanf("%lf", &preco_min);
    printf("PRECO MAXIMO: ");
    scanf("%lf", &preco_max);

    if (preco_min > preco_max) {
        double temp = preco_min;
        preco_min = preco_max;
        preco_max = temp;
    }

    FILE *produtos = fopen("produtos.csv", "r");
    if (!produtos) {
        printf("Erro: Nao foi possivel abrir o arquivo 'produtos.csv'.\n");
        return 1;
    }

    char linha[200];
    fgets(linha, 200, produtos);

    printf("\n--- RESULTADO DA BUSCA ---\n");
    while (fgets(linha, 200, produtos)) {
        char desc[41];
        double valor;
        sscanf(linha, "%*[^,],%[^,],%lf", desc, &valor);

        if (toupper(desc[0]) == letra_inicial && valor >= preco_min && valor <= preco_max) {
            printf("%s", linha);
        }
    }

    fclose(produtos);
    return 0;
}