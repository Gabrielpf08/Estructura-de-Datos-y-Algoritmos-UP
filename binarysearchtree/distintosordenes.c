#include <stdio.h>
#include <stdlib.h>

typedef struct arbol{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja);
void insertar(treenode **hoja, int elem);
void inOrder (treenode *hoja);
void preOrder(treenode *hoja);
void postOrder(treenode *hoja);

int main (){

    printf ("arboles\n");
    treenode* arbol=NULL;
    crear (&arbol);
    printf ("**************\n");
    printf ("Mostrar arbol\n");
    printf ("***************\n");

    printf("\nEn orden: ");
    inOrder (arbol);
    printf("\nPreorden: ");
    preOrder(arbol);
    printf("\nPost orden: ");
    postOrder(arbol);


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



void inOrder (treenode *hoja){
    if (hoja!=NULL){

        inOrder(hoja->izq);
        printf("%d ",hoja->dato);

        //sentencias

        inOrder(hoja->der);

    }
    return;
}

void preOrder (treenode *hoja){
    if (hoja!=NULL){

        printf("%d ",hoja->dato);

        inOrder(hoja->izq);

        inOrder(hoja->der);

    }
    return;
}

void postOrder (treenode *hoja){
    if (hoja!=NULL){

        inOrder(hoja->izq);

        inOrder(hoja->der);

        printf("%d ",hoja->dato);

    }
    return;
}


