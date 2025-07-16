#include <stdio.h>
#include <stdlib.h>

int** produto_de_matrizes(int** a, int lin_a, int col_a, int** b, int lin_b, int col_b) {
    if (col_a != lin_b) {
        return NULL; 
    }

    int** c = (int**) malloc(lin_a * sizeof(int*));
    for (int i = 0; i < lin_a; i++) {
        c[i] = (int*) calloc(col_b, sizeof(int));
    }

    for (int i = 0; i < lin_a; i++) {
        for (int j = 0; j < col_b; j++) {
            for (int k = 0; k < col_a; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int main() {
    int lin_a = 2, col_a = 3;
    int lin_b = 3, col_b = 2;

    int** matriz_a = (int**) malloc(lin_a * sizeof(int*));
    matriz_a[0] = (int[]){1, 2, 3};
    matriz_a[1] = (int[]){4, 5, 6};

    int** matriz_b = (int**) malloc(lin_b * sizeof(int*));
    matriz_b[0] = (int[]){7, 8};
    matriz_b[1] = (int[]){9, 10};
    matriz_b[2] = (int[]){11, 12};

    int** matriz_c = produto_de_matrizes(matriz_a, lin_a, col_a, matriz_b, lin_b, col_b);

    if (matriz_c != NULL) {
        printf("Matriz resultante do produto:\n");
        for (int i = 0; i < lin_a; i++) {
            for (int j = 0; j < col_b; j++) {
                printf("%d\t", matriz_c[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < lin_a; i++) {
            free(matriz_c[i]);
        }
        free(matriz_c);
    }

    free(matriz_a);
    free(matriz_b);

    return 0;
}