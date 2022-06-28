/*Este es un ejemplo en el que vemos como hacemos si queremos buscar la ultima letra de cada frase y tenemos blancos
adelante de la oraion y al final antes del punto*/

#include <stdio.h>

int main() 
{
    int c, cont = 0, contv = 0;
    int ultimo;
    
    c =getchar();
    while (c != '.' && c == ' ') //este analiza los blancos que estan adelante del principo de la oracion
    {
        c = getchar(); //este lee los blancos
    }
    
    while (c != '.') //aca entra cuando ya encuentra una letra que sea distinta del blanco que venia leyendo
    {
        while (c != '.' && c != ' ')
        {
            ultimo = c;
            c = getchar();
        }
        putchar(ultimo); //esto va a devolver todas las ultimas letras de cada palabra de la oracion
        
        while (c != '.' && c == ' ') //este analiza los blancos despues de la oracion y antes del punto
        {
            c = getchar();
            
        }
    }
    
    return 0;
}