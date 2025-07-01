#include <stdio.h>
#define MAX 100

struct dados
{
    char nome[MAX], endereco[MAX];
    int idade;
};

int main()
{

    struct dados Person;

    printf("Digite o seu nome: \n");
    fgets(Person.nome, sizeof(Person.nome), stdin);
    printf("Digite a sua idade: \n");
    scanf("%d", &Person.idade);
    getchar();
    printf("Digite o seu endereco: \n");
    fgets(Person.endereco, sizeof(Person.endereco), stdin);

    printf("=== DADOS DO USUÁRIO === \n");

    printf("Nome: %s \n", Person.nome);
    printf("Idade: %d \n", Person.idade);
    printf("Endereco: %s \n", Person.endereco);

    return 0;
}