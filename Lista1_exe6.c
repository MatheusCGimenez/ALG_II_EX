#include <stdio.h>

int calcularIdadeEmDias(int anos, int meses, int dias) {
    return (anos * 365) + (meses * 30) + dias;
}

int main() {
    int idadeTotalEmDias = calcularIdadeEmDias(2, 3, 15);
    printf("A idade expressa em dias e: %d dias.\n", idadeTotalEmDias);
    return 0;
}