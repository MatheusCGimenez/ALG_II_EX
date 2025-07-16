#include <stdio.h>
#include <stdlib.h>

int** cria_matriz_diagonal_secundaria(int n) {
    int** matriz = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*) malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j == n - 1) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
    return matriz;
}

int main() {
    int dimensao = 5;
    int** matriz = cria_matriz_diagonal_secundaria(dimensao);

    printf("Matriz com diagonal secundaria preenchida (dimensao %d):\n", dimensao);
    for (int i = 0; i < dimensao; i++) {
        for (int j = 0; j < dimensao; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < dimensao; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}