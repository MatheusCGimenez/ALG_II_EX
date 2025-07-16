#include <stdio.h>

int main() {
    FILE *origem = fopen("produtos.csv", "r");
    FILE *temporario = fopen("tmp.csv", "w");

    if (!origem || !temporario) {
        printf("Erro ao abrir arquivos para ajuste de precos.\n");
        return 1;
    }
    
    char linha[200];
    fgets(linha, 200, origem);
    fputs(linha, temporario);
    
    while (fgets(linha, 200, origem)) {
        int cod;
        char desc[41];
        double preco;
        sscanf(linha, "%d,%[^,],%lf", &cod, desc, &preco);
        
        if (preco > 100.0) {
            preco += 10.0;
        }
        
        fprintf(temporario, "%d,%s,%.2f\n", cod, desc, preco);
    }
    
    fclose(origem);
    fclose(temporario);
    
    remove("produtos.csv");
    rename("tmp.csv", "produtos.csv");
    
    printf("PRECOS AJUSTADOS COM SUCESSO.\n");
    return 0;
}