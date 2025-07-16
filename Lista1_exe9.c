#include <stdio.h>

int verificarPositivoNegativo(int valor) {
    if (valor > 0) {
        return 1;
    } else if (valor < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    printf("O numero 10 e: %d\n", verificarPositivoNegativo(10));
    printf("O numero -5 e: %d\n", verificarPositivoNegativo(-5));
    printf("O numero 0 e: %d\n", verificarPositivoNegativo(0));
    return 0;
}