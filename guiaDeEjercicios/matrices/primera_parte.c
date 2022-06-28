#include <stdio.h>
#include <stdlib.h>


/*
Desarrollar un algoritmo y luego codificarlo en C para cada problema.
1.   Cargar una matriz de n*n de números enteros. Mostrar: 
a)   la sumatoria de los elementos de la 2º fila. 
b)  el mayor elemento de la segunda columna.
c)   el promedio de todos los múltiplos de 5 en la matriz. 
d)  la sumatoria de la diagonal principal de la matriz.
e)   el elemento mínimo de cada fila. 
f)   los elementos de la diagonal secundaria.
g)   los elementos que se encuentran debajo de la diagonal principal.*/


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


void sumarElementosSegundaFila(int matriz[10][10], int dimension){
    int i, j;
    int suma = 0;
    for(i = 0; i < dimension; i++){
        for(j = 0; j < dimension; j++){
            if(i == 1){
                suma += matriz[i][j];
            }  
        }
    }
    printf("\nSuma elementos segunda fila: %d\n", suma);
}


void buscarMayorElementoSegundaColumna(int matriz[10][10], int dimension){
    int i, j;
    int mayor = 0;
    for(i = 0; i < dimension; i++){
        for(j = 0; j < dimension; j++){
            if(j == 1){
                if(matriz[i][j] > mayor){
                    mayor = matriz[i][j];
                }
            }
        }
    }
    printf("El mayor elemento de la segunda columna es: %d\n",mayor);
}


void calcularPromedioMult5(int matriz[10][10], int dimension){
    int i, j, contador = 0, acumulador = 0;
    for(i = 0; i < dimension; i++){
        for(j = 0; j < dimension; j++){
            if(matriz[i][j] % 5 == 0){
                contador++;
                acumulador += matriz[i][j];
            }
        }
    }
    if(contador == 0){
        printf("No hay Multiplos de 5\n");
    }
    else{
        printf("El promedio es: %.2f\n", (float)acumulador / contador);
    }
}


void sumarDiagonalPrincipal(int matriz[10][10], int dimension){
    int i, j;
    int suma = 0;
    for(i = 0; i < dimension; i++){
        for(j = 0; j < dimension; j++){
            if(i == j){
                suma += matriz[i][j];
            }
        }
    }
    printf("La suma de los elementos de la diagonal principal es: %d\n",suma);
}


void buscarElementoMinimoPorFila(int matriz[10][10], int dimension){
    int i, j;
    int cont = 0;
    for(i = 0; i < dimension; i++){
        int menor = matriz[i][0];
        for(j = 0; j < dimension; j++){
            if(matriz[i][j] < menor){
                menor = matriz[i][j];
            }
        }
        printf("El menor de la fila %d es: %d\n",cont++, menor);
    }
    
}


void buscarElementosDiagonalSecundaria(int matriz[10][10], int dimension){
    int i, j;
    for(i = 0; i < dimension; i++){
        for(j = 0; j < dimension; j++){
            if(i + j == dimension - 1){
                printf("\nLa diagonal secundaria es: %d",matriz[i][j]);
            }
        }
    }
}



void buscarElementosPorDebajoDiagonalPrincipal(int mat[10][10], int dimension){
    int i, j;
    for(i = 0; i < dimension; i++){
        for(j = 0; j < dimension; j++){
            if(i - 1 == j){
                printf("\nElementos debajo de la diagonal principal: %d",mat[i][j]);
            }
        }
    }
}



void buscarMatrizAntisimetrica(int mat[10][10], int dimension){
    int i, j;
    int contador = 0;
    for(i = 0; i < dimension; i++){
        for(j = 0; j < dimension; j++){
            if(mat[i][j] == -mat[j][i]){
                contador++;
            }
        }
    }
    if(contador == dimension * dimension){
        printf("\nLa matriz es antisimetrica");
    }
    else{
        printf("\nLa matriz NO es antisimetrica");
    }
}


int main(){
    int mat[10][10], dimension;
    printf("Ingrese Dimension de la matriz (menor a 10)");
    scanf("%d",&dimension);
    cargar(mat, dimension);
    mostrar(mat, dimension);
    sumarElementosSegundaFila(mat, dimension);    
    buscarMayorElementoSegundaColumna(mat, dimension);
    calcularPromedioMult5(mat, dimension);
    sumarDiagonalPrincipal(mat, dimension);
    buscarElementoMinimoPorFila(mat, dimension);
    buscarElementosDiagonalSecundaria(mat, dimension);
    buscarElementosPorDebajoDiagonalPrincipal(mat, dimension);
    buscarMatrizAntisimetrica(mat, dimension);
}