/*En  este calculamos la potencia de los numeros que ingresemos de manera recursiva*/

#include <stdio.h>

int potencia(int a, int b)
{
    if(b==0)
    {
        return 1; //pongo 1 porque nunca va a ser 0, dado que cualquier numero elevado a la 0 da 1
    }
    
    return potencia(a, b-1)*a; //como la potencia es multiplicar "x" numero "n" cantidad de veces se pone asi 
                               //por ejemplo 2^4 es igual a 2x2x2x2 
}


int main()
{
    int a, b;
    printf("\nIngrese los valores: ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("\nLa potencia es: %d", potencia(a, b));
    
    return 0;
}
