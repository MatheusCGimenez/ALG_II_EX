#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite a dimensao da matriz: ");
    scanf("%d", &n);

    int** matriz = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*) malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                matriz[i][j] = 1;
            } else if (i > j) {
                matriz[i][j] = -1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }

    printf("Matriz gerada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}