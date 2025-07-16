#include <stdio.h>
#include <stdlib.h>

int* cria_vetor_sequencial(int n) {
    int* vetor = (int*) malloc(n * sizeof(int));
    if (vetor == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        vetor[i] = i;
    }
    return vetor;
}

int main() {
    int tamanho = 10;
    int* meu_vetor = cria_vetor_sequencial(tamanho);

    if (meu_vetor != NULL) {
        printf("Vetor gerado: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", meu_vetor[i]);
        }
        printf("\n");
        free(meu_vetor);
    }
    return 0;
}