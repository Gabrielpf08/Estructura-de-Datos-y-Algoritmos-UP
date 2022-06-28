/* Ejemplo de vectores en C*/

#include <stdio.h> 

void cargar (int arr[])
{
    int i; 
    for (i = 0; i < 10; i ++)
    {
        printf("\nIngrese un valor: ");
        scanf("%d", &arr[i]); // el arreglo toma el valor de "i"
    }
}

void mostrar(int vec[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("\nEl valor %d pertenece a la posicion %d", vec[i], i); // vec[i] es el valor i es la posicion.
    }
}

int main()
{
    int vec[10];
    cargar(vec);
    mostrar(vec);

    return 0;
}