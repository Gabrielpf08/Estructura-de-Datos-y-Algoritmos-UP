#include <stdio.h>
/*Ingresar números enteros y cargar un vector con los primero 10 números positivos o hasta que se lea un cero.
Si el vector no tiene elementos, mostrar una leyenda, caso contrario mostrarlo y realizar las siguientes operaciones;

a) Insertar el opuesto antes de aquellos números pares menores al promedio.

b) Ordenar el vector de mayor a menor y mostrarlo.

*/

int cargar (int array[], int longitud){
    int i=0,numero;
	printf("\n ingrese valor");
	scanf("%d",&numero);
    while (numero != 0 && i < longitud){
        if (numero > 0){
            array[i]=numero;
			i++;
        }
        printf("\n ingrese valor");
	    scanf("%d",&numero);
	}
	return i;
}

void mostrar (int array[],int size){
    int i;
	for (i=0;i<size;i++){
		printf("\n %d  %d",i, array[i]);
	}
	return;
}

double promedioDeArreglo(int arreglo[], int cantidadDeElementos){
    double suma = 0;
    for (int i = 0; i < cantidadDeElementos; i++){
        suma = suma + arreglo[i];
    }
    return suma / cantidadDeElementos;
}

void ordenar(int a[],int longitud){
    int i,j,aux;
	for(i=0;i<longitud;i++){
		for(j=i+1;j<longitud;j++){
            if(a[i]<a[j]){
				aux=a[i];
				a[i]=a[j];
				a[j]=aux;
			}
		}
	}
return;
}

void insertar(int a[],int longitud, int promedio){
	int i, opuesto;
	for (i=longitud; i>0;i--){
		a[i]=a[i-1];
	}
    if (a[i] % a[2] == 0 && a[i] < a[promedio])
	opuesto = a[i] * a[i * -1];
    a[2]=opuesto;
    return;
}

int main(){
    int vector[100],size, longitud;
    float  prom;
    longitud = 10;

	size=cargar(vector, longitud);
	mostrar(vector,size);

    prom = promedioDeArreglo(vector,size);
    printf("\nEl promedio es: %f", prom);

    ordenar(vector,size);
    printf("\n el arreglo ordenado");
	mostrar(vector,size+1);
    
    insertar(vector,size, prom);
	printf("\n el arreglo con insercion es");
	mostrar(vector,size+1);

}
