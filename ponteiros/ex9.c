#include <stdio.h>

void imprimirVetor(int *vetor, int tamanho) {
    int *fim = vetor + tamanho;
    while (vetor < fim) {
        printf("%d ", *vetor);
        vetor++; 
    }
    printf("\n");
}

int main() {
    int numeros[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    imprimirVetor(numeros, tamanho);

    return 0;
}
