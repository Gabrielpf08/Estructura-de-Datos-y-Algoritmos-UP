/*Diseñar una función que, dado un árbol binario de búsqueda, calcule el promedio de
aquellos nodos múltiplos de la raíz.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct arbol{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int *);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja, int *raiz, int *, int *);

int main (){

    int  raiz, contProm=0, acumProm = 0;
    float promedio=0;
    printf ("arboles\n");
    treenode* arbol=NULL;
    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, &raiz, &contProm, &acumProm);

    promedio = (float)acumProm / (float)contProm;
    printf("\nEl promedio de los numeros multiplos de la raiz es: %.2f",promedio);


    return 0;
}
void crear (treenode **hoja, int *raiz){
    int numero;

    printf ("ingrese numero: \n");
    scanf ("%d",&numero);
    *raiz = numero;
    while (numero!=-1){
        insertar(&(*hoja),numero);
        printf ("ingrese numero: \n");
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



void mostrar (treenode *hoja, int *raiz, int *contProm, int *acumProm){
    if (hoja!=NULL){

        mostrar(hoja->izq, raiz, contProm, acumProm);
        printf("%d ",hoja->dato);

        if(hoja->dato % *raiz == 0 && hoja->dato != *raiz){
            *acumProm += hoja->dato;
            *contProm += 1;
        }

        mostrar(hoja->der, raiz, contProm, acumProm);

    }
    return;
}
