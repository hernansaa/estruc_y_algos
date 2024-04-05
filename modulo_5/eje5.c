/*5. Diseñar un algoritmo recursivo que permita sumar los elementos de una matriz.*/

#include <stdio.h>


void cargar(int a[][10], int n){

  int i, j;

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      printf("Ingresar el valor %d:%d: ", i, j);
      scanf("%d", &a[i][j]);
    }
  }
}


void mostrar(int a[][10], int n){

  int i, j;

  for (i=0; i<n; i++){
    printf("\n");
    for (j=0; j<n; j++){
      printf("%d ", a[i][j]);
    }
  }
  printf("\n");
}


int sumar(int a[][10], int i, int j, int dim){

  if (j >= dim)
    return 0;

  printf("%d\n", a[i][j]);

  return sumar(a, i, j+1, dim)+a[i][j];
}


int main(){

  int a[10][10], dim, suma;

  printf("Ingresar el numero de filas y columnas de la matriz: ");
  scanf("%d", &dim);

  cargar(a, dim);
  mostrar(a, dim);

  suma = sumar(a, 1, 0, dim);

  printf("La suma es: %d\n", suma);

  return 0;
}
