#include <stdio.h>

int main() {
    float meuArray[10];
    float *ptr = meuArray;

    for (int i = 0; i < 10; i++) {
        printf("Endereco da posicao %d: %p\n", i, (void*)(ptr + i));
    }

    return 0;
}