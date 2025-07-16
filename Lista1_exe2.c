#include <stdio.h>

void imprimirTexto(const char *texto) {
    printf("%s\n", texto);
}

int main() {
    imprimirTexto("Ola, mundo!\n");
    return 0;
}