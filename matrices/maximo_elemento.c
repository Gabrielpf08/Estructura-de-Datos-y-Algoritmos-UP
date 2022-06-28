/*Aca tenemos un ejemplo donde se buscan los maximos elementos de la matriz*/

void cargar(int a[][10],int dim)
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


void mostrar(int a[][10],int dim)
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

void maximo(int a[][10], int dim)
{
    int i, j, max = a[0][0]; //el "a[0][0]" es para inicializar 0 en ambas posiciones (i y j) y que de ahi empiece a recorrer
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            if(a[i][j] > max)
            {
                max = a[i][j];
            }
        }
    }
}


int main() {
   int a[10][10],dim;
    printf("ingrese dimension de la matriz menor a 10 filas: ");
    scanf("%d",&dim); 
   cargar(a,dim);
   mostrar(a,dim);
   maximo(a, dim);
    
    return 0;
}

