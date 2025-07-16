#include <stdio.h>

char obterConceito(float mediaFinal) {
    if (mediaFinal >= 9.0 && mediaFinal <= 10.0) {
        return 'A';
    } else if (mediaFinal >= 7.0 && mediaFinal < 9.0) {
        return 'B';
    } else if (mediaFinal >= 5.0 && mediaFinal < 7.0) {
        return 'C';
    } else if (mediaFinal >= 0.0 && mediaFinal < 5.0) {
        return 'D';
    } else {
        return 'I';
    }
}

int main() {
    printf("Media 9.5: Conceito %c\n", obterConceito(9.5));
    printf("Media 7.8: Conceito %c\n", obterConceito(7.8));
    printf("Media 6.2: Conceito %c\n", obterConceito(6.2));
    printf("Media 3.1: Conceito %c\n", obterConceito(3.1));
    printf("Media -1.0: Conceito %c\n", obterConceito(-1.0));
    printf("Media 10.0: Conceito %c\n", obterConceito(10.0));
    return 0;
}