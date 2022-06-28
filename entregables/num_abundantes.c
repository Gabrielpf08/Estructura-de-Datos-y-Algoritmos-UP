#include <stdio.h>
int main()
{
int numero = 1, contador = 1, suma, i;
while (contador <= 4)
{
suma = 0; //suma de los divisores
for (i=1; i<numero; i++)
{
if (numero % i == 0)
{
suma += i;
}
}
if (suma > numero)
{
printf("\n%d Es un numero abundante\n",numero);
contador++;
}
numero++;
}
}