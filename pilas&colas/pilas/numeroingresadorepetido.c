/**
 
 * 6) Ingresar un numero por teclado y calcular la cantidad de veces que está en la pila.
    Si no está, mostrar una leyenda.
 * 
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CANT 4

typedef struct tiponodo{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int * seleccion, int *contador){
    printf("\n %d \n", aux.dato);
    if(aux.dato == *seleccion){
        *contador += 1;
    }
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
   int i,num = 0, seleccion, contador = 0;
   nodo* p=NULL;

    printf("Seleccione un numero: ");
    scanf("%d",&seleccion);

    apilar(&p, crear_nodo(num));
    printf("Ingrese un numero: \n");
   while(num != -1){
        apilar(&p, crear_nodo(num));
        printf("Ingrese un numero: \n");
        scanf("%d",&num);
   }

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL){
    	mostrar(desapilar(&p), &seleccion, &contador);
   }
    if(contador == 0){
        printf("El numero no esta en la Pila");
    }
   else{
       printf("El numero %d esta %d veces en la Pila",seleccion, contador);
   }

   return 0;
}
