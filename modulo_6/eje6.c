/* 6. Escribir un programa efectúe las siguientes operaciones:
a) Declarar una matriz de 3x4 de tipo int. Cargar sus elementos y mostrarla.
b) Declarar un puntero a entero.
c) Asignar al puntero la dirección de la matriz.
d) Recorrer con el puntero la matriz, mostrando la dirección y el contenido de cada
posición. */


#include <stdio.h>
#include <stdlib.h>

void cargar(int matriz[3][4]){
    int i,j;
    
    for (i=0; i<3; i++){
        for (j=0; j<4; j++){
            printf("Ingresar numero en la posicion %d:%d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrar(int matriz[3][4]){
    
    int i, j;
    
    for (i=0; i<3; i++){
        printf("\n");
        for (j=0; j<4; j++){
            printf("%d \t", matriz[i][j]);
        }
    }
    printf("\n");
}


int main() {
    
    int matriz[3][4];
    int *punt;
    int i,j,k;

    cargar(matriz);
    mostrar(matriz);
    
    punt = &matriz[0][0];
    
    for (i=0; i<3; i++)
      for (j=0; j<4; j++){
        printf("Contenido: %d, Direccion: %p\n", *punt, &punt[k]);
        punt++;
        k++;
      }

    return 0;
}

