#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Ingresar numeros en la pila hasta que el usuario ingrese 0 mostrar y calcular la sumatoria 
de numeros menores al tercer elemento ingresado a la pila. si no hubiera ningun numero o la pila 
es menor a 3 elementos mostrar leyenda:*/

typedef struct tiponodo{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *tercerelemento, int *sumatoria){

    printf("\n %d \n", aux.dato);

        if(aux.dato < *tercerelemento){
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
    printf("apilar_nodo");
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
   int i = 0,num, tercerelemento = 0, sumatoria = 0;
   nodo* p=NULL;

    printf("Ingrese un numero \n");
   	scanf("%d",&num);
    while(num != 0)
   {
    apilar(&p, crear_nodo(num));
    i += 1;
    if(i == 3){
        tercerelemento = num;
    }
    printf("Ingrese un numero \n");
   	scanf("%d",&num);
   }

   printf("Vamos a desapilar todo\n");
	while(p!=NULL){
    	mostrar(desapilar(&p), &tercerelemento, &sumatoria);
   }

   if(i < 3){
       printf("Hay menos de 3 elementos, no se puede operar...");
   }
   else{
       
        printf("Tercer elemento: %d",tercerelemento);
        printf("\nSumatoria numeros menores al tercer elemento: %d",sumatoria);

   }
   
   return 0;
}
