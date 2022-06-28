#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Desarrollar un programa en C que permita cargar un pila de n números enteros. Calcular y mostrar (en una función no en el programa principal) 
en el promedio de los cuatro primeros números ingresados a la pila. Si no los hubiera, mostrar un cartel aclaratorio.*/

typedef struct tiponodo{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *posicion, int *contador, int *acumulador, float *promedio, int longitudPila){

    printf("\nPosicion: %d. Dato: %d\n", *posicion, aux.dato);
    
    if (longitudPila  4){
        *acumulador += aux.dato;
        
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
    printf("Apilar Nodo\n");
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
   int i,num, longitudPila, posicion = 1, contador = 0, acumulador = 0;
   float promedio;
   nodo* p=NULL;

    printf("Ingrese El tamanio de su pila: ");
    scanf("%d",&longitudPila);
    longitudPila = posicion;
    for(i=0; i<longitudPila; i++){
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	apilar(&p, crear_nodo(num));
   }

   printf("\nDESAPILAR TODO: \n");
	while(p!=NULL){
    	mostrar(desapilar(&p),&posicion, &contador, &acumulador, &promedio, longitudPila);
   }
    if (longitudPila >= 4){
        promedio = (float)acumulador / contador;
        printf("\nEl promedio de los 4 primeros digitos de la pila es: %.2f", promedio);
    }
    else{
        printf("\nNo se puede calcular el promedio, hay menos de 4 numeros...");
    }
   return 0;
}
