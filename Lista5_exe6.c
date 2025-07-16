#include <stdio.h>

int main() {
    int meuArray[5];
    int *ptr = meuArray;

    printf("Digite 5 valores inteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    printf("\nEnderecos das posicoes com valores pares:\n");
    for (int i = 0; i < 5; i++) {
        if (*(ptr + i) % 2 == 0) {
            printf("Endereco de %d (valor %d): %p\n", i, *(ptr + i), (void*)(ptr + i));
        }
    }

    return 0;
}