#include <stdio.h>
#include <stdlib.h>


/*2.   Cargar una matriz de n*n de números enteros y mostrar:
a)    la matriz transpuesta
b)    El promedio de los elementos de las dos diagonales (principal y secundaria)
c)    Multiplicar la matriz por su transpuesta.
d)    Determinar cuántos números primos hay en la matriz.


*/


void cargar(int matriz[10][10], int dimension){
    int i, j;
    for(i = 0; i < dimension; i++){
        for(j = 0; j < dimension; j++){
            printf("Fila: %d Columna: %d\n", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

}


void mostrar(int matriz[10][10], int dimension){
    int i, j;
    for(i = 0; i < dimension; i++){
        printf("\n");
        for(j = 0; j < dimension; j++){
            printf("%d\t", matriz[i][j]);
        }
    }
}


void obtenerMatrizTranspuesta(int matriz[10][10], int dimension){
    int i, j;
    for(i = 0; i < dimension; i++){
        printf("\n");
        for(j = 0; j < dimension; j++){
            printf("%d\t", matriz[j][i]);
        }
    }
}


void calcularPromedioDiagonales(int mat[10][10], int dim){
    int i, j;
    int contador = 0, acumulador = 0;
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            if((i == j) || (i + j == dim - 1)){
                acumulador += mat[i][j];
                contador += 1;
            }
        }
    }
    printf("El promedio de los elementos de las diagonales es: %.2f", (float)acumulador / contador);
}


int main(){
    int mat[10][10], dimension;
    printf("Ingrese Dimension de la matriz (menor a 10)");
    scanf("%d",&dimension);
    cargar(mat, dimension);
    mostrar(mat, dimension);
    printf("\n\nMatriz Transpuesta\n");
    obtenerMatrizTranspuesta(mat, dimension);
    calcularPromedioDiagonales(mat,dimension);
}