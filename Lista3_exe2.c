#include <stdio.h>

struct Aluno {
    int matricula;
    char nome[80];
    float notas[3];
};

int main() {
    printf("Tamanho em bytes da estrutura Aluno: %zu\n", sizeof(struct Aluno));

    return 0;
}