/**
 * @file entregar.c
 * 
 * Desarrollar un programa en C que permita ingresar números en un árbol binario de búsqueda. InOrderlo en preorden,
 *  en orden y en postorden. Calcular y InOrder (en una función y no en el programa principal):

El valor máximo múltiplo de la raíz.
La cantidad de nodos hojas divisores de la raíz.
La sumatoria de aquellos nodos pares con un hijo.
 * @date 2021-11-12
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct typearbol
{
    int dato;
    struct typearbol *izq;
    struct typearbol *der;
}treenode;

void crear (treenode **hoja,int*);
void insertar(treenode **hoja, int elem);
void InOrder (treenode *hoja, int raiz , int *maximo, int *contDivisoresRaiz, int *sumatoriaNodosPares);
void PostOrder (treenode *hoja, int raiz);
void PreOrder (treenode *hoja, int raiz);

int main (){

    int raiz, maximo, contDivisoresRaiz=0, sumatoriaNodosPares=0;
    printf ("arboles: \n");
    treenode* typearbol=NULL;

    crear (&typearbol, &raiz);
    printf ("**************\n");
    printf ("ARBOL BINARIO\n");
    printf ("***************\n");

    
    printf ("\nARBOL BINARIO En Orden: ");
    InOrder (typearbol, raiz , &maximo, &contDivisoresRaiz, &sumatoriaNodosPares);
    printf ("\nARBOL BINARIO En Preorden: ");
    PreOrder (typearbol, raiz);
    printf ("\nARBOL BINARIO En Postorden: ");
    PostOrder (typearbol, raiz);
    printf("\n");
	printf("\nMaximo divisor de la raiz: %d ",maximo);
	printf("\nla cantidad de nodos hojas divisores de la raiz %d ",contDivisoresRaiz);
    printf("\nSumatoria Nodos pares con un hijo: %d",sumatoriaNodosPares);

    return 0;
}
void crear (treenode **hoja, int *raiz ){

    int numero;
    printf ("Ingrese un Numero: \n");
    scanf ("%d",&numero);
	*raiz=numero;
    while (numero!=-1){

        insertar(&(*hoja),numero);
        printf ("Ingrese un numero: \n");
        scanf ("%d",&numero);
    }
}

void insertar (treenode **hoja,int elem){

    int numero=elem;

    if (elem == -1)
        return;

    if (*hoja==NULL){
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }
    
    else{

    if (numero > (*hoja)->dato){
        insertar (&(*hoja)->der,elem);
    }

    else{

        insertar (&(*hoja)->izq,elem);
    }
    }
return;
}

void InOrder (treenode *hoja, int raiz ,int *maximo, int *contDivisoresRaiz, int *sumatoriaNodosPares){
    
    if (hoja != NULL){

        InOrder(hoja->izq, raiz , maximo, contDivisoresRaiz, sumatoriaNodosPares);
        printf("%d ",hoja->dato);
        
		if((hoja->dato > *maximo) && (hoja ->dato % raiz == 0)){
			*maximo = hoja->dato;   //Maximo Divisor de la raiz
        }

		if((hoja->izq == NULL && hoja->der == NULL) && raiz % hoja->dato == 0){ 
			*contDivisoresRaiz += 1;    //Cantidad de nodos hojas divisores de la raiz y distintos de la misma.
        }

		if((hoja->izq != NULL && hoja->der == NULL) || (hoja->izq==NULL && hoja->der != NULL) && (hoja->dato % 2 == 0)){ 
			*sumatoriaNodosPares += hoja->dato;          //Sumatoria nodos pares con un hijo
        }

        InOrder(hoja->der, raiz , maximo, contDivisoresRaiz, sumatoriaNodosPares);
    }
    return;
}

void PostOrder (treenode *hoja, int raiz){
    
    if (hoja != NULL){

        PostOrder(hoja->izq, raiz);
        PostOrder(hoja->der, raiz);
        printf("%d ",hoja->dato);
    }
    return;
}

void PreOrder (treenode *hoja, int raiz){
    
    if (hoja != NULL){

        printf("%d ",hoja->dato);
        PreOrder(hoja->izq, raiz);
        PreOrder(hoja->der, raiz);
    }
    return;
}