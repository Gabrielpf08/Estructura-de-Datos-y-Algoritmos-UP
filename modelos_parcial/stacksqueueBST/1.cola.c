#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Desarrollar una función que permita mostrar el promedio de tres primeros
números ingresados a la cola. Si no hubiese tres números, mostrar una leyenda y
no calcular el promedio. */

typedef struct tiponodo{ //First In Last Out FIFO
	int num;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *cont,int *acumulador,int *posicion){  
     	printf("Posicion: %d Numero: %d \n",*posicion, aux.num);
         if(*posicion < 3){
            *acumulador += aux.num;
            *cont += 1;
        }
        *posicion -= 1;

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

    int i,num,cont=0,acumulador,posicion=0, longitud;
    float promedio = 0;
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
    	mostrar(desapilar(&p), &cont, &acumulador,&posicion);
   }
    promedio = (float)acumulador / (float)cont;
    if (longitud < 3){
        printf("No hay suficientes valores para calcular el promedio... ");
    }
    else {
        printf("El promedio de los primeros 3 numeros que entraron a la cola es: %.2f \n",promedio);
    }
    return 0;
}

