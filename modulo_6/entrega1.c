/* 1) Escribir un programa en C que efectúe las siguientes operaciones:

1. Declarar un arreglo de quince posiciones de tipo float.
2. En una función cargar sus elementos mediante el uso de un puntero 
(no utilizar subíndices)
3. En otra función que reciba el arreglo, declarar un puntero a float y asignar al 
puntero la dirección del arreglo pasado por parámetro. Recorrer con el puntero 
el arreglo y utilizando el mismo mostrar la dirección y el contenido de cada posición.
(no usar subíndices)*/

#include <stdio.h>
#include <stdlib.h>

void cargar(float *p){

  int i;

  for (i=0; i<15; i++){
    printf("Ingresar valor: ");
    scanf("%f", &*(p+i));
  }
}


void mostrar(float a[15]){
  
  int i;
  float *p; //Entiendo que el enunciado pide que se declare el puntero dentro de la funcion.

  p = &a[0];

  for (i=0; i<15; i++){
    printf("Valor: %f, Direccion: %p\n", *(p++), &*p);
  }
}


int main(){

  float arreglo[15], *punt;

  punt = &arreglo[0];

  cargar(punt);
  mostrar(arreglo);
  
  return 0;
}
