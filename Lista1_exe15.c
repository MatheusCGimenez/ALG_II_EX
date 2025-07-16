#include <stdio.h>

double calcularPotencia(double base, int expoente)
{
  double resultado = 1.0;

  if (expoente == 0)
  {
    return 1.0;
  }

  if (expoente > 0)
  {
    for (int i = 0; i < expoente; i++)
    {
      resultado *= base;
    }
  }
  else
  {
    int absExpoente = -expoente;
    for (int i = 0; i < absExpoente; i++)
    {
      resultado *= base;
    }
    resultado = 1.0 / resultado;
  }

  return resultado;
}

int main()
{
  printf("2 elevado a 3 = %.2f\n", calcularPotencia(2, 3));
  printf("5 elevado a 0 = %.2f\n", calcularPotencia(5, 0));
  printf("2 elevado a -2 = %.4f\n", calcularPotencia(2, -2));
  printf("3 elevado a 4 = %.2f\n", calcularPotencia(3, 4));
  printf("10 elevado a 1 = %.2f\n", calcularPotencia(10, 1));
  printf("4 elevado a -1 = %.2f\n", calcularPotencia(4, -1));
  return 0;
}