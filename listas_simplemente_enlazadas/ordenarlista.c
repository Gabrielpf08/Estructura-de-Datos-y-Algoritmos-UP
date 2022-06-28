#include<stdio.h>
#include <stdlib.h>

typedef struct lista{
    int dato;
    struct lista *sig;
}nodo;


int insertarOrdenado(p, num);
void mostrarlista(p);


int main(){
    nodo *p=NULL;
    p=(nodo*)malloc(sizeof(nodo));
    int num;
    printf("Ingresar numeros: "); scanf("%d", &num);
    while(num!=0){
    p = insertarOrdenado(p, num);
    
    }
}

int insertarOrdenado(nodo *inicio, int elemento){
    nodo *nuevo=NULL;
    nuevo=(nodo*)malloc(sizeof(nodo));
    nodo *aux=NULL;
    aux=(nodo*)malloc(sizeof(nodo));
    nuevo->dato=elemento;
    nuevo->sig=NULL;

    if (inicio == NULL || elemento < inicio->dato){
        nuevo->sig=inicio;
        inicio=nuevo;
    }

    else{
    
    aux = inicio;
    while(aux->sig != NULL && aux->sig->dato < elemento)
    aux=aux->sig;

    if (aux->sig!=NULL){
    nuevo->sig=aux->sig;
    }
    aux->sig=nuevo;  
    }
    return inicio;
}

void mostrarlista(nodo *h){
	while(h->sig!=NULL){
		printf("%d \n",h->dato);
		h=h->sig;
		
	}
}