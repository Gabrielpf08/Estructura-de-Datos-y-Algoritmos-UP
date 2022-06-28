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

void mostrar (nodo aux, int *longitud, int *primerMinimo, int *segundoMinimo,int *contPromedio,int *acumPromedio, int *posicion){

  	printf("posicion: %d Numero: %d \n", *posicion, aux.num);
        
        if (aux.num < *primerMinimo){

        *segundoMinimo = *primerMinimo;
        *primerMinimo = aux.num;
        }

        if(aux.num < *segundoMinimo && aux.num != *primerMinimo){
            *segundoMinimo = aux.num;
        }

      if(aux.num > *primerMinimo && aux.num < *segundoMinimo){
        *segundoMinimo = aux.num;
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

   int longitud ,num = 0, primerMinimo , segundoMinimo = 0, contPromedio = 0, acumPromedio = 0, posicion = 1;
   float promedio = 0;
   nodo* p=NULL;
   nodo* u=NULL;

    printf("Ingrese un numero");
    scanf("%d",&num);
   while (num != -1)
   {
        acolar(&p, &u, crear_nodo(num));
        longitud++;
        primerMinimo = segundoMinimo;
        segundoMinimo = num;
        printf("Ingrese un numero");
        scanf("%d",&num);
   }

   printf("\nVamos a desacolar todo: \n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p), &longitud, &primerMinimo, &segundoMinimo, &contPromedio, &acumPromedio, &posicion);
   }
   promedio = (float)acumPromedio / (float)contPromedio;
   if(longitud <= 3){
       printf("No se puede calcular el promedio, hay menos de 3 datos ingresados...");
   }
   else{
       printf("\nPromedio: %.2f\n", promedio);
   }
   
   printf("\nPrimer Minimo: %d\n",primerMinimo);
   printf("Segundo Minimo: %d\n",segundoMinimo);
   printf("Suma de los minimos: %d",primerMinimo + segundoMinimo);
   return 0;

}