#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Ejercicio nª3
Crear una cola con la siguiente información:
 num: numero entero.
 siguiente: puntero al próximo elemento de la cola.

Escribir una función para calcular el máximo elemento de la cola y en qué posición
está.*/

typedef struct tiponodo{ //First In Last Out FIFO
	int num;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *maximo, int *posicion, int *posmax){  
     	printf("Posicion: %d Numero: %d \n",*posicion, aux.num);
         if(*maximo < aux.num){
             *maximo = aux.num;
             *posmax = *posicion;
        }
        *posicion -=1;
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
  	printf("%02d p=%p u=%p\n", u->num, *p, u);
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

    int i,num, maximo = 0,posicion=0, longitud, posmax =0;
    nodo* p=NULL;

    printf("Ingrese longitud cola: \n");
    scanf("%d",&longitud);
    posicion = longitud;

    for (i=0; i < longitud; i++){
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	apilar(&p, crear_nodo(num));
   }

    printf("\nVamos a desapilar todo\n");
	while(p!=NULL){
    	mostrar(desapilar(&p), &maximo, &posicion, &posmax);
   }
   printf("El valor maximo es: %d en la posicion: %d",maximo,posmax);
    }



