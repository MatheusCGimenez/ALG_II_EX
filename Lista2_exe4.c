#include <stdio.h>
#include <string.h>

void copia_exceto_codigo(FILE *origem, FILE *destino, int cod_excluir) {
    char linha[200];
    fgets(linha, 200, origem);
    fputs(linha, destino);

    while (fgets(linha, 200, origem)) {
        int codigo_lido;
        sscanf(linha, "%d,", &codigo_lido);
        if (codigo_lido != cod_excluir) {
            fputs(linha, destino);
        }
    }
}

int main() {
    int cod;
    printf("CODIGO DO CLIENTE A EXCLUIR: ");
    scanf("%d", &cod);

    FILE *origem_cli = fopen("clientes.csv", "r");
    FILE *temp_cli = fopen("temp_clientes.csv", "w");

    if (!origem_cli || !temp_cli) {
        printf("Erro ao abrir arquivos de clientes.\n");
        return 1;
    }
    copia_exceto_codigo(origem_cli, temp_cli, cod);
    fclose(origem_cli);
    fclose(temp_cli);
    remove("clientes.csv");
    rename("temp_clientes.csv", "clientes.csv");

    FILE *origem_rec = fopen("recebimentos.csv", "r");
    FILE *temp_rec = fopen("temp_recebimentos.csv", "w");

    if (!origem_rec || !temp_rec) {
        printf("Erro ao abrir arquivos de recebimentos.\n");
        return 1;
    }
    copia_exceto_codigo(origem_rec, temp_rec, cod);
    fclose(origem_rec);
    fclose(temp_rec);
    remove("recebimentos.csv");
    rename("temp_recebimentos.csv", "recebimentos.csv");

    printf("CLIENTE E SEUS RECEBIMENTOS FORAM EXCLUIDOS COM SUCESSO.\n");

    return 0;
}