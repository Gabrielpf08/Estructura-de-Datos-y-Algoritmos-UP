/*La cadena de hoteles Hilton tiene establecimientos en todo el mundo. Para conocer las ganancias, se ingresa código de país, numero de establecimiento y su recaudación mensual (en millones de dólares) en una lista simplemente enlazada.

El ingreso de datos termina con el código de país igual a cero.

Se deben ingresar los datos ordenados por país y establecimiento.

Mostrar la lista.

 Insertar un nodo al final de la lista con 100 en código de pais, 0 en numero de establecimiento y la recaudación de todos los hoteles ingresados.

 Eliminar de la lista original aquellos establecimientos con recaudación inferior al promedio de todos los establecimientos ingresados.

 Ingresar un nuevo hotel con el código de país y la recaudación mensual e Insertarlas en orden en la lista.
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
	int cod_pais;
	int nro_establecimiento;
	int recaudacion;
	struct lista *sig;
 }nodo;

void crear (nodo *registro)
{
	printf("Ingrese el codigo de pais: \n");
    scanf("%d",&registro->cod_pais);

    if (registro->cod_pais==0)
        registro->sig=NULL;

    else
	{
		printf("Ingrese el numero de establecimiento: \n");
		scanf("%d",&registro->nro_establecimiento);
		printf("Ingrese la recaudacion mensual: \n");
		scanf("%d",&registro->recaudacion);
        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig);
	}
	return;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("\nCodigo Pais: %d\n",registro->cod_pais);
		printf("Numero de establecimiento: %d \n",registro->nro_establecimiento);
		printf("Recaudacion Mensual: %d \n",registro->recaudacion);
        mostrar (registro->sig);
	}
	return;
}

void insertar_final (nodo *p){
	int total_recaudado = p->recaudacion;
	nodo *nuevo;

	while(p->sig->sig != NULL){
		p = p->sig;
		total_recaudado += p->recaudacion; 
	}

	nuevo =(nodo *)malloc(sizeof(nodo));
	nuevo->cod_pais = 100;
	nuevo->nro_establecimiento = 0;
	nuevo->recaudacion = total_recaudado;
	nuevo->sig = p->sig;
	p->sig = nuevo;

}

float recorrer_promedio(nodo *p){
	int contador = 0;
	int acumulador = 0;
	while(p->sig != NULL){
        acumulador += p->recaudacion;
        p = p->sig;
        contador += 1;
    }
    return (float)acumulador / contador;
}

nodo* eliminarPorCabeza(nodo* p, float promedio)
{
    nodo *datoNuevoHotel;
    while(p->recaudacion < promedio)//condicion de eliminacion
    {
        datoNuevoHotel=p->sig;
        free(p);
        p=datoNuevoHotel;

    }
    return p;
}

void eliminar2(nodo* p, float promedio)
{
    nodo *datoNuevoHotel;
    
    while(p->sig!=NULL&& p->sig->sig!=NULL)
    {
        if(p->sig->recaudacion < promedio)//condicion de eliminacion
        {
            datoNuevoHotel=p->sig->sig;
            free(p->sig);
            p->sig=datoNuevoHotel;
        }
        else
        {
            p=p->sig;
        }
    }

}

void ingreso_nuevo_hotel(nodo *p)
{
    printf("Ingrese codigo de pais a insertar: ");
    scanf("%d",&p->cod_pais);

    printf("Ingrese el nuevo numero de establecimiento: ");
    scanf("%d",&p->nro_establecimiento);

    printf("Ingrese la nueva cantidad recaudada: ");
    scanf("%d",&p->recaudacion);
}

/*Inserta en orden, por cabeza y en cualquier posicion, se le pasa por parametro la lista original
y los datos de la lista a ingresar*/

nodo *insertar_ordenado(nodo *registro, nodo *datoNuevoHotel) {
    
    nodo *nuevo, *aux;
    
    nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->cod_pais = datoNuevoHotel->cod_pais;

    if (registro == NULL || registro->cod_pais > datoNuevoHotel->cod_pais && registro->nro_establecimiento > datoNuevoHotel->nro_establecimiento){ 
        /*Lista vacia o primer elemento > nuevo*/
        nuevo->sig = registro;
        nuevo->cod_pais = datoNuevoHotel->cod_pais;
        nuevo->nro_establecimiento = datoNuevoHotel->nro_establecimiento;
        nuevo->recaudacion = datoNuevoHotel->recaudacion;
        return nuevo;
    }
    /*Si llega hasta aca => lista no vacia y nuevo > primer*/
    
    aux = registro;
    while (aux->sig != NULL && aux->sig->cod_pais <= datoNuevoHotel->cod_pais && aux->sig->nro_establecimiento <=datoNuevoHotel->nro_establecimiento){

        aux = aux->sig;
    }
    /*Salio del ciclo => aux->sig es NULL o aux->sig->dato > d*/
    /*Inserto el nuevo entre aux y aux->sig*/
    nuevo->sig = aux->sig;
    nuevo->cod_pais = datoNuevoHotel->cod_pais;
    nuevo->nro_establecimiento = datoNuevoHotel->nro_establecimiento;
    nuevo->recaudacion = datoNuevoHotel->recaudacion;
    aux->sig = nuevo;
    return registro;
}

int main()
{
    float promedio = 0;

    nodo *prin=NULL;
    nodo *datoNuevoHotel=NULL;

    prin=(nodo*)malloc(sizeof(nodo));
    datoNuevoHotel=(nodo*)malloc(sizeof(nodo));
    

    crear(prin);
    ingreso_nuevo_hotel(datoNuevoHotel);
    mostrar (prin);

    printf("\nLista con insercion ordenada por codigo pais\n");
    prin = insertar_ordenado(prin, datoNuevoHotel);
    mostrar(prin);

    promedio = recorrer_promedio(prin);
    printf("\nEl promedio es: %.2f\n",promedio);

    printf("\nLista con insercion al final\n");
    insertar_final(prin);
	mostrar(prin);

    printf("\nLista con eliminaciones\n");
    prin = eliminarPorCabeza(prin, promedio);
    eliminar2(prin, promedio);
    mostrar(prin);

    return 0;
}

