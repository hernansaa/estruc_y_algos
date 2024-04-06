/* 11. Cargar una matriz de n filas y n columnas, calcular y mostrar el producto de los
 * elementos de la diagonal principal en forma recursiva.*/

#include <stdio.h>

void cargar(int a[10][10], int n){

  int i, j;

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      printf("Ingresar valor para posicion %d:%d = ", i, j);
      scanf("%d", &a[i][j]);
    }
  } 
}


void mostrar(int a[10][10], int n){

  int i, j;

  for (i=0; i<n; i++){
    printf("\n");
    for (j=0; j<n; j++){
      printf("%d \t", a[i][j]);
    }
  }
  printf("\n");
}


int calcProducto(int a[10][10], int i, int j, int n){

  if (j > n)
    return 1;

  return calcProducto(a, i+1, j+1, n) * a[i][j];
}


int main(){

  int mat[10][10], dim, producto;

  printf("Ingresar dimension de la matriz: ");
  scanf("%d", &dim);

  cargar(mat, dim);
  mostrar(mat, dim);

  producto= calcProducto(mat, 0, 0, dim-1);
  printf("\nEl producto  de los elementos de la diagonal principal es: %d\n", producto);

  return 0;
}




