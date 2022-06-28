#include <stdio.h>

void cargar(int matriz[10][10], int dimension){
  int i,j;

  for (i=0;i<dimension;i++){
    for(j=0;j<dimension;j++){
      printf("Ingrese el valor %d %d ", i,j);
      scanf("%d", &matriz[i][j]);
    }
  }
}

void mostrar(int matriz[10][10], int dimension){
  int i, j;
  for (i=0; i<dimension; i++){
    for (j=0;j<dimension;j++){
      printf("%d  ", matriz[i][j]);
    }
    printf("\n");
  }
  return;
}

int producto_diagonal_principal(int matriz[10][10],int dimension){

  if (dimension == 0){   //recorre de adelante hacia atras. acumula valores de cada posicion y multiplica hasta llegar a la posicion 0 y retorna.
  return matriz[0][0];
  }
  else
      return producto_diagonal_principal (matriz,dimension-1) * matriz[dimension][dimension]; 
    } 

int main(){
  int matriz[10][10], dimension, prod;
  printf("Ingrese la dimension de la matriz: ");
  scanf("%d", &dimension);
  cargar(matriz,dimension);
  mostrar(matriz,dimension);
  printf("Resultado producto diagonal principal: %d", producto_diagonal_principal(matriz,dimension-1));
  return 0;
}