#include <stdio.h>

void invertir(int c){

    if ( c == '\n'){
        return;
    }
    
    c = getchar();
    invertir(c);
    putchar(c);
    
    
    
}

int main(){
    int c;
    printf("Ingrese la frase ");
    c = getchar();
    invertir(c);
    putchar(c);


    return 0;
}