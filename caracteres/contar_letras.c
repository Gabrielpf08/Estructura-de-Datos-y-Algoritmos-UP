/*Este es un ejemplo en el que vemos cuantas "a" hay en una oracion*/

#include <stdio.h>

int main()
{
    int c, cont = 0;
    
    c =getchar(); //si no se pone este, no te toma la primer letra
    while (c != '\n')
    {
        putchar (c);
        if (c == 'a') //se pone aca porque si lo pones abajo del "getchar" no tratas el caracter y directamente toma el que sigue
                      //(esto en caso de que la primer letra sea con "a" como dice la condicion)
        {
            cont ++;
        }
        c= getchar();
    }
    printf ("\nLa cantidad de A es: %d", cont);
    
    return 0;
}
