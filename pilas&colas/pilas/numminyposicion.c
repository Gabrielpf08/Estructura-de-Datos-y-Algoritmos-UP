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

void mostrar (nodo aux, int *posicion, int *posicionmin, int *minimo){
    printf("\nPosicion: %d Numero: %d \n",*posicion, aux.dato);
    if(aux.dato < *minimo){
        *minimo = aux.dato;
        *posicionmin = *posicion;
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
   int longitud,num, posicion = 0, posicionmin = 0, minimo = 0;
   nodo* p=NULL;

    printf("Ingrese un numero \n");
   	scanf("%d",&num);

    while(num != -1){
   	    apilar(&p, crear_nodo(num));
        longitud++;
        minimo = num;
        printf("Ingrese un numero \n");
   	    scanf("%d",&num);
    }
    posicion = longitud;
    

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL){
    	mostrar(desapilar(&p), &posicion, &posicionmin, &minimo);
   }
   printf("\nminimo: %d Posicion: %d",minimo, posicionmin);
   return 0;
}
