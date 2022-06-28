#include <stdio.h>
#include <stdlib.h>

/*
Crear y mostrar una lista que contenga dos números enteros (termina con ambos números en cero).

Generar una lista nueva con el promedio de ambos números.

Insertar en la lista original la mitad del valor de cada número si la suma de los números es mayor a 15.

Eliminar aquellos nodos donde el primer valor es múltiplo del segundo valor.
*/

typedef struct lista{
	int num1;
	int num2;
	struct lista *sig;
 }nodo;

typedef struct lista2{
	int num1;
	struct lista2 *sig;
 }nodo2;

void crear (nodo *);
void mostrar(nodo *);
nodo* eliminar1(nodo* );
void insertar (nodo* );
void eliminar2(nodo* );


void generar(nodo *h, nodo2 *m) //Generar una lista nueva con el promedio de ambos números.
{
    while(h->sig!=NULL)
    {
        m->num1=(h->num1+h->num2)/2;
        m->sig=(nodo2*)malloc(sizeof(nodo2));
        m=m->sig;
        h=h->sig;
    }
    m->sig=NULL;
}

void mostrar_lista_nueva (nodo2 *r)
{
    if (r->sig !=NULL)
	{
        printf ("%d\n",r->num1);
        printf("\n");
        mostrar_lista_nueva (r->sig);
	}
	return;
}

int main()
{
    nodo *p=NULL;
    nodo2 *k=NULL;

    p=(nodo*)malloc(sizeof(nodo));
    k=(nodo2*)malloc(sizeof(nodo2));

    crear(p);
    mostrar (p);

    generar(p,k);
    mostrar_lista_nueva(k);

    insertar(p);
    printf("la lista insertada es \n");
    mostrar(p);

    p=eliminar1(p);
    eliminar2(p);
    printf("la lista eliminada es \n");
    mostrar(p);

    return 0;
}

void crear (nodo *r)
{
    printf("ingrese un numero");
    scanf("%d",&r->num1);
    printf("ingrese un numero");
    scanf("%d",&r->num2);

    if (r->num1==0 && r->num2==0)
        r->sig=NULL;
    else
	{
        r->sig=(nodo*)malloc(sizeof(nodo));
        crear (r->sig);

	}
	return;
}

void mostrar (nodo *r)
{
    if (r->sig !=NULL)
	{
        printf ("%d\n",r->num1);
        printf ("%d\n",r->num2);
        printf("\n");
        mostrar (r->sig);
	}
	return;
}


void insertar (nodo *h)
{
    nodo *aux;
    while(h->sig!=NULL)
    {
        if((h->num1 + h->num2) > 15)
        {
            aux=(nodo *)malloc(sizeof(nodo));
            aux->num1=(h->num1)/2; //insertar la mitad del valor original
            aux->num2=(h->num2)/2;
            aux->sig = h->sig;
            h->sig = aux;
            h = h->sig->sig;

        }
        else
        h = h->sig;
    }
}

nodo* eliminar1(nodo* p)
{
    nodo *aux;
    while(p->num1 % p->num2 == 0)
    {
        aux=p->sig;
        free(p);
        p=aux;

    }
    return p;
}
void eliminar2(nodo* p)
{nodo *aux;
    while(p->sig!=NULL&& p->sig->sig!=NULL)
    {
        if(p->sig->num1 % p->sig->num2==0)
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

