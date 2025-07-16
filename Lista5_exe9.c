#include <stdio.h>

void imprimirVetor(int *vetor, int tamanho) {
    int *ptr = vetor;
    printf("Elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
}

int main() {
    int meuVetor[] = {10, 20, 30, 40, 50};
    int tamanhoVetor = sizeof(meuVetor) / sizeof(meuVetor[0]);

    imprimirVetor(meuVetor, tamanhoVetor);

    return 0;
}