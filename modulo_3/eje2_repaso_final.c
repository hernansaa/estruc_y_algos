/* 2. Cargar una matriz de n*n de números enteros y mostrar:
a) la matriz transpuesta
b) El promedio de los elementos de las dos diagonales (principal y secundaria)
c) Multiplicar la matriz por su transpuesta.
d) Determinar cuántos números primos hay en la matriz */

#include <stdio.h>

void cargar(int m[][10], int dim);
void mostrar(int m[][10], int dim);
void mostrarTraspuesta(int m[][10], int dim);
float promDiagPrinc(int m[][10], int dim);
float promDiagSec(int m[][10], int dim);


int main () {
    
    int matriz[10][10], dim=0;
    float prom=0;
    
    printf("Ingresar numero de col/filas (n*n) de la matriz: ");
    scanf("%d", &dim);
    
    cargar(matriz, dim);
    
    printf("\nMostrar Matriz: \n");
    mostrar(matriz, dim);
    
    printf("\n\nMostrar Matriz Traspuesta: \n");
    mostrarTraspuesta(matriz, dim);
    
    printf("\n\nProm Diag Principal Matriz: \n");
    prom = promDiagPrinc(matriz, dim);
    printf("%f", prom);
    
    printf("\n\nProm Diag Secundaria Matriz: \n");
    prom = promDiagSec(matriz, dim);
    printf("%f", prom);
}


// UTILS

void cargar(int m[][10], int dim) {
    
    int i, j;
    
    for (i=0; i<dim; i++) {
        for (j=0; j<dim; j++) {
            printf("Ingresar valor %d:%d = ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void mostrar(int m[][10], int dim) {
    
    int i, j;
    
    for (i=0; i<dim; i++) {
        printf("\n");
        for (j=0; j<dim; j++) {
            printf("%d \t", m[i][j]);
        }
    }    
}

void mostrarTraspuesta(int m[][10], int dim) {
    
    int i, j;
    
    for (i=0; i<dim; i++) {
        printf("\n");
        for (j=0; j<dim; j++) {
            printf("%d \t", m[j][i]);
        }
    }    
}


float promDiagPrinc(int m[][10], int dim) {
    
    int i, sum=0;
    
    for (i=0; i<dim; i++) {
        sum += m[i][i];
    }
    
    return (float)sum / (float)dim;
}

float promDiagSec(int m[][10], int dim) {
    
    int i, j, sum=0;
    
    for (i=0; i<dim; i++) {
        j = (dim - 1) - i;
        sum += m[i][j];
    }
    
    return (float)sum / (float)dim;
}











