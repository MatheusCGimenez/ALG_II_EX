#include <stdio.h>
#include <string.h>

int existe_codigo(char* nome_arquivo, int cod) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        return 0;
    }

    char linha[200];
    fgets(linha, 200, arquivo);

    while (fgets(linha, 200, arquivo)) {
        int c;
        sscanf(linha, "%d,", &c);
        if (c == cod) {
            fclose(arquivo);
            return 1;
        }
    }
    fclose(arquivo);
    return 0;
}

void cadastraEstacao() {
    int cod;
    char nome[31];

    printf("CODIGO DA ESTACAO: ");
    scanf("%d", &cod);

    if (existe_codigo("estacoes.csv", cod)) {
        printf("ERRO: Codigo de estacao ja existe.\n");
        return;
    }
    
    FILE *arquivo = fopen("estacoes.csv", "a");
    if (!arquivo) {
        printf("ERRO: Nao foi possivel abrir o arquivo de estacoes.\n");
        return;
    }

    printf("NOME DA ESTACAO: ");
    scanf(" %30[^\n]", nome);

    fprintf(arquivo, "%d,%s\n", cod, nome);
    fclose(arquivo);
    printf("ESTACAO CADASTRADA COM SUCESSO.\n");
}

void cadastraEstilista() {
    int cod;
    char nome[31];
    double salario;

    printf("CODIGO DO ESTILISTA: ");
    scanf("%d", &cod);
    if (existe_codigo("estilistas.csv", cod)) {
        printf("ERRO: Codigo de estilista ja existe.\n");
        return;
    }

    FILE *arquivo = fopen("estilistas.csv", "a");
    if (!arquivo) {
        printf("ERRO: Nao foi possivel abrir o arquivo de estilistas.\n");
        return;
    }
    
    printf("NOME DO ESTILISTA: ");
    scanf(" %30[^\n]", nome);
    printf("SALARIO: ");
    scanf("%lf", &salario);

    fprintf(arquivo, "%d,%s,%.2f\n", cod, nome, salario);
    fclose(arquivo);
    printf("ESTILISTA CADASTRADO COM SUCESSO.\n");
}

void cadastraRoupa() {
    int cod, cod_estilista, cod_estacao, ano;
    char desc[41];

    printf("CODIGO DA ROUPA: ");
    scanf("%d", &cod);
    if (existe_codigo("roupas.csv", cod)) {
        printf("ERRO: Codigo de roupa ja existe.\n");
        return;
    }

    printf("CODIGO DO ESTILISTA: ");
    scanf("%d", &cod_estilista);
    if (!existe_codigo("estilistas.csv", cod_estilista)) {
        printf("ERRO: Estilista nao encontrado.\n");
        return;
    }

    printf("CODIGO DA ESTACAO: ");
    scanf("%d", &cod_estacao);
    if (!existe_codigo("estacoes.csv", cod_estacao)) {
        printf("ERRO: Estacao nao encontrada.\n");
        return;
    }

    FILE *arquivo = fopen("roupas.csv", "a");
    if (!arquivo) {
        printf("ERRO: Nao foi possivel abrir o arquivo de roupas.\n");
        return;
    }

    printf("DESCRICAO DA ROUPA: ");
    scanf(" %40[^\n]", desc);
    printf("ANO DE LANCAMENTO: ");
    scanf("%d", &ano);
    
    fprintf(arquivo, "%d,%s,%d,%d,%d\n", cod, desc, cod_estilista, cod_estacao, ano);
    fclose(arquivo);
    printf("ROUPA CADASTRADA COM SUCESSO.\n");
}

void relatorioPorEstacao() {
    int cod_estacao;
    printf("CODIGO DA ESTACAO PARA O RELATORIO: ");
    scanf("%d", &cod_estacao);

    FILE *roupas = fopen("roupas.csv", "r");
    if (!roupas) {
        printf("ERRO: Nao foi possivel abrir o arquivo de roupas.\n");
        return;
    }
    
    printf("\n--- RELATORIO DE ROUPAS DA ESTACAO %d ---\n", cod_estacao);
    char linha_roupa[300];
    fgets(linha_roupa, 300, roupas);

    while (fgets(linha_roupa, 300, roupas)) {
        int cod_r, cod_es, cod_s, ano;
        char desc[41];
        sscanf(linha_roupa, "%d,%[^,],%d,%d,%d", &cod_r, desc, &cod_es, &cod_s, &ano);

        if (cod_s == cod_estacao) {
            char nome_estilista[31] = "NAO ENCONTRADO";
            FILE *estilistas = fopen("estilistas.csv", "r");
            if (estilistas) {
                char linha_estilista[200];
                fgets(linha_estilista, 200, estilistas);
                while (fgets(linha_estilista, 200, estilistas)) {
                    int c;
                    sscanf(linha_estilista, "%d,%[^,]", &c, nome_estilista);
                    if (c == cod_es) break;
                }
                fclose(estilistas);
            }
            printf("ROUPA: %d - %s | ESTILISTA: %s | ANO: %d\n", cod_r, desc, nome_estilista, ano);
        }
    }
    fclose(roupas);
}

int main() {
    int op;
    do {
        printf("\n--- MENU ---\n");
        printf("1. CADASTRAR ESTACAO\n");
        printf("2. CADASTRAR ESTILISTA\n");
        printf("3. CADASTRAR ROUPA\n");
        printf("4. RELATORIO POR ESTACAO\n");
        printf("5. SAIR\n");
        printf("OPCAO: ");
        scanf("%d", &op);
        printf("\n");

        switch (op) {
            case 1: cadastraEstacao(); break;
            case 2: cadastraEstilista(); break;
            case 3: cadastraRoupa(); break;
            case 4: relatorioPorEstacao(); break;
            case 5: printf("Saindo do programa.\n"); break;
            default: printf("Opcao invalida. Tente novamente.\n"); break;
        }
    } while (op != 5);

    return 0;
}