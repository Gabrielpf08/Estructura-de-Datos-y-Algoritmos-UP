/*Aca calculamos la cantidad de palabras con mas de 3 letras*/

#include <stdio.h>

int main() 
{
    int c, cont = 0, contLetras = 0, contPal = 0;
    
    c =getchar();
    
    while (c != '.' && c == ' ')
    {
        c = getchar();
    }
    
    while (c != '.')
    {
        while (c != '.' && c != ' ')
        {
            contLetras++;
            putchar(c);
            c = getchar();
        }
        
        if(contLetras > 3)
        {
            contPal++;
        }
        contLetras = 0; //se reinicia el contador de letras porque sino se nos acumulan 
        
        while (c != '.' && c == ' ')
        {
            c = getchar();
            
        }
    }
    
    printf("\nLa cantidad de palabras de la oracion que tienen mas de 3 letras son: %d", contPal);
    
    return 0;
}
