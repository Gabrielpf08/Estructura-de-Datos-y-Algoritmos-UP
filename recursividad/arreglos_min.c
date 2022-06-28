int minvec (int vec[10],int dim,int aux){
    
    if (dim < 0){
        return aux;
    }
    if(vec[dim]<aux) //si cambio el signo a mayor me devuelve el mayor
		aux=vec[dim];
	return minvec(vec,dim-1,aux);
}


int main()
{
    int vec[10]={-9,5,-20,6,14},dim=4, min,aux=vec[0]; //inicializo el aux en la posicion cero.
    min=minvec(vec,dim,aux);
    printf("El numero menor del vector es: %d",min);
    return 0;
}
