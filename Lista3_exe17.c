#include <stdio.h>
#include <stdlib.h>

int* soma_colunas_matriz(int** matriz, int n) {
    int* vetor_soma = (int*) calloc(n, sizeof(int));
    if (vetor_soma == NULL) {
        return NULL;
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            vetor_soma[j] += matriz[i][j];
        }
    }
    return vetor_soma;
}

int main() {
    int n = 3;
    int** matriz_a = (int**) malloc(n * sizeof(int*));
    matriz_a[0] = (int[]){1, 2, 3};
    matriz_a[1] = (int[]){4, 5, 6};
    matriz_a[2] = (int[]){7, 8, 9};

    int* resultado = soma_colunas_matriz(matriz_a, n);

    if (resultado != NULL) {
        printf("Vetor com a soma das colunas: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", resultado[i]);
        }
        printf("\n");
        free(resultado);
    }
    free(matriz_a);
    return 0;
}