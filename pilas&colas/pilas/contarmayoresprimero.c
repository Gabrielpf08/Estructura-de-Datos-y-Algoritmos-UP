#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CANT 4

typedef struct tiponodo{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *cont, int primero){
    printf("\n %d \n", aux.dato);
    if (aux.dato > primero){
        *cont=*cont+1;
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
   int i,num, cont=0, primero;
   nodo* p=NULL;

   for(i=0; i<CANT; i++){
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
       if (i==0)
        primero = num;
   	apilar(&p, crear_nodo(num));
   }

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL){
    	mostrar(desapilar(&p) ,&cont, primero);
   }
   printf("\nLa cantidad de numeros mayores al primero es: %d", cont);
   getch();
   return 0;
}
