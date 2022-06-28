/*Se pide:

a)	Crear y mostrar la lista. Termina con num=1000.

b)  Generar otra lista con aquellos números múltiplos de 3. Mostrarla  

c)	Si la suma de nodos consecutivos de la lista original es mayor a 20 agregar adelante del primer nodo (que se suma) un nodo con num=0.

Si la suma de nodos consecutivos es menor a 10 eliminar el segundo nodo que se suma.
Mostrar la lista.
*/

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

void mostrar (nodo *r){
    if (r->sig != NULL){
        printf ("Numero: %d\n",r->num);
        mostrar (r->sig);
	}
	return;
}

void generar(nodo *r, nodo *s){

    while (r->sig != NULL){
        if(r->num % 3 == 0){
            s->num = r->num;
            s->sig = (nodo*)malloc(sizeof(nodo));
            s = s->sig;
        }
        r->sig;
    }
}
/*nodo* InsertarPorCabeza(nodo *p){
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

}*/

int main()
{

    nodo *prin=NULL;
    nodo *q = NULL;

    prin=(nodo*)malloc(sizeof(nodo));
    q = (nodo*)malloc(sizeof(nodo));

    crear(prin);
    mostrar (prin);
    printf("\nMULTIPLOS DE 3\n");
    generar(prin,q);
    mostrar(q);

    /*prin=InsertarPorCabeza(prin);
    insertar2(prin);
    prin=EliminarCabezaDeLista(prin);
    eliminar2(prin);
    mostrar(prin);*/

    return 0;
}