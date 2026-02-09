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
int sumaDiagPrinc(int a[][10], int dim);
void minimos(int a[][10], int dim);
void mostarDiagSec(int a[][10], int dim);
void mostrarDebajoDiagPrinc(int a[][10], int dim);


int main() {
    
    int matriz[10][10], dim=4, sum=0, max=0, sum_diag_princ=0; 
    float prom=0;
    
    cargar(matriz, dim);
    mostrar(matriz, dim);
    
    sum = suma(matriz, dim);
    printf("\nSuma: %d", sum);
    
    max = maximo(matriz, dim);
    printf("\nMax: %d", max);
    
    prom = promedio(matriz, dim);
    printf("\nPromedio multiplos de 5: %f", prom);
    
    sum_diag_princ = sumaDiagPrinc(matriz, dim);
    printf("\nSuma Diagonal Principal: %d", sum_diag_princ);
    
    minimos(matriz, dim);
    
    mostarDiagSec(matriz, dim);
    
    mostrarDebajoDiagPrinc(matriz, dim);
    
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

float promedio(int a[][10], int dim) {
    
    int i=0, j=0, cont=0, acum=0;
    
    for (i=0; i<dim; i++) {
        for (j=0; j<dim; j++) {
            if (a[i][j] % 5 == 0) {
                acum += a[i][j];
                cont++;
            }
        }
    }
    
    return (float)acum / (float)cont;
}

int sumaDiagPrinc(int a[][10], int dim) {
    
    int i=0, j=0, sum=0;
    
    for (i=0; i<dim; i++) {
        sum += a[i][j];
        j++;
    }
    
    return sum;
}


void minimos(int a[][10], int dim) {
    
    int i=0, j=0, min;
    
    for (i=0; i<dim; i++) {
        
        min = a[i][0];
        
        for (j=0; j<dim; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
        printf("\n-El minimo de la fila %d es: %d", i, min);
    }
    
}


void mostarDiagSec(int a[][10], int dim) {
    
    int i, j;
    
    for (i=0; i<dim; i++) {
        j = (dim - 1) - i;
        printf("\n\nElemento Diag Sec %d:%d = %d", i, j, a[i][j]);
    }
}


void mostrarDebajoDiagPrinc(int a[][10], int dim) {
    
    int i;
    
    for (i=1; i<dim; i++) {
        printf("\n\nElemento Debajo Diag Princ %d:%d = %d", i, i-1, a[i][i-1]);
    }
}


