#include <stdio.h>
#include <math.h>

void calcularEImprimirBhaskara(double a, double b, double c) {
    double delta = b * b - 4 * a * c;

    if (a == 0) {
        printf("Nao e uma equacao do segundo grau (o coeficiente 'a' e zero).\n");
    } else if (delta < 0) {
        printf("Nao e possivel calcular as raizes reais (delta negativo).\n");
    } else {
        double raiz1 = (-b + sqrt(delta)) / (2 * a);
        double raiz2 = (-b - sqrt(delta)) / (2 * a);
        printf("As raizes da equacao sao:\n");
        printf("Raiz 1: %.2f\n", raiz1);
        printf("Raiz 2: %.2f\n", raiz2);
    }
}

int main() {
    printf("--- Teste 1: x^2 - 5x + 6 = 0 ---\n");
    calcularEImprimirBhaskara(1, -5, 6);
    return 0;
}