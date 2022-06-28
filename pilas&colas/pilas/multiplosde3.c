#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CANT 4

typedef struct tiponodo{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *contmultiplos){
    printf("\n %d \n", aux.dato);
    if (aux.dato % 3 == 0){
        *contmultiplos += 1;
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
   int i,num, contmultiplos = 0;
   nodo* p=NULL;

    printf("Ingrese un numero \n");
   	scanf("%d",&num);
   while(num != -1)
   {
    apilar(&p, crear_nodo(num));
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	
   }

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL){
    	mostrar(desapilar(&p), &contmultiplos);
   }
   printf("Cantidad multiplos 3: %d",contmultiplos);
   getch();
   return 0;
}
