/* 1. Cargar una matriz de n*n de números enteros. 
  Mostrar:
  a) la sumatoria de los elementos de la 2º fila.
  b) el mayor elemento de la segunda columna.
  c) el promedio de todos los múltiplos de 5 en la matriz.
  d) la sumatoria de la diagonal principal de la matriz.
  e) el elemento mínimo de cada fila.
  f) los elementos de la diagonal secundaria.
  g) los elementos que se encuentran debajo de la diagonal principal. 
  h) si la matriz es simétrica */


#include <stdio.h>

void cargar(int a[][4], int n){
  
  int i,j;

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      printf("Ingrese el valor en la posicion %d:%d: ", i,j);
      scanf("%d", &a[i][j]);
    }
  }
}


void mostrar(int a[][4], int n){
  
  int i,j;

  for (i=0; i<n; i++){
    printf("\n"); // Espacio entre fila y fila
    for (j=0; j<n; j++){
      printf("%d\t", a[i][j]);
    }
  }
  printf("\n");

}


int suma(int a[][4], int n){
  
  int i=1, j=0, sum=0;

  for (j=0; j<n; j++){
    sum += a[i][j];
  }

  return sum;
}


int maximo(int a[][4], int n){

  int i=0, j=1, max=a[0][j];

  for (i=0; i<n; i++){
    if (a[i][j] > max){
      max = a[i][j];
    }
  }
  return max;
}


int promedio(int a[][4], int n){
  
  int i=0, j=0, acum=0, cont=0;

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      acum += a[i][j];
      cont++;
    }
  }
  return (float)acum / (float)cont;
}


int diag_princ(int a[][4], int n){
  
  int i=0, j=0, sum=0;

  for (i=0; i<n; i++){
    sum+= a[i][j];
    //printf("numero sumado: %d\n", a[i][j]);
    j++;
  }
  return sum;
}


void minimos(int a[][4], int n){

  int i=0, j=0, min=a[i][j];

  for (i=0; i<n; i++){
    
    min=a[i][0];
    
    for (j=0; j<n; j++){
      if (a[i][j] < min){
        min = a[i][j];
      }
    }
    printf("El minimo de la fila %d, es %d\n", i, min);
  }

}


void elem_diag_sec(int a[][4], int n){

  int i=0, j=0;

  for (i=0; i<n; i++){
    printf("De la fila %d, el elemento es: %d\n", i, a[i][n-1-i]);
  }
}


void elem_debajo_princ(int a[][4], int n){

  int i=1, j=0;

  for (i=1; i<n; i++){
    printf("El elemento de la fila %d, es: %d\n", i, a[i][j]);
    j++;
  }
}


void verif_simetria(int a[][4], int n){

  int i=0, j=0, cont=0;
  
  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      if (a[i][j] == a[j][i])
        cont++;
    }
  }
  //printf("CONT: %d\n", cont);
  //printf("DIM: %d\n", n*n);
  if (cont == n*n)
    printf("Esta matriz es simetrica\n");
  else
    printf("Esta matriz NO ES simetrica\n");
}


int main(){

  int matriz[4][4], dim, sum, max, sum_diag_princ;
  float prom;

  printf("Ingresar numero de filas/clumnas de la matriz: \n");
  scanf("%d", &dim);

  cargar(matriz, dim);
  mostrar(matriz, dim);
  sum = suma(matriz, dim);
  printf("\nLa suma de la fila 2 es: %d\n", sum);
  max = maximo(matriz, dim);
  printf("El maximo de la columna 2 es: %d\n", max);
  prom = promedio(matriz, dim);
  printf("El promedio de toda la matriz es: %f\n", prom);
  sum_diag_princ = diag_princ(matriz, dim);
  printf("La suma de la diagonal principal: %d\n", sum_diag_princ);
  printf("Los minimos de cada fila son:\n");
  minimos(matriz, dim);
  printf("Elementos diagonal secundaria: \n");
  elem_diag_sec(matriz,dim);
  printf("Elementos por debajo de la diagonal principal:\n");
  elem_debajo_princ(matriz, dim);
  verif_simetria(matriz, dim);
  


  return 0;
}





















