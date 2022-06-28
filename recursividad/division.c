#include <stdio.h> //division entera

int dividir(int a, int b){
    if (a-b ==0)
    return 0;
    else
    return dividir(a-b,b) + 1 ;
}

int main(){
    int numero_a, numero_b;
    printf("Ingrese un numero: ");
    scanf("%d",&numero_a);
    printf("Ingrese otro numero: ");
    scanf("%d",&numero_b);
    printf("\nEl resultado de la division es: %d", dividir(numero_a,numero_b));
}