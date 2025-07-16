#include <stdio.h>
#include <stdlib.h>

int* aloca_vetor_validado(int n) {
    if (n <= 0) {
        return NULL;
    }
    int* vetor = (int*) malloc(n * sizeof(int));
    return vetor;
}

int main() {
    int* vetor1 = aloca_vetor_validado(5);
    if (vetor1 != NULL) {
        printf("Vetor de 5 posicoes alocado com sucesso.\n");
        free(vetor1);
    }

    int* vetor2 = aloca_vetor_validado(-3);
    if (vetor2 == NULL) {
        printf("Alocacao do vetor de -3 posicoes falhou, como esperado.\n");
    }
    return 0;
}