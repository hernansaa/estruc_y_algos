/*Diseñar un algoritmo recursivo que permita invertir un número. Por ejemplo,Entrada: 123 Salida: 321 */

#include <stdio.h>

int main(){

  int num, num1, res;

  int invert(int a){

    if (a == 0)
      return 0;


    return invert(a);

  }

  printf("Ingresar dividendo: ");
  scanf("%d", &num);

  res = invert(num);

  printf("El resultado de la division es: %d\n", res);

  return 0;
}
