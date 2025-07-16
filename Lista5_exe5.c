#include <stdio.h>

int main() {
    int meuArray[5];
    int *ptr = meuArray;

    printf("Digite 5 valores inteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    printf("\nO dobro de cada valor lido:\n");
    for (int i = 0; i < 5; i++) {
        printf("Dobro de %d: %d\n", *(ptr + i), *(ptr + i) * 2);
    }

    return 0;
}