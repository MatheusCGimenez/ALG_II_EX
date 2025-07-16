#include <stdio.h>

int main()
{
  int a;
  int *b;
  int **c;
  int ***d;

  printf("Digite um valor inteiro para 'a': ");
  scanf("%d", &a);

  b = &a;
  c = &b;
  d = &c;

  printf("Valor de 'a': %d\n", a);

  printf("Dobro de 'a' (usando *b): %d\n", (*b) * 2);
  printf("Triplo de 'a' (usando **c): %d\n", (**c) * 3);
  printf("Quadruplo de 'a' (usando ***d): %d\n", (***d) * 4);

  return 0;
}