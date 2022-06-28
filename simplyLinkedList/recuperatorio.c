/*se ingresan los siguientes datos de empleados de una empresa. Nro_legajo, 
nombre y apellido, anios de antiguedad en la empresa y sueldo. aumentar15porciento una lista
simplemente enlazada con estos datos, la carga finaliza con nro_legajo = 0

aumentar 15 porciento nueva lista con empleados mayores a 15 anios y aumentar el sueldo un 15% 

Generar una nueva lista con el sueldo de cada empleado y al final insertar el monto total que la empresa debe pagar en sueldos

Eliminar de la lista original a aquellos empleados que tienen menos de 4 anios de antiguedad*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista{
	int legajo;
    char nyape[30];
    int antiguedad;
    int sueldo;
	struct lista *sig;
 }nodo;

void crear (nodo *registro)
{
    printf("Ingrese el numero de legajo: ");
    scanf("%d",&registro->legajo);

    if (registro->legajo==0)
        registro->sig=NULL;

    else
	{
        printf("Ingrese nombre y apellido: \n");
        scanf("%s", registro->nyape);

        printf("Ingrese anios de antiguedad: \n");
        scanf("%d",&registro->antiguedad);

        printf("Ingrese sueldo: \n");
        scanf("%d",&registro->sueldo);    

        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig);
	}
	return;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
	{

        printf ("\nLegajo: %d\n",registro->legajo);
        printf ("Nombre y apellido: %s\n",registro->nyape);
        printf ("Anios de antiguedad: %d\n",registro->antiguedad);
        printf ("Sueldo: %d\n",registro->sueldo);

        mostrar (registro->sig);
	}
	return;
}

void mostrar2 (nodo *registro)
{
    if (registro->sig != NULL)
	{
        printf ("\nNombre y apellido: %s\n",registro->nyape);
        printf ("Sueldo: %d\n",registro->sueldo);

        mostrar2 (registro->sig);
	}
	return;
}

void aumentar15porciento(nodo *registro, nodo *q){

	while(registro->sig != NULL){

        if(registro->antiguedad > 10){

       		q->legajo = registro->legajo;
            strcpy(q->nyape, registro->nyape);        
            q->antiguedad = registro->antiguedad;
		    q->sueldo = registro->sueldo * 1.15;
			q->sig=(nodo *)malloc(sizeof(nodo));
			q=q->sig;
			}
		registro = registro->sig;
		}
	q->sig=NULL;
	}

void generarListaSueldoEmpleados(nodo *h, nodo *a){

	while(h->sig != NULL){

		strcpy(a->nyape, h->nyape);
		a->sueldo = h->sueldo;
		a->sig=(nodo *)malloc(sizeof(nodo));
		a=a->sig;
		h=h->sig;
	}
	a->sig=NULL;
	}

void insertar_final (nodo *p){//insertar al final un nuevo empleado con la recaudacion total
    
    
	int total_sueldo = p->sueldo;
	nodo *nuevo;
	
	while(p->sig->sig != NULL){
		p = p->sig;
		total_sueldo += p->sueldo; 
	}

	nuevo =(nodo *)malloc(sizeof(nodo));;
	nuevo->sueldo = total_sueldo;
	nuevo->sig = p->sig;
	p->sig = nuevo;

}

nodo* eliminarPorCabeza(nodo* p)
{
    nodo *aux;
    while(p->antiguedad < 4)//condicion de eliminacion
    {
        aux=p->sig;
        free(p);
        p=aux;

    }
    return p;
}

void eliminar2(nodo* p)
{
    nodo *aux;
    
    while(p->sig != NULL && p->sig->sig!=NULL)
    {
        if(p->sig->antiguedad < 4)//condicion de eliminacion
        {
            aux=p->sig->sig;
            free(p->sig);
            p->sig=aux;
        }
        else
        {
            p=p->sig;
        }
    }

}

int main()
{

    nodo *prin=NULL;
    nodo *q = NULL;
	nodo *h =NULL;

    prin=(nodo*)malloc(sizeof(nodo));
    q = (nodo*)malloc(sizeof(nodo));
	h = (nodo*)malloc(sizeof(nodo));
    
    crear(prin);
    mostrar (prin);

    printf("\nAUMENTO 15 PORCIENTO MAYORES 10 ANIOS \n");
    aumentar15porciento(prin, q);
    mostrar(q);

	printf("\nLISTA NOMBRES Y SUELDOS INSERCION TOTAL AL FINAL:\n");
	generarListaSueldoEmpleados(prin, h);
	insertar_final(h);
	mostrar2(h);

	printf("\nLISTA CON ELIMINACIONES MENORES A 4 ANIOS\n");
	prin = eliminarPorCabeza(prin);
	eliminar2(prin);
	mostrar(prin);

    return 0;
}