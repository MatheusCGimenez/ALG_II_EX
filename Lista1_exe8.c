#include <stdio.h>

void obterCategoriaNadador(int idade, char *categoria) {
    if (idade >= 5 && idade <= 7) {
        sprintf(categoria, "Infantil A");
    } else if (idade >= 8 && idade <= 10) {
        sprintf(categoria, "Infantil B");
    } else if (idade >= 11 && idade <= 13) {
        sprintf(categoria, "Juvenil A");
    } else if (idade >= 14 && idade <= 17) {
        sprintf(categoria, "Juvenil B");
    } else if (idade >= 18) {
        sprintf(categoria, "Adulto");
    } else {
        sprintf(categoria, "Nao Classificado");
    }
}

int main() {
    char categoriaNadador[25];

    obterCategoriaNadador(6, categoriaNadador);
    printf("Nadador com 6 anos: Categoria %s\n", categoriaNadador);

    obterCategoriaNadador(9, categoriaNadador);
    printf("Nadador com 9 anos: Categoria %s\n", categoriaNadador);

    obterCategoriaNadador(12, categoriaNadador);
    printf("Nadador com 12 anos: Categoria %s\n", categoriaNadador);

    obterCategoriaNadador(16, categoriaNadador);
    printf("Nadador com 16 anos: Categoria %s\n", categoriaNadador);

    obterCategoriaNadador(20, categoriaNadador);
    printf("Nadador com 20 anos: Categoria %s\n", categoriaNadador);

    obterCategoriaNadador(4, categoriaNadador);
    printf("Nadador com 4 anos: Categoria %s\n", categoriaNadador);
    return 0;
}