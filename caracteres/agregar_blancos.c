/*En este ejemplo queremos que cuando devuelva la lectura (que pone todas las palabras juntas) tenga mas de un espacio entre 
palabra y palabra*/

#include <stdio.h>

int main() 
{
    int c;
    
    c =getchar();
    while (c != '.' && c == ' ')
    {
        c = getchar();
    }    
    
    while (c != '.')
    {
        while (c != '.' && c != ' ')
        {
            putchar(c);
            c = getchar();
        }
        
        while (c != '.' && c == ' ')
        {
            c = getchar();
        }
        
        putchar(' '); //se ponen aca porque al salir del "while" sabemos que nos dejo al principio de la palabra o en la marca
        putchar(' '); //de fin, en el ultimo caracter de la secucencia 
    }
    
    return 0;
}
