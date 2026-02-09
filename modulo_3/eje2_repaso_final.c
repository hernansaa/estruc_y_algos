/* 2. Cargar una matriz de n*n de números enteros y mostrar:
a) la matriz transpuesta
b) El promedio de los elementos de las dos diagonales (principal y secundaria)
c) Multiplicar la matriz por su transpuesta.
d) Determinar cuántos números primos hay en la matriz */

#include <stdio.h>

void cargar(int m[][10], int dim);
void mostrar(int m[][10], int dim);
void mostrarTraspuesta(int m[][10], int dim);
int sumaDiagPrinc(int m[][10], int dim);


int main () {
    
    int matriz[10][10], dim=0;
    
    printf("Ingresar numero de col/filas (n*n) de la matriz: ");
    scanf("%d", &dim);
    
    cargar(matriz, dim);
    
    printf("\nMostrar Matriz: \n");
    mostrar(matriz, dim);
    
    printf("\n\nMostrar Matriz Traspuesta: \n");
    mostrarTraspuesta(matriz, dim);
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


