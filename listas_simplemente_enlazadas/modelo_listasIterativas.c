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
	while(h->num!=0){
		printf("ingrese sueldo");
		scanf("%f",&h->sueldo);
		h->sig=(nodon *)malloc(sizeof(nodon));
		h=h->sig;
		printf("ingrese valor numerico");
	    scanf("%d",&h->num);
	}
	h->sig=NULL;
	
	}
void mostrarlista(nodon *h){
	while(h->sig!=NULL){
		printf("%d \n",h->num);
		printf("%f \n",h->sueldo);
		h=h->sig;
		
	}
	
}

int main() {
	nodon *p=NULL;
	p=(nodon *)malloc(sizeof(nodon));
    crearlista(p);
	mostrarlista(p);
	return 0;
}
