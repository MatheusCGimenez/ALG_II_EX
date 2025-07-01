#include <stdio.h>

int main()
{
    FILE *clientes;
    FILE *recebimentos;

    clientes = fopen("../clientes.csv", "w");
    recebimentos = fopen("../recebimento.csv", "w");

    if((clientes || recebimentos) == NULL){
        printf("Erro ao abrir arquivo. \n");
        return 1;
    }

    fprintf(clientes, "Cod_Cli,Nome,Endereco,Fone");
    fprintf(recebimentos, "Num_doc,Valor_doc,Data_Emissao,Data_Vencimento,Cod_Cli");

    fclose(clientes);
    fclose(recebimentos);

    return 0;
}