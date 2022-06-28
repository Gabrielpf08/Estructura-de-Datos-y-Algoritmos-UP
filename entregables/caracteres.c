//Desarrollar un programa en C que permita leer un texto carácter a carácter terminado en punto. Por fin de proceso
//a) Mostrar el texto con tres blancos de separación después de cada palabra que finaliza en s y tiene al menos 2 vocales.
//b) Contar cuantas palabras de mas de 4 caracteres empiezan y terminan con la misma letra.
#include <stdio.h>
void inicio_fin_misma_letra(){
int c, cont = 0, contLetras = 0, contPal=0;
int ultimo, primera;

	c =getchar();
	while (c != '.' && c == ' ')
		c = getchar();
	while (c != '.')
		{
			primera = c;
			while (c != '.' && c != ' '){
				contLetras ++;
        putchar(c);
				ultimo = c;
				c = getchar();
			}
			if (contLetras > 4 && primera == ultimo){
				cont ++;
        putchar(' ');
        putchar(' ');
        putchar(' ');
      }
      contLetras = 0;
			while (c != '.' && c == ' ')
				c = getchar();	
		}
		printf ("\nCantidad de palabras que inician y terminan con la misma letra: %d", cont);
}

void finaliza_s_2_vocales(){
int c, cont = 0, contv = 0;
	int ultimo;

	c =getchar();
	while (c != '.' && c == ' ')
		c = getchar();
	while (c != '.')
		{

			while (c != '.' && c != ' '){
				ultimo = c;
          if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				  contv ++;
				  c = getchar();

			}

			if (ultimo == 's' && contv >= 2){
				cont ++;
      }

			while (c != '.' && c == ' ')
				c = getchar();

		}
		printf ("\nCantidad de palabras que terminan en s y tiene minimo dos vocales: %d", cont);

}

int main(){
  inicio_fin_misma_letra();
  printf("\nRescriba la frase. ");
  finaliza_s_2_vocales();
}

