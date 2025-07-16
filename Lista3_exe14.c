#include <stdio.h>
#include <stdlib.h>

int* soma_vetores(int* a, int* b, int n) {
    int* c = (int*) malloc(n * sizeof(int));
    if (c == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
    return c;
}

int main() {
    int vetorA[] = {10, 20, 30, 40, 50};
    int vetorB[] = {1, 2, 3, 4, 5};
    int tamanho = 5;

    int* vetorC = soma_vetores(vetorA, vetorB, tamanho);

    if (vetorC != NULL) {
        printf("Vetor resultado da soma: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", vetorC[i]);
        }
        printf("\n");
        free(vetorC);
    }
    return 0;
}