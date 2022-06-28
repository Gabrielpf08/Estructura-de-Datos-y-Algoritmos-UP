#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
	int num;
	struct lista *sig;
 }nodo;



void crear (nodo *r){
    scanf("%d",&r->num);
    if (r->num==0)
        r->sig=NULL;
    else
	{
        r->sig=(nodo*)malloc(sizeof(nodo));
        crear (r->sig);
	}
	return;
}

void Imprimir (nodo *r){
    if (r->sig !=NULL){
        printf ("%d\n",r->num);
        Imprimir (r->sig);
	}
	return;
}

nodo* InsertarPorCabeza(nodo *p){
    nodo *aux;
    if()//condicion de insercion
    {
        aux=(nodo *)malloc(sizeof(nodo));
        aux->num=0;//valor a insertar
        aux->sig=p;
        p=aux;
    }
    return p;
}

void insertar2 (nodo *p){
    nodo *aux;
    while(p->sig!=NULL){
        if() //condicion de insercion
        {
            aux=(nodo *)malloc(sizeof(nodo));
            aux->num=0;//valor a insertar
            aux->sig=p->sig;
            p->sig=aux;

        }
        p=p->sig;
    }
}

nodo* EliminarPorCabeza(nodo* p){
    nodo *aux;
    while()//condicion de eliminacion
    {
        aux=p->sig;
        free(p);
        p=aux;
    }
    return p;
}

void eliminar2(nodo* p)
{nodo *aux;
    while()
    {p->sig!=NULL&& p->sig->sig!=NULL
        if()//condicion de eliminacion
        {
            aux=p->sig->sig;
            free(p->sig);
            p->sig=aux;
        }
        else
        {
            p=p->sig;
        }
    }

}
int main()
{

    nodo *prin=NULL;
    prin=(nodo*)malloc(sizeof(nodo));
    crear(prin);
    Imprimir (prin);
    prin=InsertarPorCabeza(prin);
    insertar2(prin);
    prin=EliminarCabezaDeLista(prin);
    eliminar2(prin);
    Imprimir(prin);

    return 0;
}