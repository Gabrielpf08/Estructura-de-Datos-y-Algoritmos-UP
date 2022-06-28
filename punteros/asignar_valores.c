#include <stdio.h>

int main(){
    int a = 10, b = 20, c = 30, *p, *q;
    p = &a;
    q = p;
    *q = 200;

    q = &b;
    p = q;
    *p = 300;
    
    p = &c;
    q = p;
    q = &c;
    *q = 500;

    printf("a %d, b %d, c %d, *p %d, *q %d",a, b, c, *p, *q);
}