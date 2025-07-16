#include <stdio.h>

int main() {
    FILE *estilistas = fopen("estilistas.csv", "w");
    if (!estilistas) {
        printf("Erro ao criar o arquivo 'estilistas.csv'.\n");
        return 1;
    }
    fprintf(estilistas, "COD,NOME,SALARIO\n");
    fclose(estilistas);

    FILE *roupas = fopen("roupas.csv", "w");
    if (!roupas) {
        printf("Erro ao criar o arquivo 'roupas.csv'.\n");
        return 1;
    }
    fprintf(roupas, "COD_ROUPA,DESC,COD_ESTILISTA,COD_ESTACAO,ANO\n");
    fclose(roupas);

    FILE *estacoes = fopen("estacoes.csv", "w");
    if (!estacoes) {
        printf("Erro ao criar o arquivo 'estacoes.csv'.\n");
        return 1;
    }
    fprintf(estacoes, "COD,NOME\n");
    fclose(estacoes);

    printf("Arquivos de moda criados com sucesso.\n");
    return 0;
}