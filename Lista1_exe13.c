
void verificarTipoTriangulo(double ladoX, double ladoY, double ladoZ) {
    if (ladoX + ladoY > ladoZ && ladoX + ladoZ > ladoY && ladoY + ladoZ > ladoX) {
        if (ladoX == ladoY && ladoY == ladoZ) {
            printf("Os lados %.2f, %.2f e %.2f formam um Triangulo Equilatero.\n", ladoX, ladoY, ladoZ);
        } else if (ladoX == ladoY || ladoX == ladoZ || ladoY == ladoZ) {
            printf("Os lados %.2f, %.2f e %.2f formam um Triangulo Isosceles.\n", ladoX, ladoY, ladoZ);
        } else {
            printf("Os lados %.2f, %.2f e %.2f formam um Triangulo Escaleno.\n", ladoX, ladoY, ladoZ);
        }
    } else {
        printf("Os lados %.2f, %.2f e %.2f NAO podem formar um triangulo.\n", ladoX, ladoY, ladoZ);
    }
}

int main() {
    printf("--- Testes de Triangulos ---\n");
    verificarTipoTriangulo(3.0, 4.0, 5.0);
    verificarTipoTriangulo(5.0, 5.0, 5.0);
    verificarTipoTriangulo(4.0, 4.0, 6.0);
    verificarTipoTriangulo(1.0, 2.0, 5.0);
    verificarTipoTriangulo(7.0, 7.0, 7.0);
    verificarTipoTriangulo(8.0, 8.0, 10.0);
    return 0;
}