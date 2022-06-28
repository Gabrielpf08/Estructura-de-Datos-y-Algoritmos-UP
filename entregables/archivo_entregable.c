#include <stdio.h>
#include <stdlib.h>

/*Desarrollar un programa en C que permita crear una lista simplemente enlazada con la siguiente información de una universidad:

Legajo
Edad
Cantidad de materias cursadas
Cantidad de materias aprobadas.
La carga finaliza con cero en el legajo.



Generar un archivo con aquellos alumnos con más del 50% de materias aprobadas.

Mostrarlo en pantalla.*/

typedef struct universidad{
	int legajo;
  int edad;
  int cursadas;
  int aprobadas;
	struct universidad *sig;
 }nodo;

void crear (nodo *r)
{
    printf("\nIngrese numero de legajo: \n");
    scanf("%d",&r->legajo);

    if (r->legajo==0)//condicion de corte
        r->sig=NULL;
    else
	{
        printf("Ingrese Edad: \n");
        scanf("%d",&r->edad);

        printf("Ingrese materias cursadas: \n");
        scanf("%d",&r->cursadas);

        printf("Ingrese materias aprobadas: \n");
        scanf("%d",&r->aprobadas);

        r->sig = (nodo*)malloc(sizeof(nodo));
        crear (r->sig);

	}
	return;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("\nLegajo: %d\n",registro->legajo);
        printf ("Edad: %d\n",registro->edad);
        printf ("Materias cursadas: %d\n",registro->cursadas);
        printf ("Materias aprobadas: %d\n",registro->aprobadas);
        mostrar (registro->sig);
	}
	return;
}

int main()
{

    nodo *p=NULL;
    p=(nodo*)malloc(sizeof(nodo));
    crear(p);
    mostrar (p);

    return 0;
}