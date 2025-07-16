#include <stdio.h>

int cliente_existe(int cod_cliente) {
    FILE *arquivo_clientes = fopen("clientes.csv", "r");
    if (arquivo_clientes == NULL) {
        return 0;
    }

    char linha[200];
    fgets(linha, 200, arquivo_clientes);

    while (fgets(linha, 200, arquivo_clientes)) {
        int codigo_lido;
        sscanf(linha, "%d,", &codigo_lido);
        if (codigo_lido == cod_cliente) {
            fclose(arquivo_clientes);
            return 1;
        }
    }

    fclose(arquivo_clientes);
    return 0;
}

int main() {
    int cod_cliente;
    printf("COD CLIENTE: ");
    scanf("%d", &cod_cliente);

    if (!cliente_existe(cod_cliente)) {
        printf("ERRO: CLIENTE COM CODIGO %d NAO ENCONTRADO.\n", cod_cliente);
        return 0;
    }

    FILE *arquivo_recebimentos = fopen("recebimentos.csv", "a");
    if (arquivo_recebimentos == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo 'recebimentos.csv'.\n");
        return 1;
    }

    int doc;
    double val;
    char em[11], ven[11];

    printf("DOC: ");
    scanf("%d", &doc);

    printf("VALOR: ");
    scanf("%lf", &val);

    printf("EMISSAO (dd/mm/aaaa): ");
    scanf("%10s", em);

    printf("VENCIMENTO (dd/mm/aaaa): ");
    scanf("%10s", ven);

    fprintf(arquivo_recebimentos, "%d,%.2f,%s,%s,%d\n", doc, val, em, ven, cod_cliente);
    fclose(arquivo_recebimentos);
    
    printf("RECEBIMENTO INCLUIDO COM SUCESSO.\n");

    return 0;
}