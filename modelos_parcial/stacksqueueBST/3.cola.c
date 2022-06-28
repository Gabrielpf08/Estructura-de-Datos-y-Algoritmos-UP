/*Ingresa numeros hasta que se ingrese un 0. Mostrar el promedio de los numeros multiplos del
sexto numero ingresado. Si no hubiese ningun multiplo o no hubiese 5 numeros en la cola mostrar 
una leyenda*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *sextoelemento, int *acumProm, int *contProm, int *longitud){

    printf("%d \n", aux.dato);

    if(*longitud >= 6){
    if(aux.dato % *sextoelemento == 0 && aux.dato != *sextoelemento){
        *acumProm += aux.dato;
        *contProm += 1;
    }
    }
}

nodo* crear_nodo(int dato)
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));

   u->dato = dato;

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
  	printf("%02d p=%X u=%X\n", q->dato, *p, *u);
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

   int i = 0,num, contProm = 0, acumProm = 0, sextoelemento = 0;
   float promedio = 0;
   nodo* p=NULL;
   nodo* u=NULL;

    printf("Ingrese un numero");
    scanf("%d",&num);
    while(num != 0){

        acolar(&p, &u, crear_nodo(num));
        i++;
        if(i == 6){
            sextoelemento = num;
        }
        printf("Ingrese un numero");
        scanf("%d",&num);
   }


   printf("\nVamos a desacolar todo: \n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p), &sextoelemento, &acumProm, &contProm, &i);
   }

   if(i < 6){
       printf("No hay 6 elementos en la cola...");
   }

   if(i >= 6){

    printf("Sexto elemento: %d\n",sextoelemento);
    if(contProm == 0){
        printf("No hay multiplos del sexto elemento...");
        }

    else{
        promedio = (float)acumProm / contProm;
        printf("El promedio de los numeros multiplos del 6to elemento es %.2f",promedio);
    }

   }
      return 0;
   }
    


