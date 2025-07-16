#include <stdio.h>
#include <stdlib.h>

int* produto_matriz_vetor(int** matriz_a, int* vetor_b, int n) {
    int* vetor_c = (int*) calloc(n, sizeof(int));
    if (vetor_c == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vetor_c[i] += matriz_a[i][j] * vetor_b[j];
        }
    }
    return vetor_c;
}

int main() {
    int n = 3;
    int* vetor_b = (int[]){2, 3, 4};
    int** matriz_a = (int**) malloc(n * sizeof(int*));
    matriz_a[0] = (int[]){1, 2, 3};
    matriz_a[1] = (int[]){4, 5, 6};
    matriz_a[2] = (int[]){7, 8, 9};

    int* vetor_resultado = produto_matriz_vetor(matriz_a, vetor_b, n);

    if (vetor_resultado != NULL) {
        printf("Resultado do produto da matriz pelo vetor: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", vetor_resultado[i]);
        }
        printf("\n");
        free(vetor_resultado);
    }
    
    free(matriz_a);
    return 0;
}