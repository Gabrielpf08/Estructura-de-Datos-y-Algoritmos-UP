#include <stdio.h>
#include <stdlib.h>

typedef struct alumno{
        int num;
        char nombre[20];
        char apellido[20]; 
        int materiasAprobadas;
        struct alumno *sig;
        }nodon;

void crearlista(nodon *h){
  int contMat = 0;
  
	printf("Ingrese un numero de legajo: ");
	scanf("%d",&h->num);
	
	while(h->num!=0){

	printf("ingrese nombre: ");
	scanf("%s", h->nombre);
		
    printf("Ingrese apellido: ");
    scanf("%s", h-> apellido);

    printf("Ingrese cantidad de materias aprobadas: ");
    scanf("%d", &h-> materiasAprobadas);
    if(h -> materiasAprobadas > 10)
    contMat++;

    h->sig=(nodon *)malloc(sizeof(nodon));
	h=h->sig;

	printf("Ingrese un numero de legajo: ");
	scanf("%d",&h->num);
	}
  
  printf("\n");
  printf("Hay %d alumnos con mas de 10 materias aprobadas \n",contMat);

	h->sig=NULL;
	
	}
void mostrarlista(nodon *h){
	while(h->sig!=NULL){
    printf("\n");
	printf("Numero de legajo: %d \n",h->num);
	printf("Nombre: %s \n",h->nombre);
    printf("Apellido: %s \n", h->apellido);
    printf("Cantidad de materias aprobadas: %d \n", h-> materiasAprobadas);
    printf("\n");
		h=h->sig;
		
	}
	
}
void generar(nodon *h, nodon *a){
	while(h->sig!=NULL){
		if(h->materiasAprobadas < 3){
			a->num=h->num;
			a->materiasAprobadas=h->materiasAprobadas;
			a->sig=(nodon *)malloc(sizeof(nodon));
			a=a->sig;
		}
		h=h->sig;
	}
	a->sig=NULL;
}

		int main() {
	nodon *p=NULL;
	nodon *q=NULL;
	p=(nodon *)malloc(sizeof(nodon));
	q=(nodon *)malloc(sizeof(nodon));
    crearlista(p);
	mostrarlista(p);
	generar(p,q);
	printf("Alumnos con menos de 3 materias aprobadas \n");
	mostrarlista(q);
	
	return 0;
}
