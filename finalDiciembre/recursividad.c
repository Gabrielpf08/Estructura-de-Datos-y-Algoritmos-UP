/* Dado un numero N la sumatoria en forma recursiva de todos los numeros hasta N en forma recursiva*/

#include <stdio.h>
#include <stdlib.h>

int sumarde1hastaN(int n)
{
	if(n==1){ //situacion de corte 
		return 1;
	}else
	{
		return n + sumarde1hastaN(n - 1);	
	}
}

int main(){
	int n = 0;
	printf("Ingrese un Numero");
	scanf("%d",&n);
	printf("La suma sucesiva es: %d", sumarde1hastaN(n));
}