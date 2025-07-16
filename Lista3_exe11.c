#include <stdio.h>
#include <stdlib.h>

int** cria_matriz_identidade(int n) {
    int** matriz = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*) malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
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
    int** identidade = cria_matriz_identidade(dimensao);

    printf("Matriz Identidade de dimensao %d:\n", dimensao);
    for (int i = 0; i < dimensao; i++) {
        for (int j = 0; j < dimensao; j++) {
            printf("%d ", identidade[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < dimensao; i++) {
        free(identidade[i]);
    }
    free(identidade);

    return 0;
}