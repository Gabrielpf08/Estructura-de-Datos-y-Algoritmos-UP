/*Desarrollar un programa en C que permita cargar un cola de n números enteros. Calcular y mostrar 
(en una función y no en el programa principal) la sumatoria de los elementos en 
posición par de la cola. 
(se considera que el primer que entra está en la posición uno y así sucesivamente).*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4

typedef struct tiponodo{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *suma, int *cont){  
     	printf("Posicion: %d Dato: %d\n", *cont, aux.dato);
            *cont = *cont+1;
            if(*cont % 2 ==0)
		        *suma +=aux.dato;
}

nodo* crear_nodo(int dato ){
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;
   u->siguiente = NULL;
   return u;
}

void apilar(nodo** p, nodo* u){
    printf("apilar_nodo\n");
  	u->siguiente = *p;
  	printf("%02d p=%p u=%p\n", u->dato, *p, u);
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

   int i,num, suma = 0, cont = 0;
   nodo* p=NULL;

   for(i=0; i<CANT; i++){
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	apilar(&p, crear_nodo(num));
   }

   printf("\nDESAPILAR:\n\n");
	while(p!=NULL){
    	mostrar(desapilar(&p),&suma, &cont);
   }
   printf("\nLa Suma de los datos en posiciones pares es: %d",suma);
   return 0;
}

