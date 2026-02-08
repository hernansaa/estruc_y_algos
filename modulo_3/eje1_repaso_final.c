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

int main() {
    
    int matriz[10][10], dim=4;
    
    cargar(matriz, dim);
    mostrar(matriz, dim);
    
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
