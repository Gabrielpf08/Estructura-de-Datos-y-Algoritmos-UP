/*Escribir una funcion que permita calcular el promedio de los numeros 
mayores al primer elemento agregado a la fila*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tiponodo{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *primero, int *contador, int *acumulador){
  	printf("%d \n", aux.dato);
    if(aux.dato > *primero){
        *acumulador += aux.dato;
        *contador += 1;
    }
    
}

nodo* crear_nodo(int dato){
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;
   u->siguiente = NULL;

   return u;
}

void acolar(nodo** p,nodo** u, nodo *q){
   printf("acolar_nodo\n");
	if(*p==NULL)
    *p = *u = q; /*porque hay uno solo*/
   else{
    	(*u)->siguiente = q;
    	(*u) = q;
   }
  	printf("%02d p=%X u=%X\n", q->dato, *p, *u);
}

nodo desacolar(nodo** inicio){
	nodo* aux;
    nodo datos;
	datos=**inicio;
	aux=*inicio;
	*inicio=(*inicio)->siguiente;
	free(aux);
    return datos;
}

int main(){

   int i,num, longitud, primero, contador = 0, acumulador = 0;
   float promedio;
   nodo* p=NULL;
   nodo* u=NULL;

   printf("Ingrese la longitud de la fila: %n");
   scanf("%d", &longitud);

   for(i=0; i < longitud; i++){
       printf("Ingrese un numero");
       scanf("%d",&num);
       if(i == 0)
            primero = num;
        acolar(&p, &u, crear_nodo(num));

   }

   printf("\nVamos a desacolar todo: \n");
	while(p!=NULL){
    	mostrar(desacolar(&p), &primero, &contador, &acumulador);
   }

   promedio = (float)acumulador / contador;

   if (acumulador == 0)
        printf("No hay numeros mayores al primero, no se puede realizar el calculo...\n");
    else{
        printf("EL promedio de los numeros ingresados mayores al primero es: %.2f",promedio);
    }
   return 0;
}
