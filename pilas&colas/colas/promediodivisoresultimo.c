#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 10

typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *acumprom, int *contprom, int *ultimo)
{
  	printf("%d \n", aux.dato);
    if(aux.dato % *ultimo == 0){
        *acumprom += aux.dato;
        *contprom += 1;
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

   int num, contpromedio = 0, acumpromedio = 0, ultimo =0;
   float promedio = 0;
   nodo* p=NULL;
   nodo* u=NULL;

    printf("Ingrese un numero");
    scanf("%d",&num); 
   while(num!=-1)
   {
    acolar(&p, &u, crear_nodo(num));
    ultimo = num;
    printf("Ingrese un numero");
    scanf("%d",&num);
    

   }


   printf("\nVamos a desacolar todo: \n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p), &acumpromedio, &contpromedio, &ultimo);
   }
   promedio = (float)acumpromedio / contpromedio;
   printf("Promedio Multiplos Ultimo ingresado: %.2f",promedio);
   return 0;
}
