/*ARREGLOS Y RECURSIVIDAD*/
/*En este caso tenemos el arreglo definido con sus valores*/

#include <stdio.h>

int suma(int vec[], int dim)
{
    if(dim<0)
    {
        return 0;
    }
    
    return suma(vec, dim-1)+vec[dim];
}


int main()
{
    int vec[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    printf("\nIngrese los valores: ");
    printf("\nLa suma del arreglo es: %d", suma(vec, 9)); //se pone desde el 9 porque las cajitas del arreglo son de 0 al 9 (osea 10 posociones) 
    
    return 0;
}