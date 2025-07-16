#include <stdio.h>

int main() {
    int var1;
    int var2;

    printf("Digite o valor para a primeira variavel: ");
    scanf("%d", &var1);
    printf("Digite o valor para a segunda variavel: ");
    scanf("%d", &var2);

    int *ptr1 = &var1;
    int *ptr2 = &var2;

    printf("Endereco de var1: %p\n", (void*)ptr1);
    printf("Endereco de var2: %p\n", (void*)ptr2);

    if (ptr1 > ptr2) {
        printf("O conteudo do maior endereco (%p) e: %d\n", (void*)ptr1, *ptr1);
    } else if (ptr2 > ptr1) {
        printf("O conteudo do maior endereco (%p) e: %d\n", (void*)ptr2, *ptr2);
    } else {
        printf("Os enderecos sao iguais. Conteudo: %d\n", *ptr1);
    }

    return 0;
}