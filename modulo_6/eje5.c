/* 5. Escribir un programa efectúe las siguientes operaciones:
a) Declarar un arreglo de quince posiciones de tipo float. Cargar sus elementos y
mostrarlo.
b) Declarar un puntero a float.
c) Asignar al puntero la dirección del arreglo.
d) Recorrer con el puntero el arreglo, mostrando la dirección y el contenido de cada
posición. */

#include <stdio.h>
#include <stdlib.h>

int main(){

  float array[15] = {1,13,3,4,5,6,7,8,9,10,11,12,13,14,15};
  float *punt=NULL;
  int i;

  punt = &array[0];

  for (i=0; i<15; i++)
    printf("Contenido: %f, Direccion: %p \n", *(punt + i), &punt[i]);

  return 0;
}
