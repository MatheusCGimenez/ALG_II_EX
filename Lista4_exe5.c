#include <stdio.h>
#include <stdbool.h>

struct Ponto {
    float x;
    float y;
};

struct Retangulo {
    struct Ponto superiorEsquerdo;
    struct Ponto inferiorDireito;
};

bool pontoDentroDoRetangulo(struct Retangulo r, struct Ponto p) {
    return (p.x >= r.superiorEsquerdo.x && p.x <= r.inferiorDireito.x) &&
           (p.y <= r.superiorEsquerdo.y && p.y >= r.inferiorDireito.y);
}

int main() {
    struct Retangulo ret;
    struct Ponto ponto;

    printf("Digite as coordenadas do ponto superior esquerdo do retangulo (x y): ");
    scanf("%f %f", &ret.superiorEsquerdo.x, &ret.superiorEsquerdo.y);

    printf("Digite as coordenadas do ponto inferior direito do retangulo (x y): ");
    scanf("%f %f", &ret.inferiorDireito.x, &ret.inferiorDireito.y);

    printf("Digite as coordenadas do ponto a ser verificado (x y): ");
    scanf("%f %f", &ponto.x, &ponto.y);

    if (pontoDentroDoRetangulo(ret, ponto)) {
        printf("O ponto esta DENTRO do retangulo.\n");
    } else {
        printf("O ponto esta FORA do retangulo.\n");
    }

    return 0;
}
