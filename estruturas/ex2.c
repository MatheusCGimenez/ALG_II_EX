#include <stdio.h>
#include <math.h>

struct Coords
{
    int x, y;
};

int main()
{

    struct Coords defineCoods;

    printf("Insira o X: \n");
    scanf("%d", &defineCoods.x);
    getchar();
    printf("Insira o Y: \n");
    scanf("%d", &defineCoods.y);
    getchar();

    int origem = sqrt((defineCoods.x * defineCoods.x) + (defineCoods.y * defineCoods.y));

    printf("A distancia do ponto (%d, %d) ate a origem (0, 0) eh de: %d", defineCoods.x, defineCoods.y, origem);

    return 0;
}