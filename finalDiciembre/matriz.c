/*Dada una matriz de N * N elementos, calcular la productoria de la diagonal secundaria*/

#include <stdio.h>
#include <stdlib.h>

void productoriaDiagonalsecundaria(int matriz[10][10], int dimension){
	int i, j;
	int productoria = 1;
	for(i = 0; i < dimension; i++){
		for(j = 0; j < dimension; j++){
			if(i + j == dimension -1){
				productoria *= matriz[i][j];
			}
		}
	}
	printf("\nLa productoria de la diagonal secundaria es: %d",productoria);
}


void cargar(int matriz[10][10], int dimension){
	int i, j;
	for(i = 0; i < dimension; i++){
		for(j = 0; j < dimension; j++){
			printf("Fila %d Columna %d ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}
}


void mostrar(int matriz[10][10], int dimension){
	int i, j;
	for(i = 0; i < dimension; i++){
		printf("\n");
		for(j = 0; j < dimension; j++){
			printf(" %d\t ",matriz[i][j]);
			}
		}
}


int main(){
	int matriz[10][10], dimension = 0;
	printf("Ingrese la dimension de la matriz: \n");
	scanf("%d", &dimension);
	cargar(matriz, dimension);
	mostrar(matriz, dimension);
	productoriaDiagonalsecundaria(matriz, dimension);
}