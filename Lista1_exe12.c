#include <stdio.h>

void ordenarEImprimirNumeros(int num1, int num2, int num3) {
    int temp;

    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num2 > num3) {
        temp = num2;
        num2 = num3;
        num3 = temp;
    }
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    printf("Os valores ordenados em ordem crescente sao: %d, %d, %d\n", num1, num2, num3);
}

int main() {
    ordenarEImprimirNumeros(5, 2, 8);
    ordenarEImprimirNumeros(10, 1, 5);
    ordenarEImprimirNumeros(3, 3, 1);
    ordenarEImprimirNumeros(9, 7, 7);
    return 0;
}