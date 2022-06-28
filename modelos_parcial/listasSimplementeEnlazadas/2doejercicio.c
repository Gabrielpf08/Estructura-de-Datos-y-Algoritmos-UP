/*
a)	Crear y mostrar la lista con números enteros. Termina con num=-2.
b)	Insertar en otra lista los números impares. Mostrarla.
c)	Eliminar todos los valores menores al promedio de la lista original en la lista de números impares. Mostrarla
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
  int num;
  struct list *sig;
}nodo;

void crear(nodo *r){
  printf("Ingrese un numero: ");
  scanf("%d", &r->num);

  if (r->num==-2)
    r->sig=NULL;
  
  else{
    r->sig = (nodo *)malloc(sizeof(nodo));
    crear(r->sig);  
  }
}

void mostrar(nodo *r){

  if (r->sig!=NULL){
    printf("\nEl numero de su lista es: %d", r->num);
    mostrar(r->sig);
  }
}

void generar(nodo *h, nodo *a){

	while(h->sig!=NULL){

		if(h->num % 2 != 0){
			a->num=h->num;
			a->sig=(nodo *)malloc(sizeof(nodo));
			a=a->sig;
		}
		h=h->sig;
	}
	a->sig=NULL;
}

float recorrer(nodo *r){

int cont=0;
float suma = 0;

while(r->sig!=NULL){
    suma = suma + r->num;
    r=r->sig;
    cont++;
    }
  return suma / cont;
}

nodo* eliminar1(nodo* p,int promedio)
{
    nodo *aux;
    while(p->num < promedio)//condicion de eliminacion
    {
        aux=p->sig;
        free(p);
        p=aux;

    }
    return p;
}

void eliminar(nodo *h, int promedio){
  nodo *aux=NULL;
  while(h->sig!=NULL && h->sig->sig!=NULL)
  if(h->sig->num < promedio){
    aux=h->sig->sig;
    free(h->sig);
    h->sig=aux;
  }
  else
    h=h->sig;
}
int main() {
  float promedio;
  nodo *p = NULL;
  nodo *q = NULL;
  nodo *s = NULL;
  p = (nodo *)malloc(sizeof(nodo));
  q = (nodo *)malloc(sizeof(nodo));

  crear(p);
  mostrar(p);
  promedio = recorrer(p);
  printf("\n");
  printf("\nEl promedio es %.2f", promedio);
  printf("\n");
  printf("\nLa lista con los numeros impares es: ");
  generar(p, q);
  mostrar(q);
  printf("\n");
  printf("\nEliminar los valores menores al promedio impares: ");
  eliminar1(q, promedio);
  eliminar(q, promedio);
  mostrar(q);
  

  return 0;
}