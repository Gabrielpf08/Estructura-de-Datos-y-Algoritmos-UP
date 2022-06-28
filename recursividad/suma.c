#include <stdio.h>

int sumarDesdeUnoHastaN(int n){
    if (n==1)
    return 1;
    else 
    return n + sumarDesdeUnoHastaN(n-1);
}

int main(){
    int numero;
    printf("Ingrese un numero: "); scanf("%d",&numero);
    printf("\n El resultado de la suma sucesiva de numeros de 1 hasta el numero ingresado es: %d",sumarDesdeUnoHastaN(numero) );
}
    