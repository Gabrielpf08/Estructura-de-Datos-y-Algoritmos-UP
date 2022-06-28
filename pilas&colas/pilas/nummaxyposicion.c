#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * 
 * 
4) El número máximo y su posición en la pila.*/

typedef struct tiponodo{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *posicion, int *posicionmax, int *maximo){
    printf("\nPosicion: %d Numero: %d \n",*posicion, aux.dato);
    if(aux.dato > *maximo){
        *maximo = aux.dato;
        *posicionmax = *posicion;
    }
    *posicion -= 1;
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
  	printf("%02d p=%X u=%X\n", u->dato, *p, u);
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
   int longitud,num, posicion = 0, posicionmax = 0, maximo = 0;
   nodo* p=NULL;

    while(num != -1){
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
       if(num != -1){
   	        apilar(&p, crear_nodo(num));
               longitud++;
   }
    }
    posicion = longitud;

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL){
    	mostrar(desapilar(&p), &posicion, &posicionmax, &maximo);
   }
   printf("\nMaximo: %d Posicion: %d",maximo, posicionmax);
   return 0;
}
