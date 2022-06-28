/*Aca hacemos la cantidad de palabras que tiene la frase*/

#include <stdio.h>

int main()
{
    int c, cont = 0, cont1 = 0;
    printf("\nIngrese la frase: ");
    c = getchar();
    while(c != '.')
    {
        while(c == ' ' && c != '.')
        {
            c = getchar();
        }

        cont = 0;
        while(c != ' ' && c != '.') // aca lo que hace es  contar las letras hasta que llegue al blanco, donde pasa al "if"
        {
            cont++;
            c = getchar();
        }

        if(cont != 0) // aca en el "if" lo que pasa es que recibe las letras que salieron del "while" de arriba y si la cantidad de letras es distinta de 0 
                      // entiende que es una palabra, entonces la suma al cont1 (donde se almacenara la cantidad de palabras)
        {
            cont1++;
        }
    }

    printf("\nLa cantidad de palabras que tiene la frase es: %d", cont1);

    return 0;
}
