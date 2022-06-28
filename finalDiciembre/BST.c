/* Cantidad de veces que aparece el divisor de la raiz en un BST en los nodos hojas de ese arbol
RECORDANDO: 
	Nodo hoja: Son todos aquellos nodos que no tienen hijos

*/
/*5. Diseñar una función que, dado un árbol binario de búsqueda, calcule la cantidad de
nodos hojas divisores de la raíz.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct arbol{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int *raiz);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja, int *, int *);

int main (){
		int raiz = 0; int contdivraiz = 0;
    printf ("arboles\n");
    treenode* arbol=NULL;
    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol, &raiz, &contdivraiz);
	printf("\nLa raiz es: %d", raiz);
	printf("\nLa cantidad de divisores de la raiz es: %d", contdivraiz);


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



void mostrar (treenode *hoja, int *raiz, int *contdivraiz){
    if (hoja!=NULL){

        mostrar(hoja->izq, raiz, contdivraiz);
        printf("%d ",hoja->dato);

			if((hoja->der == NULL ) && (hoja->izq == NULL) && *raiz % hoja->dato == 0)
			{
				*contdivraiz += 1;
			}
        mostrar(hoja->der, raiz, contdivraiz);

    }
    return;
}
