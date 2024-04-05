/*Diseñar un algoritmo recursivo que permita hacer la división por restas sucesivas.*/

#include <stdio.h>

int main(){

  float num, num1, res;

  float division(float a, float b){

    if (a == 0)
      return 0;

    //printf("Res: %f\n", division(a, b));

    return division(a-b, b)+1;

  }


  printf("Ingresar dividendo: ");
  scanf("%f", &num);

  printf("Ingresar divisor: ");
  scanf("%f", &num1);

  res = division(num, num1);

  printf("El resultado de la division es: %f\n", res);


}
