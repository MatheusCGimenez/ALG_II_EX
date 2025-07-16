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

    printf("DATA DE NASCIMENTO (formato: dia mes ano): \n");
    scanf("%d %d %d", &vetorPessoa[i].data_nascimento.dia, &vetorPessoa[i].data_nascimento.mes, &vetorPessoa[i].data_nascimento.ano);

    getchar();
  }


  int indiceMaisVelha = 0;
  int indiceMaisNova = 0;

  for (int i = 1; i < 6; i++)
  {

    if (vetorPessoa[i].data_nascimento.ano < vetorPessoa[indiceMaisVelha].data_nascimento.ano)
    {
      indiceMaisVelha = i;
    }
    else if (vetorPessoa[i].data_nascimento.ano == vetorPessoa[indiceMaisVelha].data_nascimento.ano && vetorPessoa[i].data_nascimento.mes < vetorPessoa[indiceMaisVelha].data_nascimento.ano)
    {
      indiceMaisVelha = i;
    }
    else if (vetorPessoa[i].data_nascimento.ano == vetorPessoa[indiceMaisVelha].data_nascimento.ano && vetorPessoa[i].data_nascimento.mes == vetorPessoa[indiceMaisVelha].data_nascimento.ano && vetorPessoa[i].data_nascimento.dia < vetorPessoa[indiceMaisVelha].data_nascimento.dia)
    {
      indiceMaisVelha = i;
    }


    if (vetorPessoa[i].data_nascimento.ano > vetorPessoa[indiceMaisNova].data_nascimento.ano)
    {
      indiceMaisNova = i;
    }
    else if (vetorPessoa[i].data_nascimento.ano == vetorPessoa[indiceMaisNova].data_nascimento.ano && vetorPessoa[i].data_nascimento.mes > vetorPessoa[indiceMaisNova].data_nascimento.mes)
    {
      indiceMaisNova = 1;
    }
    else if (vetorPessoa[i].data_nascimento.ano == vetorPessoa[indiceMaisNova].data_nascimento.ano && vetorPessoa[i].data_nascimento.mes == vetorPessoa[indiceMaisNova].data_nascimento.mes && vetorPessoa[i].data_nascimento.dia > vetorPessoa[indiceMaisNova].data_nascimento.dia)
    {
      indiceMaisNova = i;
    }
  }

  printf("---------------- \n");
  printf("%s é a pessoa mais velha, com %d anos! \n", vetorPessoa[indiceMaisVelha].nome, 2025 - vetorPessoa[indiceMaisVelha].data_nascimento.ano);
  printf("%s é a pessoa mais nova, com %d anos! \n", vetorPessoa[indiceMaisNova].nome, 2025 - vetorPessoa[indiceMaisNova].data_nascimento.ano);

  return 0;
}