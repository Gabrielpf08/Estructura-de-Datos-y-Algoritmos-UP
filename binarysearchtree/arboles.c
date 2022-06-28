#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja,int*);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja,int *,int *, int);

int main (){
    int cont=0, cont1=0, raiz;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol, &raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol,&cont,&cont1,raiz);
	printf("\nla cantidad de numeros pares es %d ",cont);
	printf("\nla cantidad de nodos hojas es %d ",cont1);

    return 0;
}
void crear (treenode **hoja, int *raiz ){
   
    int numero;

    printf ("Ingrese numero: \n");
    scanf ("%d",&numero);
	*raiz=numero;
    while (numero != -1)
    {

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}

void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem == -1)
        return;
    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }else{




    if (numero>(*hoja)->dato)
    {

        insertar (&(*hoja)->der,elem);

    }
    else
    {

        insertar (&(*hoja)->izq,elem);
    }
    }
return;
}



void mostrar (treenode *hoja, int *cont, int *cont1, int raiz)
{
    if (hoja!=NULL)
    {


        mostrar(hoja->izq,cont,cont1,raiz);
        printf("%d ",hoja->dato);

		if(hoja->dato % 2 == 0)
			*cont=*cont+1; //Contar Pares

		if(hoja->izq == NULL && hoja->der == NULL) //Nodos Hojas
			*cont1=*cont1+1;

		if(hoja->dato > raiz && ((hoja->izq == NULL && hoja->der != NULL)||(hoja->izq!=NULL && hoja->der==NULL))) 
			printf("%d \n",hoja->dato); 

        mostrar(hoja->der,cont,cont1,raiz);

    }
    return;
}