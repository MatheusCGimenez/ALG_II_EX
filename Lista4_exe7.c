#include <stdio.h>

struct Hora
{
  int hora, minutos, segundos;
};

int main()
{

  struct Hora vetorHora[5];
  int maiorHora[5];
  int k = 0;

  for (int i = 0; i < 5; i++)
  {
    printf("=== POSICAO [%d] === \n", i);
    printf("Digite a hora: \n");
    scanf("%d", &vetorHora[i].hora);
    printf("Digite o minuto: \n");
    scanf("%d", &vetorHora[i].minutos);
    printf("Digite o segundo: \n");
    scanf("%d", &vetorHora[i].segundos);

    if (vetorHora[i].hora > 24)
    {
      printf("A hora precisa ser inferior a 24!");
      return 1;
    }
    else if ((vetorHora[i].minutos > 60) || vetorHora[i].segundos > 60)
    {
      printf("O minuto/segundo deve ser inferior a 60");
      return 1;
    }

    maiorHora[k] = vetorHora[i].hora;
    k++;
  }

  for (int i = 0; i < 5; i++)
  {
    for (int j = i; j < 5; j++)
    {
      if (maiorHora[i] < maiorHora[j])
      {
        int temp = maiorHora[i];
        maiorHora[i] = maiorHora[j];
        maiorHora[j] = temp;
      }
    }
  }

  printf("A maior hora eh: %d", maiorHora[0]);

  return 0;
}