#include <stdio.h>

int main() {
    int doc, cod;
    printf("DOC: ");
    scanf("%d", &doc);
    printf("COD CLI: ");
    scanf("%d", &cod);

    FILE *origem = fopen("recebimentos.csv", "r");
    FILE *temporario = fopen("tmp.csv", "w");
    if (!origem || !temporario) {
        printf("Erro ao abrir arquivos para alteracao.\n");
        return 1;
    }

    char linha[200];
    fgets(linha, 200, origem);
    fputs(linha, temporario);

    int encontrado = 0;
    while (fgets(linha, 200, origem)) {
        int d, c;
        sscanf(linha, "%d,%*[^,],%*[^,],%*[^,],%d", &d, &c);
        if (d == doc && c == cod) {
            encontrado = 1;
            double v;
            char em[11], ven[11];
            printf("NOVO VALOR: ");
            scanf("%lf", &v);
            printf("NOVA EMISSAO (dd/mm/aaaa): ");
            scanf("%10s", em);
            printf("NOVO VENCIMENTO (dd/mm/aaaa): ");
            scanf("%10s", ven);
            fprintf(temporario, "%d,%.2f,%s,%s,%d\n", doc, v, em, ven, cod);
        } else {
            fputs(linha, temporario);
        }
    }

    fclose(origem);
    fclose(temporario);
    remove("recebimentos.csv");
    rename("tmp.csv", "recebimentos.csv");

    if (encontrado) {
        printf("RECEBIMENTO ALTERADO COM SUCESSO.\n");
    } else {
        printf("RECEBIMENTO NAO ENCONTRADO (DOC: %d, CLIENTE: %d).\n", doc, cod);
    }

    return 0;
}