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


void diagonal_principal(int mat[][10], int dim){
    int i, j,multiplicar = 1;
    for (i=0; i<dim; i++)
        for (j=0; j <dim;j++)
            if (i == j){
                printf("\n La diagonal Principal es %d",mat[i][j]);
                multiplicar *= mat[i][j]; 
            }
                
                printf("\nEl resultado de la multiplicacion es %d", multiplicar);         
}


void diagonal_secundaria(int mat[][10], int dim){
    int i, j;
    for (i=0; i<dim; i++)
        for (j=0; j <dim;j++)
            if (i+j == dim-1)
                printf("\n La diagonal secundaria es %d",mat[i][j]);         
}


int main() {
   int mat[10][10],dim, prin;
    printf("ingrese dimension de la matriz menor a 10 filas ");
    scanf("%d",&dim); 
   cargar(mat,dim);
   mostrar(mat,dim);
    diagonal_principal(mat,dim);
    printf("\n");
    diagonal_secundaria(mat,dim);
    
    return 0;
}