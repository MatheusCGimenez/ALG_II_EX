#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inverte_string(const char* original) {
    int tamanho = strlen(original);
    char* invertida = (char*) malloc((tamanho + 1) * sizeof(char));

    if (invertida == NULL) {
        return NULL;
    }

    for (int i = 0; i < tamanho; i++) {
        invertida[i] = original[tamanho - 1 - i];
    }
    invertida[tamanho] = '\0'; 

    return invertida;
}

int main() {
    char texto[] = "matheus";
    char* texto_invertido = inverte_string(texto);

    if (texto_invertido != NULL) {
        printf("Original: %s\n", texto);
        printf("Invertida: %s\n", texto_invertido);
        free(texto_invertido);
    }
    return 0;
}