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
  int k = 0;
  int vetorNota[15];

  for (int i = 0; i < 5; i++)
  {
    printf("=== DIGITE AS INFORMACOES DO ALUNO [%d] === \n", i + 1);
    printf("MATRICULA: \n");
    scanf("%d", &aluno[i].matricula);
    getchar();
    printf("NOME: \n");
    fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);

    printf("=== AGORA, VAMOS AS NOTAS DO ALUNO [%d] === \n", i + 1);

    for (int j = 0; j < 3; j++)
    {
      printf("DIGITE A NOTA [%d]", j + 1);
      scanf("%d", &aluno[i].notas[j]);

      vetorNota[k] = aluno[i].notas[j];
      k++;
    }
  }

  for (int i = 0; i < 15; i++){
    printf("%d \n", vetorNota[i]);
  }
}