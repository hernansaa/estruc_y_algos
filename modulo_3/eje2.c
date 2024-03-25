/* 2. Cargar una matriz de n*n de números enteros y mostrar:
a) la matriz transpuesta
b) El promedio de los elementos de las dos diagonales (principal y secundaria)
c) Multiplicar la matriz por su transpuesta.
d) Determinar cuántos números primos hay en la matriz */

#include <stdio.h>

void cargar(int a[][100], int n){

  int i,j;

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      printf("Ingresar el valor para %d:%d: ", i, j);
      scanf("%d", &a[i][j]);
    }
  }
}


void mostrar(int a[][100], int n){

  int i,j;

  for (i=0; i<n; i++){
    printf("\n");
    for (j=0; j<n; j++){
      printf("%d \t", a[i][j]);
    }
  }
  printf("\n");
}


void mostrar_traspuesta(int a[][100], int n){

  int i,j;

  for (i=0; i<n; i++){
    printf("\n");
    for (j=0; j<n; j++){
      printf("%d \t", a[j][i]);
    }
  }
  printf("\n");
}


float suma_diag_princ(int a[][100], int n){

  int i=0, j=0, acum=0;

  for (i=0; i<n; i++){
    acum+=a[i][j];
    j++;
  }

  return acum;
}


float suma_diag_sec(int a[][100], int n){

  int i=0, j=0, acum=0;

  for (i=0; i<n; i++){
    acum+=a[i][n-1-i];
    j++;
  }

  return acum;
}


void multiplicar_por_traspuesta(int a[][100], int n){

  int i,j;

  for (i=0; i<n; i++){
    printf("\n");
    for (j=0; j<n; j++){
      printf("%d \t", a[j][i]*a[i][j]);
    }
  }
  printf("\n");
}
:q

// VER COMO SE SACAN LOS NUMEROS PRIMOS
int numeros_primos(int a[][100], int n){

  int i=0, j=0, cont=0;

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      if (a[i][j] % a[i][j] == 0){
        cont++;
      }
    }

  }
  return cont;
}



int main(){

  int matriz[100][100], dim, cant_num_primos;
  float suma_princ, suma_sec;

  printf("Ingresar el numero de columnas/filas para la matriz: ");
  scanf("%d", &dim);

  cargar(matriz, dim);

  printf("\nMostrar la matriz cargada: \n");
  mostrar(matriz, dim);

  printf("\nLa transpuesta: \n");
  mostrar_traspuesta(matriz, dim);

  printf("\nPromedio Diagonales: \n");
  suma_princ = suma_diag_princ(matriz, dim);
  suma_sec = suma_diag_sec(matriz, dim);
  printf("-Suma diagonal principal: %f\n", suma_princ);
  printf("-Suma diagonal segundaria: %f\n", suma_sec);
  printf("-El promedio de las diagonales es %f.\n", (suma_princ+suma_sec) / (dim+dim));

  printf("\nMultiplicar la Matriz por la traspuesta:\n");
  multiplicar_por_traspuesta(matriz, dim);

  cant_num_primos = numeros_primos(matriz, dim);
  printf("\nCantidad de numeros primos en la matriz: %d\n", cant_num_primos);

  return 0;
}

