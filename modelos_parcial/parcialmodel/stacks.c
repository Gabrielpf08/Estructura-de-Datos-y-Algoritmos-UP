#include<stdio.h>
#include<stdlib.h> //LIFO
#include<string.h>

/*sumatoria multiplos de del ultimo numero ingresado en la pila, 
si no hubiera ninguno mostrar leyenda*/

typedef struct tiponodo{
	int num;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *sumatoriaMultiplosUlt, int *ultimo){

     	printf("%d \n", aux.num);
        if (*ultimo % aux.num  == 0 && aux.num != *ultimo){
            *sumatoriaMultiplosUlt += aux.num;
        }
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
  	printf("%02d p=%X u=%X\n", u->num, *p, u);
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

   int i,num, ultimo, sumatoriaMultiplosUlt = 0, longitud;
   nodo* p=NULL;
   printf("Ingrese la longitud de la fila: %n");
   scanf("%d", &longitud);

   for(i=0; i < longitud; i++){
   	printf("Ingrese un numero: \n");
   	scanf("%d",&num);
   	apilar(&p, crear_nodo(num));
   }
   ultimo = num;

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL){

    	mostrar(desapilar(&p), &sumatoriaMultiplosUlt, &ultimo);
   }
    if (sumatoriaMultiplosUlt == 0)
        printf("No hay ningun valor multiplo del ultimo numero...");
    else{
    	printf("\nLa sumatoria de los multiplos del ultimo numero ingresado es: %d\n", sumatoriaMultiplosUlt);
        }
   return 0;
}
