#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    do {
        printf("Digite o tamanho do vetor (um numero positivo): ");
        scanf("%d", &n);
    } while (n < 0);

    int* v = (int*) malloc(n * sizeof(int));
    if (v == NULL) {
        return 1;
    }

    printf("Digite os %d elementos do vetor (maiores ou iguais a 2):\n", n);
    for (int i = 0; i < n; i++) {
        do {
            printf("Posicao V[%d]: ", i);
            scanf("%d", &v[i]);
        } while (v[i] < 2);
    }

    printf("\nVetor final: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);
    return 0;
}