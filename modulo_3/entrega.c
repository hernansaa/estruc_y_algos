/* Recuerde validar los datos en caso de ser necesario y de modularizar.
Definir una matriz de 100x100. Ingresar por teclado la dimensión de la matriz a tratar.
Se pide cargar la matriz de la dimensión ingresada. Mostrar los datos ingresados.
Si la suma de los elementos de la diagonal principal es menor al máximo de la matriz, 
se pide generar un arreglo con el promedio de cada columna de la matriz.
En caso contrario mostrar la traspuesta de la matriz cargada.*/


#include <stdio.h>


void cargar(int a[][100], int n){
  int i=0, j=0;
  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      printf("Ingresar el valor para %d:%d = ", i, j);
      scanf("%d", &a[i][j]);
    }
  }
}


void mostrar(int a[][100], int n){
  int i=0, j=0;
  for (i=0; i<n; i++){
    printf("\n");
    for (j=0; j<n; j++){
      printf("%d\t", a[i][j]);
    }
  }
  printf("\n");
}


int suma_diag_princ(int a[][100], int n){
  int i=0, j=0, acum=0;
  for (i=0; i<n; i++){
    acum+=a[i][j];
    j++;
  }
  return acum;
}


void traspuesta(int a[][100], int n){
  int i=0, j=0;
  for (i=0; i<n; i++){
    printf("\n");
    for (j=0; j<n; j++){
      printf("%d\t", a[j][i]);
    }
  }
  printf("\n");
}


int max(int a[][100], int n){
  int i=0 , j=0, max=a[i][j];
  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      if (a[i][j] > max) {
        max = a[i][j];
      }
    }
  }
  return max;
}


void generar(int a[][100], int n, float arreglo[100]){
  int i=0, j=0, k=0, acum=0, prom=0;
  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      acum += a[j][i];
      prom = (float)acum / (float)n;
    }
  arreglo[i] = (float)prom;
  acum = 0;
  prom = 0;
  }
}


void mostrar_arreglo(float arreglo[100], int n){
  int i;
  for (i=0; i<n; i++){
    printf("-Promedio columna %d: %f\n", i, arreglo[i]);
  }
}


int main(){

  int matriz[100][100], dim;
  float prom_colums[100];

  do { 
    printf("Ingresar la dimension de la matriz: ");
    scanf("%d", &dim);
  } while (dim > 100 || dim < 0);

  cargar(matriz, dim);
  mostrar(matriz, dim);

  printf("\nSuma diag: %d\n", suma_diag_princ(matriz, dim));
  printf("El max es: %d\n", max(matriz, dim));

  if (suma_diag_princ(matriz, dim) < max(matriz, dim)){
    printf("\nLa suma de la diagonal principal es menor al maximo: \n");
    generar(matriz, dim, prom_colums);
    mostrar_arreglo(prom_colums, dim);
  }
  else{
    printf("\nLa suma de la diagonal principal es mayor al maximo: \n");
    traspuesta(matriz, dim);
  }

  return 0;
}
