#include <stdio.h>

const char* imprimirTexto(const char *texto) {
    printf("%s\n", texto);
    return "Ok";
}

int main() {
    const char *statusRetornado = imprimirTexto("Este texto sera impresso e o status 'Ok' retornado.\n");
    printf("Ok: %s\n", statusRetornado);
    return 0;
}