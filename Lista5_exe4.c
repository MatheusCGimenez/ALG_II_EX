#include <stdio.h>

int main() {
    float minhaMatriz[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Endereco da posicao [%d][%d]: %p\n", i, j, (void*)&minhaMatriz[i][j]);
        }
    }

    return 0;
}