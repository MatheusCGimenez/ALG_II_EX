#include <stdio.h>

int main() {
    FILE *arquivo_clientes = fopen("clientes.csv", "w");
    if (arquivo_clientes == NULL) {
        printf("Erro: Nao foi possivel criar o arquivo 'clientes.csv'.\n");
        return 1;
    }

    FILE *arquivo_recebimentos = fopen("recebimentos.csv", "w");
    if (arquivo_recebimentos == NULL) {
        printf("Erro: Nao foi possivel criar o arquivo 'recebimentos.csv'.\n");
        fclose(arquivo_clientes);
        return 1;
    }

    fprintf(arquivo_clientes, "COD,NOME,ENDERECO,FONE\n");
    fprintf(arquivo_recebimentos, "DOC,VALOR,EMISSAO,VENCIMENTO,COD_CLI\n");

    fclose(arquivo_clientes);
    fclose(arquivo_recebimentos);

    printf("Arquivos 'clientes.csv' e 'recebimentos.csv' criados com sucesso.\n");
    
    return 0;
}