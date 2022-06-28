#include <stdio.h>

int main(){
    int vec[6] = {2,4,6,8,10,12};
    int *p;
    p = &vec[0];
    p++;
    *(p+1)=40;
    p++;
    p[2] = 100;
    p++;
    p[0] = 200;
    printf("%d", *p);
    
}