#include <stdio.h>

struct Atleta
{
  char nome[100], esporte[20];
  int idade;
  float altura;
};

int main()
{

  struct Atleta vetorAtleta[5];

  for (int i = 0; i < 5; i++)
  {
    printf("=== ATLETA (%d) === \n", i + 1);
    printf("NOME: \n");
    fgets(vetorAtleta[i].nome, sizeof(vetorAtleta[i].nome), stdin);
    printf("ESPORTE: \n");
    fgets(vetorAtleta[i].esporte, sizeof(vetorAtleta[i].esporte), stdin);
    printf("IDADE: \n");
    scanf("%d", &vetorAtleta[i].idade);
    printf("ALTURA: \n");
    scanf("%f", &vetorAtleta[i].altura);
    getchar();
  }

  int atletaMaisAlto = 0;
  int atletaMaisVelho = 0;

  for (int i = 1; i < 5; i++)
  {
    if (vetorAtleta[i].idade > vetorAtleta[atletaMaisVelho].idade)
    {
      atletaMaisVelho = i;
    }

    if (vetorAtleta[i].altura < vetorAtleta[atletaMaisAlto].altura)
    {
      atletaMaisAlto = i;
    }
  }

  printf("================ \n");
  printf("O atleta mais velho eh o %s, com %d anos!", vetorAtleta[atletaMaisVelho].nome, vetorAtleta[atletaMaisVelho].idade);
  printf("O atleta mais alto eh o %s, com %.2f cm!", vetorAtleta[atletaMaisAlto].nome, vetorAtleta[atletaMaisAlto].altura);

  return 0;
}
