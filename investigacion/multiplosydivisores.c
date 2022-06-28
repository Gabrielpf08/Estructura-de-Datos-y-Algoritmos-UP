#include <stdio.h>
#include <stdlib.h>

int main(){

    int num, cont = 0, valor, contdivisores = 0;
    printf("Ingrese valor para verificar multiplos y divisores: ");
    scanf("%d", &valor);
    printf("Ingrese un numero: ");
    scanf("%d", &num);

    while(num!=0){
        if(num % valor == 0){
            cont += 1;
        }

        if (valor % num == 0){
            contdivisores += 1;
        }
        printf("Ingrese un numero: ");
        scanf("%d",&num);
    }
    printf("El numero %d tiene %d multiplos ingresados",valor,cont);
    printf("\nEl numero %d tiene %d divisores ingresados",valor,contdivisores);

}