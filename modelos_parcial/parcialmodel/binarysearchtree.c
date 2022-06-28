#include <stdio.h>
#include <stdlib.h>

/*a) buscar el menor elemento par del arbol divisor de la raiz
b)cantidad de nodos hojas impares
*/

typedef struct arbol{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int *);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja, int *, int *, int *);

int main (){

    int raiz, minimo, contarNodosHojaImpares = 0;
    printf ("arboles\n");
    treenode* arbol=NULL;
    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, &raiz, &minimo, &contarNodosHojaImpares);
    printf ("\nEl menor elemento par del arbol divisor de la raiz es: %d \n",minimo);
    printf("Nodos hojas con valor Impar: %d", contarNodosHojaImpares);
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

void mostrar (treenode *hoja, int *raiz, int *minimo, int *contarNodosHojaImpares){
    
    if (hoja!=NULL){

        mostrar(hoja->izq, raiz, minimo, contarNodosHojaImpares);
        printf("%d ",hoja->dato);
        *minimo = hoja -> dato;
        if (*raiz % hoja->dato == 0 && hoja->dato < *minimo && hoja->dato % 2 == 0)
            *minimo = hoja->dato; //buscar el menor elemento par del arbol divisor de la raiz
            
        if (hoja->izq == NULL && hoja->der == NULL && hoja->dato % 2 != 0)
        *contarNodosHojaImpares += 1;

        mostrar(hoja->der, raiz, minimo,contarNodosHojaImpares);

    }
    return;
}
