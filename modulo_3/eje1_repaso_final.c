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

void cargar(int a[][10], int dim);
void mostrar(int a[][10], int dim);
int suma(int a[][10], int dim);
int maximo(int a[][10], int dim);
float promedio(int a[][10], int dim);


int main() {
    
    int matriz[10][10], dim=4, sum=0, max=0;
    
    cargar(matriz, dim);
    mostrar(matriz, dim);
    
    sum = suma(matriz, dim);
    printf("\nSuma: %d", sum);
    
    max = maximo(matriz, dim);
    printf("\nMax: %d", max);
    
    return 0;
}


void cargar(int a[][10], int dim) {
    
    int i=0, j=0;
    
    for (i=0; i<dim; i++) {
        for (j=0; j<dim; j++){
            printf("Ingresar valor %d:%d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
}

void mostrar(int a[][10], int dim) {
    
    int i=0, j=0;
    
    for (i=0; i<dim; i++) {
        printf("\n");
        for (j=0; j<dim; j++){
            printf("%d\t", a[i][j]);
        }
    }
    printf("\n");
}

int suma(int a[][10], int dim) {
    
    int i=1, j=0, sum=0;
    
    for (j=0; j<dim; j++) {
        sum += a[i][j];
    }
    
    return sum;
}

int maximo(int a[][10], int dim) {
    
    int i=0, j=1, max=0;
    
    for (i=0; i<dim; i++) {
        if (a[i][j] > max) {
            max = a[i][j];
        }
    }
    return max;
}
