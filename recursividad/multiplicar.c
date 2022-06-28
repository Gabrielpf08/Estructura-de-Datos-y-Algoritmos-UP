#include <stdio.h>

int multiplicar(int a, int b){
    if (a == 0 || b == 0)
    return 0;
    else 
    return multiplicar(a,b-1) + a;
}

int main(){
    int numero_a, numero_b;
    printf("Ingrese un numero: ");
    scanf("%d",&numero_a);
    printf("Ingrese otro numero: ");
    scanf("%d",&numero_b);
    printf("\nEl resultado de la multiplicacion es: %d", multiplicar(numero_a,numero_b));

}