/* 10. Cargar una matriz de n filas y n columnas, calcular y mostrar el elemento máximo
 * de cada fila en forma recursiva.*/

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


int calcMax(int a[10][10], int max, int i, int j, int n){

  if (j > n)
    return max;

  if (a[i][j] > max){
    max = a[i][j];
  }

  return calcMax(a, max, i, j+1, n);

}


int main(){

  int mat[10][10], dim, primer=mat[0][0], maximo;

  printf("Ingresar dimension de la matriz: ");
  scanf("%d", &dim);

  cargar(mat, dim);
  mostrar(mat, dim);

  maximo = calcMax(mat, primer, 0, 0, dim);
  printf("\nEl maximo es: %d\n", maximo);

  return 0;
}

