/*
Ejercicio nª1: Crear y Mostrar un árbol binario de búsqueda.
Escribir las funciones necesarias para calcular y luego mostrar:
a) Buscar el mayor elemento del árbol divisor de la raíz
b) Cantidad de nodos hojas impares.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct arbol{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int *);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja, int raiz, int *, int *);

int main (){

    int raiz, maximo = 0, nodosHojasImpares=0;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, raiz, &maximo, &nodosHojasImpares);
    printf("\n");
    printf("Mayor Numero Divisor de la Raiz: %d \n", maximo);
    printf("Cantidad de nodos hojas impares: %d \n", nodosHojasImpares);

    return 0;
}

void crear (treenode **hoja, int *raiz){

    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz = numero;
    while (numero != -1){

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}

void insertar (treenode **hoja,int elem){
    int numero = elem;
    if (elem == -1)
        return;

    if (*hoja==NULL){
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }else{

    if (numero>(*hoja)->dato){

        insertar (&(*hoja)->der,elem);

    }
    else{

        insertar (&(*hoja)->izq,elem);
    }
    }
return;
}

void mostrar (treenode *hoja, int raiz, int *maximo, int *nodosHojasImpares){
    if (hoja != NULL){

        mostrar(hoja->izq, raiz, maximo,nodosHojasImpares);

        if ((raiz % hoja->dato == 0 && hoja->dato != raiz) && hoja->dato > *maximo){
            *maximo = hoja->dato;
        }

        if ((hoja->der == NULL) && (hoja->izq == NULL) && hoja->dato % 2 != 0){
            *nodosHojasImpares += 1;
        }
//8 3 10 1 6 14 4 7 13
        printf("%d ",hoja->dato);
        mostrar(hoja->der, raiz, maximo, nodosHojasImpares);

    }
    return;
}