//Diseñar una función que, dado un árbol binario, calcule su cantidad de nodos.

#include <stdio.h>
#include <stdlib.h>

typedef struct arbol{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja, int *);

int main (){
    int contador =0;
    printf ("arboles\n");
    treenode* arbol=NULL;
    crear (&arbol);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, &contador);
    printf("\nHay %d nodos", contador);


    return 0;
}
void crear (treenode **hoja){
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
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
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }
    else{

    if (numero>(*hoja)->dato){
        insertar (&(*hoja)->der,elem);
        }
    else{
        insertar (&(*hoja)->izq,elem);
    }
    }
return;
}



void mostrar (treenode *hoja, int *contador){
    if (hoja!=NULL){

        mostrar(hoja->izq, contador);
        printf("%d ",hoja->dato);
        *contador += 1;

        

        mostrar(hoja->der, contador);

    }
    return;
}
