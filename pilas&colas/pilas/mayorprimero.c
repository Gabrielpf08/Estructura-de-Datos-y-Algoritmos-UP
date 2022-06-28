/*
Crear una pila con la siguiente información:
 num: numero entero.
 siguiente: puntero al próximo elemento de la pila.
Desarrollar una función que permita mostrar la sumatoria de números
mayores al primer elemento ingresado en la pila. Si no hubiera ningún
número mostrar una leyenda.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct pila{
    int num;
    struct pila *sig;

}nodo;

void mostrar(nodo aux, int primer,int *sumatoria ){
    printf("%d\n", aux.num);
    if (aux.num > primer){
        *sumatoria += aux.num;
    }
}

void apilar(nodo **p, nodo *nuevo){
    nuevo->sig = *p;
    *p = nuevo;
}

nodo *crearnodo(int num){
    nodo * nuevo;
    nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->num = num;
    nuevo->sig = NULL;
    return nuevo;
}



nodo desapilar(nodo **p){
    nodo *aux;
    nodo datos;

    datos = **p;
    aux = *p;

    *p = (*p)->sig;
    free(aux);

    return datos;
}

int main(){
    int i=0, n, primer, sumatoria=0;
    nodo *p;

    

    while (i <4){
        printf("Ingrese un numero: ");
        scanf("%d", &n);
        if(i==0){
            primer = n;
        }
        apilar(&p, crearnodo(n));
        i++;
    }
    printf("primer numero: %d\n", primer);

    while (p != NULL){
        mostrar(desapilar(&p), primer, &sumatoria);
    }

    printf("La sumatoria de los numeros mayores al primero es: %d", sumatoria);
    
    getch();
    return 0;
}