#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux,int *cont, int *acum, int *cont1, int ultimo, int *cont2, int primero, int *cont3)

{
     	if (aux.dato%2!=0)
            *cont=*cont+1;
        if (aux.dato%3==0)
        {
            *acum=*acum+aux.dato;
            *cont1=*cont1+1;
        }

        if (aux.dato%ultimo==0)
               *cont2=*cont2+1;

        if (aux.dato > primero)
                *cont3=*cont3+1;

     	printf("%d \n", aux.dato);
}

nodo* crear_nodo(int dato )
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");


  	u->siguiente = *p;
  	printf("%02d p=%X u=%X\n", u->dato, *p, u);
	*p = u;
}

nodo desapilar(nodo** p)
{
	nodo* aux;
    nodo datos;

	datos=**p;

	aux=*p;

	*p=(*p)->siguiente;
	free(aux);

    return datos;
}

int main()
{


   int i,num,cont=0,acum=0, cont1=0,ultimo,cont2=0,cont3=0,primero;
   nodo* p=NULL;


   for(i=0; i<CANT; i++){
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	if (i==0)
        primero=num;
   	apilar(&p, crear_nodo(num));
   }
    ultimo=num;

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p),&cont,&acum,&cont1,ultimo,&cont2,primero,&cont3);
   }

    printf("\nla cantidad de impares es%d", cont);
    if(cont1!=0)
        printf("\n el promedio es %d",acum/cont1);
    else
        printf("\n no puedo calcular el promedio");
    printf("\n La cantidad de multiplos del ultimo numero es %d",cont2);
     printf("\n La cantidad de numero mayores al primero es %d",cont3);
   getch();
   return 0;
}
