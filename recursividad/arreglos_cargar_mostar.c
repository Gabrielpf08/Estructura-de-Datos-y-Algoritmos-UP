#include <stdio.h>

void cargar(int vec[], int dim)
{
    if(dim<0)
    {
        return; //queda solo el "return" porque es de tipo "void", no devuelve nada
    }

    printf("\ningrese valor: ");
    scanf("%d", &vec[dim]);
    cargar(vec, dim-1); 
}

void mostrar(int vec[], int dim)
{
    if(dim<0)
    {
        return; //queda solo el "return" porque es de tipo "void", no devuelve nada
    }

    printf("\nEl valor es: %d", vec[dim]);
    mostrar(vec, dim-1); 
}

int main()
{
    int vec[10], dim;
    printf("\nIngrese los valores: ");
    scanf("%d", &dim);
    cargar(vec, dim-1); //el "dim" va a ir de la ultima posicion hasta la primera 
    mostrar(vec, dim-1);
    printf("\nLa suma del arreglo es: %d", suma(vec, dim-1)); 
    
    return 0;
}
