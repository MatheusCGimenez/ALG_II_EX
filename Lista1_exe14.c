#include <stdio.h>

float calcularMediaAritmeticaPositivos() {
    float somaValores = 0.0;
    int quantidadeValores = 0;
    int valorLido;

    printf("Por favor, digite valores inteiros positivos.\n");
    printf("Para parar, digite um valor nao positivo (zero ou negativo).\n");

    while (1) {
        printf("Digite um valor: ");
        if (scanf("%d", &valorLido) != 1) {
            printf("Entrada invalida. Certifique-se de digitar um numero inteiro.\n");
            while (getchar() != '\n');
            continue;
        }

        if (valorLido <= 0) {
            break;
        }

        somaValores += valorLido;
        quantidadeValores++;
    }

    if (quantidadeValores > 0) {
        return somaValores / quantidadeValores;
    } else {
        return 0.0;
    }
}

int main() {
    float media = calcularMediaAritmeticaPositivos();

    if (media > 0) {
        printf("A media aritmetica dos valores positivos inseridos e: %.2f\n", media);
    } else {
        printf("Nenhum valor positivo foi inserido para calcular a media.\n");
    }
    return 0;
}