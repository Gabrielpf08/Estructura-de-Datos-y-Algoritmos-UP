#include <stdio.h>
#include <stdlib.h>

/*Crear una cola con la siguiente informacion.

El ingreso de datos termina con -1.

escribir una funcion que permita calcular 

el promedio de los numeros mayores al tercer elemento ingresado a la cola,
si no hubiera algun numero mostrar una leyenda

La sumatoria de los dos elementos minimos de la cola*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tiponodo
{
	int num;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *longitud, int *minimo1, int *minimo2,int *contPromedio,int *acumPromedio, int *posicion){

  	printf("posicion: %d Numero: %d \n", *posicion, aux.num);
        
        if (aux.num < *minimo1){

        *minimo2 = *minimo1;
        *minimo1 = aux.num;
        }

        if(aux.num < *minimo2 && aux.num != *minimo1){
            *minimo2 = aux.num;
        }

      if(aux.num > *minimo1 && aux.num < *minimo2){
        *minimo2 = aux.num;
      }

      if(*posicion > 3){
          *acumPromedio += aux.num;
          *contPromedio += 1;
      }
      *posicion += 1;
}

nodo* crear_nodo(int num)
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->num = num;
   u->siguiente = NULL;
   return u;
}

void acolar(nodo** p,nodo** u, nodo *q)
{
   printf("acolar_nodo\n");
	if(*p==NULL)
    *p = *u = q; /*porque hay uno solo*/
   else
   {
    	(*u)->siguiente = q;
    	(*u) = q;
   }
  	printf("%02d p=%X u=%X\n", q->num, *p, *u);
}

nodo desacolar(nodo** inicio)
{
	nodo* aux;
   nodo datos;

	datos=**inicio;

	aux=*inicio;

	*inicio=(*inicio)->siguiente;
	free(aux);

    return datos;
}

int main()
{

   int longitud ,num = 0, minimo1 , minimo2 = 0, contPromedio = 0, acumPromedio = 0, posicion = 1;
   float promedio = 0;
   nodo* p=NULL;
   nodo* u=NULL;

    printf("Ingrese un numero");
    scanf("%d",&num);
   while (num != -1)
   {
        acolar(&p, &u, crear_nodo(num));
        longitud++;
        minimo1 = minimo2;
        minimo2 = num;
        printf("Ingrese un numero");
        scanf("%d",&num);
   }
   


   printf("\nVamos a desacolar todo: \n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p), &longitud, &minimo1, &minimo2, &contPromedio, &acumPromedio, &posicion);
   }
   promedio = (float)acumPromedio / (float)contPromedio;
   if(longitud <= 3){
       printf("No se puede calcular el promedio, hay menos de 3 datos ingresados...");
   }
   else{
       printf("\nPromedio: %.2f\n", promedio);
   }
   
   printf("\nPrimer Minimo: %d\n",minimo1);
   printf("Segundo Minimo: %d\n",minimo2);
   printf("Suma de los minimos: %d",minimo1+minimo2);
   return 0;

}