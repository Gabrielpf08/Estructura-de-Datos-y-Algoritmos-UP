/*Este es un ejemplo de si queremos ver las primeras letras de cada frase de la oracion*/

#include <stdio.h>

int main() 
{
    int c;
    
    c =getchar();
    while (c != '.' && c == ' ') //este analiza los blancos que estan adelante del principo de la oracion
    {
        c = getchar(); //este lee los blancos
    }
    
    while (c != '.') //aca entra cuando ya encuentra una letra que sea distinta del blanco que venia leyendo
    {
        putchar(c); //este lo que hace es quedarse con la primera letra, no las recorre todas como si haria si estuviese dentro del "while"
        while (c != '.' && c != ' ')
        {
            c = getchar();
        }
        
        while (c != '.' && c == ' ') //este analiza los blancos despues de la oracion y antes del punto
        {
            c = getchar();
        }
    }
    
    return 0;
}
