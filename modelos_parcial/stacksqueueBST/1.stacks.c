/*Ejercicio nª2
Crear una pila con la siguiente información:
 num: numero entero.
 siguiente: puntero al próximo elemento de la pila.

Desarrollar una función que permita mostrar la sumatoria de números
mayores al primer elemento ingresado en la pila. Si no hubiera ningún
número mostrar una leyenda.*/

#include<stdio.h> //LAST IN FIRST OUT
#include<stdlib.h>
#include<string.h>

typedef struct tiponodo{
	int num;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int primero, int *contMayoresPrimero){
    printf("\n %d \n", aux.num);
    if (aux.num > primero){
        *contMayoresPrimero += aux.num;
    }
}

nodo* crear_nodo(int num ){
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->num = num;
   u->siguiente = NULL;
   return u;
}

void apilar(nodo** p, nodo* u){
    printf("apilar_nodo\n");
  	u->siguiente = *p;
  	printf("%02d p=%X u=%X\n", u->num, *p, u);
	*p = u;
}

nodo desapilar(nodo** p){
	nodo* aux;
    nodo datos;
	datos=**p;
	aux=*p;
	*p=(*p)->siguiente;
	free(aux);

    return datos;
}

int main(){
    int i,num, primer, contMayoresPrimero = 0, cantidadElementos;
    nodo* p=NULL;
    printf("Ingrese la cantidad de elementos de su pila: \n");
    scanf("%d", &cantidadElementos);

   for(i=0; i<cantidadElementos; i++)
   {
   	printf("Ingrese un numero: \n");
   	scanf("%d",&num);
    if (i == 0)
        primer = num;

   	apilar(&p, crear_nodo(num));
   }

   printf("Vamos a desapilar todo: \n");
	while(p!=NULL){
    	mostrar(desapilar(&p),primer, &contMayoresPrimero);
   }
   if (cantidadElementos == 0){
       printf("No hay elementos en la Pila...\n");
   }
   else {
       printf("\nLa sumatoria de los numeros mayores al primero es: %d",contMayoresPrimero);
 }
   
   getch();
   return 0;
}
