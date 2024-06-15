#include <stdio.h>
#include <stdlib.h>


void cargar(int mat[4][4], int n){

  int i,j;

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      printf("Ingrese un numero: ");
      scanf("%d", &mat[i][j]);
    }
  }
}


void mostrar(int mat[4][4], int n){

  int i, j;

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      printf("%d", mat[j][i]);
    }
    printf("\n");
  }
}


void calcular(int mat[4][4]){

  if (mat[0][0] == 0)

  return;

}



int main(){
  
  int mat[4][4], dim;
  //FILE *p;

  printf("Ingrese dimension de la matriz: \n");
  scanf("%d", &dim);
  cargar(mat, dim);
  mostrar(mat, dim);
  //calcular(mat);

  return 0;
}
