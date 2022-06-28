/*Ejemplo que dio la profe en la clase sobre MATRICES*/

#include <stdio.h>

void cargar(int a[ ][ 10],int dim)
{
    int i, j;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            printf("fila %d columna %d\n ",i,j);
            scanf("%d",&a[i][j]);
        }
        
    }
}

void mostrar(int a[ ][ 10],int dim)
{
    int i, j;
    for(i=0;i<dim;i++)
    {
      printf("\n ");
      for(j=0;j<dim;j++)
        {
            printf(" %d\t ",a[i][j]);
            
        }
        
    }
}

int main() {
   int mat[10][10],dim;
    printf("ingrese dimension de la matriz menor a 10 filas ");
    scanf("%d",&dim); 
   cargar(mat,dim);
   mostrar(mat,dim);
    
    return 0;
}