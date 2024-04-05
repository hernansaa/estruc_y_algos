/*Diseñar un algoritmo recursivo que permita sumar los dígitos de un número. 
 * Porejemplo, Entrada: 123 Resultado: 6*/

#include <stdio.h>



int sumarDigitos(int a){

  if (a == 0)
    return 0;

  return sumarDigitos(a / 10) + a % 10;

}



int main(){

  int num, res;

  printf("Ingresar numero: ");
  scanf("%d", &num);

  res = sumarDigitos(num);

  printf("El resultado de los digitos sumados es: %d\n", res);

}
