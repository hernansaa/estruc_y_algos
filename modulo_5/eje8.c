/* 8. Cargar un vector con n elementos enteros y calcular la suma de sus elementos en
forma recursiva. */

#include <stdio.h>

int cargar(int a[10], int n){

  int i=0, num;

  while (i < n){
    printf("Ingrear numero: ");
    scanf("%d", &num);
    a[i] = num;
    i++;
  }
}


int mostrar(int a[10], int n){

  int i;

  for (i=0; i<n; i++){
    printf("%d\n", a[i]);
  }
}


int sumar(int a[], int n){

  if (n < 0)
    return 0;

  return sumar(a, n-1) + a[n];
}


int main(){

  int vec[10], dim, suma=0;

  printf("Ingresar dimension vector: ");
  scanf("%d", &dim);

  cargar(vec, dim);
  mostrar(vec, dim);

  suma = sumar(vec, dim-1);
  printf("La suma de los elementos del vector es: %d\n", suma);

  return 0;
}
