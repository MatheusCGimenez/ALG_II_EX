#include <stdio.h>

int verificarParOuImpar(int valor) {
    if (valor % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    printf("O numero 10 e par? %d\n", verificarParOuImpar(10));
    printf("O numero 7 e par? %d\n", verificarParOuImpar(7));
    printf("O numero 0 e par? %d\n", verificarParOuImpar(0));
    return 0;
}