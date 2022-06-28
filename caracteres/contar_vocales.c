/*Este es un ejemplo para ver la cantidad de vocales*/

#include <stdio.h>

int main() 
{
    int c, cont = 0, contv = 0;
    
    c =getchar();
    while (c != '\n')
    {
        putchar (c);
        if (c == 'a')
        {
            cont ++;
        }
        
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
           contv ++; 
        }
        c= getchar();
    }
    
    printf ("\nLa cantidad de A es: %d", cont);
    printf ("\nLa cantidad de vocales es: %d", contv);
    
    return 0;
}
