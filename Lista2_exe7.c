#include <stdio.h>
#include <string.h>

int eh_data_valida(char *data_vencimento, char *data_inicio, char *data_fim) {
    return strcmp(data_vencimento, data_inicio) >= 0 && strcmp(data_vencimento, data_fim) <= 0;
}

void obter_nome_cliente(int cod, char *nome_retorno) {
    FILE *c = fopen("clientes.csv", "r");
    if (!c) {
        strcpy(nome_retorno, "NAO ENCONTRADO");
        return;
    }
    
    char linha[200];
    fgets(linha, 200, c); 

    while (fgets(linha, 200, c)) {
        int x;
        sscanf(linha, "%d,%[^,]", &x, nome_retorno);
        if (x == cod) {
            fclose(c);
            return;
        }
    }
    fclose(c);
    strcpy(nome_retorno, "CLIENTE DESCONHECIDO");
}

int main() {
    char data_inicio[11], data_fim[11];
    printf("DATA INICIAL (dd/mm/aaaa): ");
    scanf("%10s", data_inicio);
    printf("DATA FINAL (dd/mm/aaaa): ");
    scanf("%10s", data_fim);

    FILE *r = fopen("recebimentos.csv", "r");
    if (!r) {
        printf("Erro: Nao foi possivel abrir o arquivo 'recebimentos.csv'.\n");
        return 1;
    }

    char linha[200];
    fgets(linha, 200, r); 

    printf("\n--- RELATORIO DE RECEBIMENTOS ---\n");
    while (fgets(linha, 200, r)) {
        int doc, cod;
        double v;
        char em[11], ven[11];
        sscanf(linha, "%d,%lf,%[^,],%[^,],%d", &doc, &v, em, ven, &cod);

        if (eh_data_valida(ven, data_inicio, data_fim)) {
            char nome_cliente[51];
            obter_nome_cliente(cod, nome_cliente);
            printf("DOC: %d | CLIENTE: %s | VALOR: R$ %.2f | VENCIMENTO: %s\n", doc, nome_cliente, v, ven);
        }
    }

    fclose(r);
    return 0;
}