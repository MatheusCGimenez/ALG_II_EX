#include <stdio.h>

int main() {
    int var1 = 10;
    int var2 = 20;

    int *ptr1 = &var1;
    int *ptr2 = &var2;

    printf("Endereco de var1: %p\n", (void*)ptr1);
    printf("Endereco de var2: %p\n", (void*)ptr2);

    if (ptr1 > ptr2) {
        printf("O maior endereco e o de var1: %p\n", (void*)ptr1);
    } else if (ptr2 > ptr1) {
        printf("O maior endereco e o de var2: %p\n", (void*)ptr2);
    } else {
        printf("Os enderecos sao iguais.\n");
    }

    return 0;
}