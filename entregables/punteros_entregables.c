#include <stdio.h>

void cargar (float *array){
    int i;
    for (i=0; i < 15; i++){
        printf ("Introduce un valor para la posicion %i ", i+1);
        scanf("%f", (array+i));
    }
}
void leer(float *array){
    int i;
    for (i=0; i < 15; i++){
        printf("\n %.2f %p ",*(array+i), (&array+i)); //%p y luego &variable muestra la posicion en memoria
    }

}


int main(){
    float array[15];
    cargar(array);
    leer(array);
}