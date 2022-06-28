#include <stdio.h>

int main(){
    int A[10]={12,15,17,21,34,45};

int *B;

B=A;

*B=A[4]; 

printf("%d A[4] representa: ", A[4]); //34
printf("\n%d El valor que representa *(&B[3])", *(&B[3])); //21
printf("\n%d El valor que representa *(B+2)", *(B+2)); //17
printf("\n%d El valor que representa A[0]", A[0]); //34
printf("\n%d El valor que representa *(B+0)", *(B+0)); //34

}