/*Este es otro ejemplo en el que cuento la cantidad de "s" que hay en total en las frases que ingrese*/

#include <stdio.h>

int main()
{
    int c, cont = 0;
    
    printf("\nIngrese la frase: ");
    c = getchar();
    while(c != '.')
    {
        if(c == 's')
        {
            cont++;
        }
        
        c = getchar();
    // putchar(c) // no esta mal pero por culpa del IDE me queda un bucle infinito 
        
    }
    
    printf("\nLas frases terminadas en S son: %d", cont);
    
    return 0; 
}
