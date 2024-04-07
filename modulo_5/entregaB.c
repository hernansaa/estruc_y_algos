/* b) Carga un arreglo de 20 elementos enteros y hacer dos funciones una que muestre
 * el arreglo en el orden en que se cargaron los elementos, y otra que los muestre 
 * en sentido inverso. Realizar 3 funciones recursivas parea resolver el problema 
 * (carga, muestra en orden, muestra en orden inverso) */

#include <stdio.h>


int cargar(int vec[20], int i, int len){

  int num;

  printf("Ingresar numero posicion %d: ", i);
  scanf("%d", &num);

  vec[i] = num;

  if (i >= len)
    return 0;


  return cargar(vec, i+1, len);
}


int mostrar(int vec[20], int i, int len){

  if (i >= len)
    return 0;

  printf("Posicion %d: %d\n", i, vec[i]);

  return mostrar(vec, i+1, len);
}

int mostrarInvert(int vec[20], int i, int len){

  if (i < 0)
    return 0;

  printf("Posicion %d: %d\n", i, vec[i]);

  return mostrarInvert(vec, i-1, len);
}


int main(){

  int vector[20], start, finish;

  cargar(vector, start=0, finish=4);
  printf("\nMostrar: \n");
  mostrar(vector, start=0, finish=5);
  printf("\nMostrar Invertido:\n");
  mostrarInvert(vector, start=4, finish=0);

  return 0;
}
