#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 10

typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *primero, int *sumatoria)
{
  	printf("%d \n", aux.dato);
      if(*primero % aux.dato == 0 && aux.dato != *primero){
          *sumatoria += aux.dato;
      }
}

nodo* crear_nodo(int dato)
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));

   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void acolar(nodo** p,nodo** u, nodo *q)
{
   printf("acolar_nodo\n");
	if(*p==NULL)
    *p = *u = q; /*porque hay uno solo*/
   else
   {
    	(*u)->siguiente = q;
    	(*u) = q;
   }
  	printf("%02d p=%X u=%X\n", q->dato, *p, *u);
}

nodo desacolar(nodo** inicio)
{
	nodo* aux;
   nodo datos;

	datos=**inicio;

	aux=*inicio;

	*inicio=(*inicio)->siguiente;
	free(aux);

    return datos;
}

int main()
{

   int i = 0,num, primero = 0, sumatoria = 0;
   nodo* p=NULL;
   nodo* u=NULL;

    printf("Ingrese un numero: ");
    scanf("%d",&num);
    while(num!=-1){
       if(i == 0){
           primero = num;
       }
        acolar(&p, &u, crear_nodo(num));
        i++;
       
    printf("Ingrese un numero: ");
    scanf("%d",&num);
        }

   printf("\nVamos a desacolar todo: \n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p), &primero, &sumatoria);
   }

   printf("Sumatoria divisores primer elemento: %d",sumatoria);
   return 0;
}

