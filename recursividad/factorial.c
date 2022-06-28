#include <stdio.h>

int factorial (int n)
{
    if (n == 0)
    return 1;
    else
    return factorial (n-1) * n;
}

int main(){
    int numero;
    printf("Ingrese el numero del que desea el factorial: ");
    scanf("%d", &numero);
    printf("El factorial es: %d\n", factorial(numero));
}