/*CARACTERES*/


/* Aca vemos un ejemplo de caracteres, la consigna era contar cuantas palabras terminaban en "s"*/ 

#include <stdio.h>

int main() 
{
  int c, cont=0, aux;
  printf("Ingrese la frase: ");
  c=getchar();
  while(c!='.')
  {   
    while(c!=' ' && c !='.')
    {
      aux=c; // como la "c" recorre todas las frases, dejo que el "aux" almacene la ultima letra de cada frase, que en este caso la condicion es que termine en "s"
      c=getchar();
    }

    if(aux == 's') // se pone el "if" afuera del "while" porque (mirar la clase)
    {
        cont++;
    }

    while(c==' '&& c!='.') // esto se hace para cuando hay muchos espacios entre palabra y palabra, de esta manera no sale error
    {
      c=getchar();
    }
    
   
  }
  printf("\nLa cantidad de palabras terminadas en S son: %d", cont);

  return 0;
}
