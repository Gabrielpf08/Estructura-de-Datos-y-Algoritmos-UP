/**
 * @file valorperteneciente.c
1. Diseñar una función que, dado un árbol binario y un valor, determine si el valor
pertenece al árbol.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct arbol{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja, int *valor, int *);

int main (){
    int valor = 0, ontree = 0;

    printf("Ingrese un valor: ");
    scanf("%d", &valor);

    printf ("arboles\n");
    treenode* arbol=NULL;
    crear (&arbol);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, &valor, &ontree);
    if(ontree == 1){
      printf("\nEl valor esta en el BST. ");
    }
    else{
      printf("\nNo se ha conseguido el valor: ");
    }


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

void mostrar (treenode *hoja, int *valor, int *onTree){
    if (hoja!=NULL){

        mostrar(hoja->izq, valor, onTree);
        printf("%d ",hoja->dato);

        if(*valor == hoja->dato){
          *onTree = 1;
        }
            

        mostrar(hoja->der, valor, onTree);

    }
    return;
}
