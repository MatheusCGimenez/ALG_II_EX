#include <stdio.h>
#include <stdlib.h>

int* cria_vetor_preenchido(int n, int valor) {
    if (n <= 0) {
        return NULL;
    }
    int* vetor = (int*) malloc(n * sizeof(int));
    if (vetor == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        vetor[i] = valor;
    }
    return vetor;
}

int main() {
    int tamanho = 8;
    int valor_preenchimento = 7;
    int* meu_vetor = cria_vetor_preenchido(tamanho, valor_preenchimento);

    if (meu_vetor != NULL) {
        printf("Vetor de %d posicoes preenchido com o numero %d: ", tamanho, valor_preenchimento);
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", meu_vetor[i]);
        }
        printf("\n");
        free(meu_vetor);
    }
    return 0;
}