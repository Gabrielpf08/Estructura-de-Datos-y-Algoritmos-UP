#include <stdio.h>
#include <stdlib.h>

typedef struct numeros{
        int num;
        float sueldo; 
        struct numeros *sig;
        }nodon;


void crearlista(nodon *h){
	printf("ingrese valor numerico");
	scanf("%d",&h->num);
	if (h->num==0)
		h->sig=NULL;
	else{
		printf("ingrese sueldo");
		scanf("%f",&h->sueldo);
        h->sig=(nodon*)malloc(sizeof(nodon));
		crearlista(h->sig);
		
	}
	}


void mostrarlista(nodon *h){
	if (h->sig!=NULL){
		printf("%d \n",h->num);
		printf("%f \n",h->sueldo);
		mostrarlista(h->sig);
		
	}
	
}


int main() {
	nodon *p=NULL;
	p=(nodon *)malloc(sizeof(nodon));
    crearlista(p);
	mostrarlista(p);
	return 0;
}
