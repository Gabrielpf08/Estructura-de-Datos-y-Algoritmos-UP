#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 10

typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *productoria)
{
  	printf("%d \n", aux.dato);
      if( aux.dato % 7 == 0){
          *productoria *= aux.dato;
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

   int num, productoria = 1;
   nodo* p=NULL;
   nodo* u=NULL;
   
      printf("Ingrese un numero");
      scanf("%d",&num);
   while(num != -1){
      acolar(&p, &u, crear_nodo(num));
      printf("Ingrese un numero");
      scanf("%d",&num);
   }


   printf("\nVamos a desacolar todo: \n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p), &productoria);
   }
   printf("La productoria de los multiplos de 7 es: %d",productoria);
   return 0;
}
