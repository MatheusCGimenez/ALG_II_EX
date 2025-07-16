#include <stdio.h>
#include <math.h>

struct Ponto {
    float x;
    float y;
};

struct Retangulo {
    struct Ponto superiorEsquerdo;
    struct Ponto inferiorDireito;
};

float calcularArea(struct Retangulo r) {
    float largura = fabs(r.inferiorDireito.x - r.superiorEsquerdo.x);
    float altura  = fabs(r.superiorEsquerdo.y - r.inferiorDireito.y);
    return largura * altura;
}

float calcularPerimetro(struct Retangulo r) {
    float largura = fabs(r.inferiorDireito.x - r.superiorEsquerdo.x);
    float altura  = fabs(r.superiorEsquerdo.y - r.inferiorDireito.y);
    return 2 * (largura + altura);
}

float calcularDiagonal(struct Retangulo r) {
    float largura = fabs(r.inferiorDireito.x - r.superiorEsquerdo.x);
    float altura  = fabs(r.superiorEsquerdo.y - r.inferiorDireito.y);
    return sqrt(largura * largura + altura * altura);
}

int main() {
    struct Retangulo ret;

    printf("Digite as coordenadas do ponto superior esquerdo (x y): ");
    scanf("%f %f", &ret.superiorEsquerdo.x, &ret.superiorEsquerdo.y);

    printf("Digite as coordenadas do ponto inferior direito (x y): ");
    scanf("%f %f", &ret.inferiorDireito.x, &ret.inferiorDireito.y);

    float area = calcularArea(ret);
    float perimetro = calcularPerimetro(ret);
    float diagonal = calcularDiagonal(ret);

    printf("AREA: %.2f\n", area);
    printf("PERIMETRO: %.2f\n", perimetro);
    printf("DIAGONAL: %.2f\n", diagonal);

    return 0;
}
