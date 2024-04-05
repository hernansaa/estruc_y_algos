/*6. Diseñar un algoritmo recursivo que muestre el número menor de un vector.*/

#include <stdio.h>


void cargar(int a[10], int n){

  int i=0, num, cont=0;

  while (i < n){
    printf("Ingresar numero: ");
    scanf("%d", &num);
    a[i] = num;
    i++;
  }
}


void mostrar(int a[10], int n){

  int i;

  for (i=0; i<n; i++){
    printf("%d\n", a[i]);
  }
}


int menor(int a[10], int m, int i, int n){

  if (i >= n)
    return m;

  if (a[i] < m)
    m = a[i];

  return menor(a, m, i+1, n);
}


int main(){

  int vec[10], dim, primer=vec[0], minimo;

  printf("Especifique longitud vector (max 10): ");
  scanf("%d", &dim);

  cargar(vec, dim);
  mostrar(vec, dim);
  minimo = menor(vec, primer, 0, dim);
  printf("El minimo es: %d\n", minimo);


  return 0;
}
