#include <stdio.h>
#include <stdlib.h>

int busca_valor(int** matriz, int linhas, int colunas, int valor) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                return 1; // Encontrou
            }
        }
    }
    return 0; // Não encontrou
}

int main() {
    int linhas, colunas, valor_para_buscar;
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    int** matriz = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
    }

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Digite o valor a ser buscado na matriz: ");
    scanf("%d", &valor_para_buscar);

    if (busca_valor(matriz, linhas, colunas, valor_para_buscar)) {
        printf("O valor %d ESTA na matriz.\n", valor_para_buscar);
    } else {
        printf("O valor %d NAO ESTA na matriz.\n", valor_para_buscar);
    }

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}