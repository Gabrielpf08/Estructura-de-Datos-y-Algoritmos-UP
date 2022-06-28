// Ingresar las edades de un curso y mostrar las mayores al promedio 

#include <stdio.h> 

void cargar (int arr[])
{
    int i; 
    for (i = 0; i < 10; i ++)
    {
        printf("\nIngrese un valor: ");
        scanf("%d", &arr[i]); // el arreglo toma el valor de "i"
    }
}

void mostrar(int vec[])
{
    int i;
    for (i = 0; i < 10; i ++)
    {
        printf("\nEl valor %d pertenece a la posicion %d", vec[i], i); // vec[i] es el la posicion en el arreglo que ocupa "i", 
                                                                       // e "i" es el numero en sí
    }
}

float promedioEdades(int vec[]) // es float porque me va a devolver numeros con coma ya que quiero sacar un promedio
{
    int suma = 0, cont; // aca se pone numero sin coma porque solo estoy sumando, y prefiero sumar numeros sin coma
    // se recomienda que las variables ("suma" en este caso) se inicializen en 0 para que el C no le asigne una por sí mismo que puede quedar como un valor fijo sin querer

    for (cont = 0; cont < 10; cont ++) 
    {
        suma += cont; 
    }

    return suma/10; // con esto saco el promedio de una y no lo tengo que hacer en otra funcion
}

void mostrarMayores(int vec[], float promedio)
{
    int i;
    for (i = 0; i < 10; i ++)
    {
        if (vec[i] > promedio)
        {
            printf("\nEl valor %d pertenece a la posicion %d", vec[i], i);
        }
    }
}

int main()
{
    int vec[10];
    float promedio; 
    cargar(vec);
    mostrar(vec); //lo comento solo para que no se muestren tantos numeros
    promedio = promedioEdades(vec);
    printf("%f", promedio);
    mostrarMayores(vec, promedio);

    return 0;
}