/* 12. Ingresar dos números y calcular el m.c.d. en los mismos en forma recursiva. */

#include <stdio.h>

int calcMcd(a, b){

  if (a == 0)
    return 0;

  return calcMcd(a, b);
}


int main(){
  
  int num, num1, mcd;

  printf("Ingresar numero 1: \n");
  scanf("%d", &num);
  printf("Ingresar numero 2: \n");
  scanf("%d", &num);

  mcd = calcMcd(num, num1);
  printf("El Maximo Comun Denominador es: %d\n", mcd);

}
