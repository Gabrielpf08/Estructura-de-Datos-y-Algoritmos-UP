/*MATRICES*/

/* Esto es un ejercicio de matrices. */

#include <stdio.h>

void cargar(int mat[5][5], int n) // los '[][]' no pueden quedar vacios porque para que C entienda que no es un "arreglo largo" hay que colocarle numeros, 
// de otro modo nos sale error de compilacion
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
           printf("\nIngrese elemento %d: ");
           scanf("%d", &mat[i][j]); // las filas son las 'i' y las columnas son la 'j'
        }
    }
}

void mostrar (int mat[5][5], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
           printf("\nEl elemento es %d ", mat[i][j]);
        }
    } 
}

int main()
{
    int mat[5][5], filas_columnas; // 'mat' es por la matriz. 'n' es la cantidad de filas o columnas.
    printf("\nIngrese la cantidad de filas o columnas (menor de 5): "); // aca no hace alta poner el '"%d"' porque ya defini que va a ser un entero desde antes.
    scanf("%d", &filas_columnas);
    cargar(mat, filas_columnas);
    mostrar(mat, filas_columnas); 
    
    return 0;
}

