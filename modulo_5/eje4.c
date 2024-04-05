/*Diseñar un algoritmo recursivo que permita multiplicar los elementos de un vector.*/

#include <stdio.h>
#include <stdlib.h>

int multiplicar(int a[], int n){

  if (n < 0)
    return 1;

  return multiplicar(a, n-1) * a[n];

}

int main(){

int vec[]={2,2,3,5,1}, dim=4, res;

  res = multiplicar(vec, dim);

  printf("Los elementos multiplicados da: %d\n", res);

}
