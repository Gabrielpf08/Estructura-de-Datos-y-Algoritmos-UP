#include <stdio.h>
#include <stdlib.h>

//Ingresar números enteros y generar un árbol binario de búsqueda. Mostrarlo en Orden.
//Mostrar la cantidad de nodos hojas impares y la cantidad de nodos múltiplos de la raíz.

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int* );
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja, int, int *,int*);

int main ()
{
    int raiz;
    int contMultiplosRaiz=0;
    int contNodosHojasImpares=0;

    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol,&raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, raiz, &contMultiplosRaiz, &contNodosHojasImpares);
    printf("\nla cantidad de multiplos de la raiz es %d",contMultiplosRaiz);
    printf("\n la cantidad de nodos hojas impares es %d",contNodosHojasImpares);

    return 0;
}
void crear (treenode **hoja,int *raiz){

    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz=numero;
    while (numero!=-1){

        insertar(&(*hoja),numero);
        printf ("Ingrese numero: \n");
        scanf ("%d",&numero);
    }
}

void insertar (treenode **hoja,int elem){
    
    int numero=elem;
    
    if (elem==-1) //Condicion de corte 
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

void mostrar (treenode *hoja,int raiz,int *contMultiplosRaiz,int *contNodosHojasImpares){
    if (hoja!=NULL){

        mostrar(hoja->izq,raiz,contMultiplosRaiz,contNodosHojasImpares);
        
        if (hoja->dato % raiz == 0 && hoja->dato != raiz)
               *contMultiplosRaiz += 1;

        if (hoja->izq == NULL && hoja->der == NULL && hoja->dato % 2 != 0)
                *contNodosHojasImpares += 1;

        printf("%d ",hoja->dato);
        mostrar(hoja->der,raiz,contMultiplosRaiz,contNodosHojasImpares);

    }
    return;
}
