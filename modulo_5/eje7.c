/* 7. Diseñar un algoritmo recursivo que nos permita obtener el determinante de una
matriz cuadrada de dimensión n.*/

#include <stdio.h>


void cargar(int a[10][10], int n){

  int i, j;

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      printf("Ingresar valor en posicion %d:%d = ", i, j);
      scanf("%d", &a[i][j]);
    }
  }
}


void mostrar(int a[10][10], int n){

  int i, j;

  for (i=0; i<n; i++){
    printf("\n");
    for (j=0; j<n; j++){
      printf("%d ", a[i][j]);
    }
  }
  printf("\n");
}


int diagPrincipal(int a[10][10], int i, int j, int n){

  if (j >= n)
    return 1;

  printf("%d\n", a[i][j]);

  return diagPrincipal(a, i+1, j+1, n) * a[i][j];

}


int diagSecundaria(int a[10][10], int i, int j, int n){

  if (i >= n)
    return 1;

  printf("%d\n", a[i][j]);


  return diagSecundaria(a, i+1, j-1, n) * a[i][j];

}


int main(){

  int mat[10][10], dim, multDiagPrin, multDiagSec;

  printf("Ingresar la dimension de la matriz: ");
  scanf("%d", &dim);

  cargar(mat, dim);
  mostrar(mat, dim);

  printf("\nDiagonal Principal: \n");
  multDiagPrin = diagPrincipal(mat, 0, 0, dim);
  printf("%d\n", multDiagPrin);
  printf("\nDiagonal Secundaria: \n");
  multDiagSec = diagSecundaria(mat, 0, dim-1, dim);
  printf("%d\n", multDiagSec);

  printf("El determinante de la matriz cuadrada es: %d\n", multDiagPrin - multDiagSec);

  return 0;
}









