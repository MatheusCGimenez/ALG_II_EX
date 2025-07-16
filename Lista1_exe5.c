#include <stdio.h>

void converterSegundosParaHMS(long totalSegundos) {
    long horas = totalSegundos / 3600;
    long segundosRestantes = totalSegundos % 3600;
    long minutos = segundosRestantes / 60;
    long segundos = segundosRestantes % 60;

    printf("Tempo total: %ld horas, %ld minutos e %ld segundos.\n", horas, minutos, segundos);
}

int main() {
    printf("Convertendo 3661 segundos:\n");
    converterSegundosParaHMS(3661);
    printf("\nConvertendo 7200 segundos:\n");
    converterSegundosParaHMS(7200);
    printf("\nConvertendo 59 segundos:\n");
    converterSegundosParaHMS(59);
    return 0;
}