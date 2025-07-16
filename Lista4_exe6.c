#include <stdio.h>

struct Aluno
{
  int matricula;
  char nome[100];
  int notas[3];
};

int main()
{
  struct Aluno aluno[5];
  float mediaAlunos[5];

  for (int i = 0; i < 5; i++)
  {
    printf("=== DIGITE AS INFORMACOES DO ALUNO [%d] === \n", i + 1);
    printf("MATRICULA: ");
    scanf("%d", &aluno[i].matricula);
    getchar();

    printf("NOME: ");
    fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);

    float soma = 0;
    printf("=== AGORA, VAMOS AS NOTAS DO ALUNO [%d] === \n", i + 1);
    for (int j = 0; j < 3; j++)
    {
      printf("DIGITE A NOTA [%d]: ", j + 1);
      scanf("%d", &aluno[i].notas[j]);
      soma += aluno[i].notas[j];
    }
    mediaAlunos[i] = soma / 3.0;
  }

  int indiceMaior = 0;
  for (int i = 1; i < 5; i++)
  {
    if (mediaAlunos[i] > mediaAlunos[indiceMaior])
    {
      indiceMaior = i;
    }
  }

  printf("\n=== ALUNO COM MAIOR MEDIA ===\n");
  printf("MATRICULA: %d\n", aluno[indiceMaior].matricula);
  printf("NOME: %s", aluno[indiceMaior].nome);
  printf("ME]]DIA: %.2f\n", mediaAlunos[indiceMaior]);

  return 0;
}
