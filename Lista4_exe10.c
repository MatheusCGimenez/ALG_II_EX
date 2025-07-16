#include <stdio.h>

struct Atleta
{
  int idade;
};

int main()
{
  struct Atleta vetorAtleta[5];

  for (int i = 0; i < 5; i++)
  {
    printf("=== ATLETA (%d) === \n", i + 1);
    printf("IDADE: ");
    scanf("%d", &vetorAtleta[i].idade);
  }

  for (int i = 0; i < 5 - 1; i++)
  {
    for (int j = i + 1; j < 5; j++)
    {
      if (vetorAtleta[i].idade < vetorAtleta[j].idade)
      {
        struct Atleta temp = vetorAtleta[i];
        vetorAtleta[i] = vetorAtleta[j];
        vetorAtleta[j] = temp;
      }
    }
  }

  printf("\n=== ATLETAS EM ORDEM DE IDADE (MAIS VELHO -> MAIS NOVO) ===\n");
  for (int i = 0; i < 5; i++)
  {
    printf("ATLETA %d - IDADE: %d\n", i + 1, vetorAtleta[i].idade);
  }

  return 0;
}
