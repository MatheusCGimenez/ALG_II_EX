#include <stdio.h>

void preencherVetor(int *vetor, int tamanho, int valor) {
    int *ptr = vetor;
    for (int i = 0; i < tamanho; i++) {
        *ptr = valor;
        ptr++;
    }
}

int main() {
    int meuVetor[5];
    int tamanhoVetor = sizeof(meuVetor) / sizeof(meuVetor[0]);
    int valorParaPreencher = 7;

    preencherVetor(meuVetor, tamanhoVetor, valorParaPreencher);

    printf("Vetor preenchido:\n");
    for (int i = 0; i < tamanhoVetor; i++) {
        printf("%d ", meuVetor[i]);
    }
    printf("\n");

    return 0;
}