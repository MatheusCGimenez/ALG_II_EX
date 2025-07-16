#include <stdio.h>
#include <stdlib.h>

struct Cadastro {
    char nome[100];
    int idade;
    char endereco[200];
};

struct Cadastro* alocaVetorCadastro(int n) {
    if (n <= 0) {
        return NULL;
    }

    struct Cadastro* vetor = (struct Cadastro*) malloc(n * sizeof(struct Cadastro));
    if (vetor == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        printf("\n--- Inserindo dados da Pessoa %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", vetor[i].nome);
        printf("Idade: ");
        scanf("%d", &vetor[i].idade);
        printf("Endereco: ");
        scanf(" %[^\n]s", vetor[i].endereco);
    }
    return vetor;
}

int main() {
    int numero_de_pessoas;
    printf("Digite o numero de pessoas para cadastrar: ");
    scanf("%d", &numero_de_pessoas);

    struct Cadastro* meus_cadastros = alocaVetorCadastro(numero_de_pessoas);

    if (meus_cadastros != NULL) {
        printf("\n--- Cadastros Realizados ---\n");
        for (int i = 0; i < numero_de_pessoas; i++) {
            printf("Pessoa %d: %s, %d anos, mora em %s\n",
                   i + 1,
                   meus_cadastros[i].nome,
                   meus_cadastros[i].idade,
                   meus_cadastros[i].endereco);
        }
        free(meus_cadastros);
    }

    return 0;
}