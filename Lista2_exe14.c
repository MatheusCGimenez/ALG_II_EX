#include <stdio.h>

int main() {
    int op;
    printf("--- MENU NOTAS ---\n");
    printf("1. CRIAR ARQUIVO\n");
    printf("2. INCLUIR NOTAS\n");
    printf("3. SAIR\n");
    printf("OPCAO: ");
    scanf("%d", &op);

    if (op == 1) {
        FILE *arquivo = fopen("notas.csv", "w");
        if (!arquivo) {
            printf("Erro ao criar o arquivo 'notas.csv'.\n");
            return 1;
        }
        fprintf(arquivo, "NUM,NOME,NOTA1,NOTA2\n");
        fclose(arquivo);
        printf("Arquivo 'notas.csv' criado com sucesso.\n");
    } else if (op == 2) {
        FILE *arquivo = fopen("notas.csv", "a");
        if (!arquivo) {
            printf("Erro ao abrir o arquivo 'notas.csv'.\n");
            return 1;
        }
        int num;
        char nome[41];
        float n1, n2;

        while (1) {
            printf("\nNUMERO DO ALUNO (ou 0 para sair): ");
            scanf("%d", &num);
            if (num == 0) {
                break;
            }
            printf("NOME: ");
            scanf(" %40[^\n]", nome);
            printf("NOTA 1: ");
            scanf("%f", &n1);
            printf("NOTA 2: ");
            scanf("%f", &n2);
            fprintf(arquivo, "%d,%s,%.1f,%.1f\n", num, nome, n1, n2);
            printf("Aluno incluido com sucesso.\n");
        }
        fclose(arquivo);
    }
    
    return 0;
}