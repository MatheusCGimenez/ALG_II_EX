#include <stdio.h>

int ehPerfeito(int numero) {
    if (numero <= 0) {
        return 0;
    }
    int somaDivisores = 1;

    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            somaDivisores += i;
            if (i * i != numero) {
                somaDivisores += numero / i;
            }
        }
    }
    return (somaDivisores == numero) ? 1 : 0;
}

int main() {
    printf("O numero 6 e perfeito? %s\n", ehPerfeito(6) ? "Sim" : "Nao");
    printf("O numero 28 e perfeito? %s\n", ehPerfeito(28) ? "Sim" : "Nao");
    printf("O numero 12 e perfeito? %s\n", ehPerfeito(12) ? "Sim" : "Nao");
    printf("O numero 7 e perfeito? %s\n", ehPerfeito(7) ? "Sim" : "Nao");
    printf("O numero 0 e perfeito? %s\n", ehPerfeito(0) ? "Sim" : "Nao");
    return 0;
}