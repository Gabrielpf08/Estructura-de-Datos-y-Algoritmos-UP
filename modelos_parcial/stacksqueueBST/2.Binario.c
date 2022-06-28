/*Ejercicio nª1: Crear y Mostrar un árbol binario de búsqueda.
Escribir las funciones necesarias para calcular y luego mostrar:

a) Cantidad de los elementos pares con un hijo.
b) Mínimo elemento impar del árbol.

El ingreso de datos es 15 9 20 6 14 17 64 13
26 72*/

#include <stdio.h>
#include <stdlib.h>

typedef struct arbol{
    int num;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int *);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja,int raiz, int *, int *);

int main (){

    int raiz, contParesHijo = 0, minimo;

    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, raiz, &contParesHijo, &minimo);
    printf ("\nCantidad de pares con un solo hijo: %d \n",contParesHijo);
    printf("minimo numero impar: %d \n",minimo);

    return 0;
}
void crear (treenode **hoja, int *raiz){
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz = numero;
    while (numero!=-1){
        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}

void insertar (treenode **hoja,int elem){

    int numero=elem;
    if (elem==-1)
        return;
    if (*hoja==NULL){
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->num=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }else{

    if (numero>(*hoja)->num){
        insertar (&(*hoja)->der,elem);
    }
    else{
        insertar (&(*hoja)->izq,elem);
    }
    }
return;
}

void mostrar (treenode *hoja, int raiz, int *contParesHijo, int *minimo ){
    if (hoja!=NULL){

        mostrar(hoja->izq, raiz, contParesHijo, minimo);
        printf("%d ",hoja->num);

        if ((hoja->izq == NULL && hoja->der != NULL)|| (hoja->izq != NULL && hoja->der == NULL)){
            if (hoja->num % 2 == 0)
                *contParesHijo +=1;
        }

      if (hoja->num < *minimo && hoja->num % 2 != 0)
            *minimo = hoja->num;


        mostrar(hoja->der, raiz, contParesHijo, minimo);

    }
    return;
}
