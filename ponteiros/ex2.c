#include <stdio.h>

int main() {
    int v1, v2;

    printf("Digite o v1: \n");
    scanf("%d", &v1);
    printf("Digite o v2: \n");
    scanf("%d", &v2);

    int *pv1 = &v1;
    int *pv2 = &v2;


    if (*pv1 > *pv2) {
        printf("O endereco de v1 eh maior: %d\n", *pv1);
    } else {
        printf("O endereco de v2 eh maior: %d\n", *pv2);
    }

    return 0;
}
