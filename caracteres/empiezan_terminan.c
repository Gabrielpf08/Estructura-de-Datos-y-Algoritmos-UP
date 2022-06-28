/*Este es un ejemplo en el que contamos las palabras que empiezan con A y terminan con S*/

#include <stdio.h>

int main() 
{
    int c, cont = 0, contv = 0;
    int ultimo, primera;
    
    c =getchar();
    while (c != '.' && c == ' ') //este analiza los blancos que estan adelante del principo de la oracion
    {
        c = getchar(); //este lee los blancos
    }
    
    while (c != '.') //aca entra cuando ya encuentra una letra que sea distinta del blanco que venia leyendo
    {
        primera = c; //este guarda la primera letra de cada palabra de la oracion
        while (c != '.' && c != ' ')
        {
            ultimo = c; //este guarda la ultima letra de cada palabra de la oracion
            c = getchar();
        }
        putchar (ultimo);
        
        if(primera == 'a' && ultimo == 's')
        {
            cont++;
        }

        while (c != '.' && c == ' ') //este analiza los blancos despues de la oracion y antes del punto
        {
            c = getchar();
            
        }
    }
    
    printf("\nLas cantidad de palabras que empiezan con A y terminan con S son: %d", cont);
    
    return 0;
}
