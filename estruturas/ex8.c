#include <stdio.h>
#define MAX 100

struct DataNascimento
{
  int dia, mes, ano;
};

struct Pessoa
{
  char nome[MAX];
  struct DataNascimento data_nascimento;
};

int main()
{

  struct Pessoa vetorPessoa[6];

  for (int i = 0; i < 6; i++)
  {
    printf("=== PESSOA (%d) === \n", i + 1);
    printf("NOME: \n");
    fgets(vetorPessoa[i].nome, sizeof(vetorPessoa[i].nome), stdin);
    printf("DATA DE NASCIMENTO (dia, mes, ano): \n");
    scanf("%d %d %d", &vetorPessoa[i].data_nascimento.dia, &vetorPessoa[i].data_nascimento.mes, &vetorPessoa[i].data_nascimento.ano);
    getchar();
  }

  for (int i = 0; i < 6; i++)
  {
    
  }

  printf("=== PESSOAS MAIS VELHA === \n");

  return 0;
}