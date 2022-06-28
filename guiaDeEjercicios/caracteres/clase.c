#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recorrerFrase(){
    int c;
    c = getchar();
    while(c != '.' ){
        putchar(c);
        c = getchar();
    }
}

void contarLetrasA(){
    int c, cont = 0;
    c = getchar();
    while(c != '.' ){
        putchar(c);
        if(c == 'a'){
            cont++;
        }
        c = getchar();
    }
    printf("\nHay %d letras A",cont);
}


void eliminarEspaciosEnBlanco(){
    int c;
    while(c != '.' && c == ' '){
        c = getchar();
    }
    while(c != '.'){
        while(c != '.' && c != ' '){
            putchar(c);
            getchar();
        }
    }
}


int main(){
    int c;
    recorrerFrase();
    contarLetrasA();
}