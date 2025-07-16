#include <stdio.h>
#include <stdlib.h>

int* multiplica_vetores(int* a, int* b, int n) {
    int* c = (int*) malloc(n * sizeof(int));
    if (c == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
    }
    return c;
}

int main() {
    int vetorA[] = {1, 2, 3, 4, 5};
    int vetorB[] = {10, 9, 8, 7, 6};
    int tamanho = 5;

    int* vetorC = multiplica_vetores(vetorA, vetorB, tamanho);

    if (vetorC != NULL) {
        printf("Vetor resultado da multiplicacao: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", vetorC[i]);
        }
        printf("\n");
        free(vetorC);
    }
    return 0;
}