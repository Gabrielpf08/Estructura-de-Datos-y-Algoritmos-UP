/*Crear una lista simplemente enlazada con el número de legajo, nombre y apellido y cantidad de materias aprobadas de los alumnos de una facultad. La carga de datos finaliza cuando el número de legajo es igual a cero.

Mostrar la lista.
Mostrar cuántos alumnos tiene más de 10 materias aprobadas.
Generar una nueva lista con aquellos alumnos que tiene menos de 3 materias aprobadas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct numeros{
        int legajo;
        char nombre[30];
        char apellido[30];
        int aprobadas; 
        struct numeros *sig;
        }nodon;


void crearlista(nodon *h){

	printf("ingrese su numero de legajo: ");
	scanf("%d",&h->legajo);

	if (h->legajo==0) //condicion de corte
		h->sig=NULL;
	
  else{  //consignas

		printf("ingrese Nombre: ");
		scanf("%s", h->nombre);
    printf("Ingrese apellido: ");
    scanf("%s", h->apellido);
    printf("Ingrese cantidad de materias aprobadas: ");
    scanf("%d",&h->aprobadas);

    h->sig=(nodon*)malloc(sizeof(nodon));
		crearlista(h->sig); //Recursividad
	}

}
void mostrarlista(nodon *h){
	if (h->sig!=NULL){ //Siguiente no devuelve ningun valor.
    printf("\n");
		printf("Legajo Numero: %d \n",h->legajo);
		printf("Nombre: %s \n",h->nombre);
    printf("Apellido: %s \n", h->apellido);
    printf("Total materias aprobadas: %d \n", h->aprobadas);
    printf("\n");
		mostrarlista(h->sig);
		
	}
	
}

int recorrer(nodon *h){
  int cont = 0;
  while(h->sig != NULL){
    if(h->aprobadas > 10)
    cont++;
    h = h->sig;
  }

  return cont;
}

void generar(nodon *h, nodon *t){
  
  while(h->sig!=NULL){ 
    
    if (h->aprobadas < 3){
    
      t->legajo=h->legajo;
      strcpy(t->nombre,h->nombre);
    
      t->aprobadas=h->aprobadas;
      t->sig=(nodon *)malloc(sizeof(nodon));
      
      t=t->sig;
    }
    h=h->sig;
  }
  t->sig=NULL;
}

int main() {
	nodon *p =NULL;
  nodon *q =NULL;
	p=(nodon *)malloc(sizeof(nodon));
  crearlista(p);
	mostrarlista(p);
  printf("Cantidad de alumnos con mas de 10 materias aprobadas: %d",recorrer(p));
  generar(p,q);
  printf("La nueva lista es");
  mostrarlista(q);
	return 0;
}
