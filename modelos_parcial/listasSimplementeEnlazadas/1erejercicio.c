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
    printf("Ingrese un numero: ");
    scanf("%d",&r->num);
    
    if (r->num==100)
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
        r=r->sig;
    }
    s->sig = NULL;
}

void insertar (nodo *h)
{
    nodo *aux;
    while(h->sig!=NULL)
    {
        if((h->num + h->sig->num) > 20) //sumar nodos consecutivos
        {
            aux=(nodo *)malloc(sizeof(nodo));
            aux->num = 0;
            aux->sig = h->sig;
            h->sig=aux;
            h=h->sig->sig;

        }
        else
        h=h->sig;
    }
}

void eliminar2(nodo* p)
{
    nodo *aux;
    
    while(p->sig != NULL && p->sig->sig!=NULL)
    { //eliminar nodos consecutivos
        if((p->sig->num + p->sig->sig->num) < 10)//condicion de eliminacion
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
    nodo *q = NULL;

    prin=(nodo*)malloc(sizeof(nodo));
    q = (nodo*)malloc(sizeof(nodo));

    crear(prin);
    mostrar (prin);
    printf("\nMULTIPLOS DE 3\n");
    generar(prin,q);
    mostrar(q);
    
    
    printf("\nLista con inserciones:\n ");
    //prin=InsertarPorCabeza(prin);
    insertar(prin);
    mostrar(prin);

    printf("Lista con eliminaciones:\n ");
    eliminar2(prin);
    mostrar(prin);
    

    return 0;
}