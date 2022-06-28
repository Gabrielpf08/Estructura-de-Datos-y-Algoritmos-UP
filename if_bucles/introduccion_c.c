/*INTRODUCCION*/

/*Ingresar numeros hasta que dicho numero sea cero. Calcular y mostrar:
a) La cantidad de numeros pares multiplos de 5.
b) La cantidad de numeros primos.
c) El promedio de aquellos numeros impares multiplos de 3.
*/

#include <stdio.h>

int main()
{
    int num, contador = 0, primos = 0, cont1 = 0, cont2 = 0, acum = 0, i; 
    // en python seria ----> num = int(input("Ingrese un numero: ")) 
    // pero en C es con 'printf' como en el siguiente ejemplo
    printf("ingrese un numero: "); 
    scanf("%d" , &num);  //el segundo parametro es el nombre de la variable, a la que se le coloca '&' para reservar espacio de memoria en la variable
   // el '"%d"' se utiliza cuando (en lenguaje python) un dato es "int", cuando es '"%f"' es float y '"%s"' es char.
    while (num != 0)  //los parentesis en C son obligatorios. Y en lugar de ':' para poner adentro del 'while' se usan solo las llaves.
    {
        if(num % 2 == 0 && num % 5 == 0) // el '&&' vendria a ser el 'and' de Python
        {
            contador ++; // vendria a ser el 'cont += 1' del Python. Pero cuando viene a ser 'cont += 2' ahi si que no se usa el 'cont ++' 
        }

        if(num % 2 != 0 && num % 3 == 0)
        {
            acum = acum + num;
            cont1 ++; //aca debo usar otro contador para que no se mezcle con el anterior
        }

        for(i = 1; i < num; i++) //es el 'for i in range(0, num)' del Python. Y tambien en lugar de ',' se ponen ';' para ir separando los datos (en este caso)
        {
            if(num % i == 0) 
            {
                cont2++; 
            }
        }
        if(cont2 == 1)
        {
            primos++;
        }
        cont2 = 0;
    
        printf("ingrese un numero: "); 
        scanf("%d" , &num);
    }

    printf("La cantidad de numeros pares multiplos de 5 es %d: ", contador); //el '%d' es porque a C hay que decirle si o si que tipo de datos va a mostrar.

    if (contador != 0)
    {
        printf("El promedio de los impares multiplo de 3 es %d:", acum/cont1);
    }

    else
    {
        printf("No se ingresaron impares multiplos de 3");
    }
    printf("la cantidad de primos es %d: ", primos);

} 
