/*Ejemplos de funciones en C*/

#include <stdio.h>

/*
tipo Retorno int, char, float, double
nombre funcion (parametros)

parametros -> tipo nombre, tipo nombre2, tipo  nombre3

return valor 
*/


int sumaNros(int nro) // variable global 
{
  int i,  suma = 0;
  for(i=1; i<=nro; i++)
    {
      suma +=i;
    }

  return suma;
}

void mostrarResultado(int valor) // variable global
{
   printf("La suma es %d", valor);
}

int main() // esta es la variable local donde pongo todas las variables que voy a usar, las llamo aca
{
    int nro, resultado;
    printf("Ingrese un nro: ");
    scanf ("%d", &nro);
    resultado = sumaNros(nro);
    mostrarResultado(resultado);

    return 0;
}