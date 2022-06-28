#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CANT 4

typedef struct tiponodo{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *primero, int *sumatoria){
    printf("\n %d \n", aux.dato);
    if(aux.dato % *primero ==  0 && *primero != aux.dato){
        *sumatoria += aux.dato;
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

   int i,num, primero = 0, sumatoria = 0;
   nodo* p=NULL;
    
    printf("Ingrese un numero \n");
   	scanf("%d",&num);

    while (num!=-1) {
        if (i == 0){
           primero = num;
       }
   	apilar(&p, crear_nodo(num));
       i++;
          	printf("Ingrese un numero \n");
   	scanf("%d",&num);

       
   }

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL){
    	mostrar(desapilar(&p), &primero, &sumatoria);
   }
   printf("Primero: %d",primero);
   printf("La sumatoria de los numeros multiplos del primer numero es: %d",sumatoria);
    return 0;
}
