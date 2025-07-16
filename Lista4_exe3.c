#include <stdio.h>
#include <math.h>

struct Coords
{
    int x, y;
};

int calculoDistancia(int p1_x, int p1_y, int p2_x, int p2_y)
{
    int distanciaDosPontos = sqrt((p2_x - p1_x) * (p2_x - p1_x) + (p2_y - p1_y) * (p2_y - p1_y));

    return distanciaDosPontos;
}

int main()
{

    struct Coords p1;
    struct Coords p2;

    printf("Digite o valor de X de p1: \n");
    scanf("%d", &p1.x);
    getchar();
    printf("Digite o valor de Y de p1: \n");
    scanf("%d", &p1.y);
    getchar();

    printf("Digite o valor de X de p2: \n");
    scanf("%d", &p2.x);
    getchar();
    printf("Digite o valor de Y de p2: \n");
    scanf("%d", &p2.y);
    getchar();

    int distancia = calculoDistancia(p1.x, p1.y, p2.x, p2.y);

    printf("A distancia do ponto (%d, %d) ao ponto (%d, %d) eh de: %d", p1.x, p1.y, p2.x, p2.y, distancia);

    return 0;
}