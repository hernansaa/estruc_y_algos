
/* a) Ingresar un numero entero positivo. Se pide mostrar el numero su espejo. Por ej: 1236 -> 6321.
 * Se pide resolver realizando una función recursiva. En caso de tener que realizar otras funciones
 * también deben ser recursivas. */


#include <stdio.h>

int invertir (int a, int espejo){

  int digito;

  if (a == 0)
    return espejo;

  //digito =  a % 10;
  //espejo = (espejo * 10) + digito;
  printf("digito: %d, espejo: %d\n", digito, espejo); //usarlo para debuggear

  return invertir(a / 10, (espejo * 10) + a % 10);
}


int main(){

  int num, numEspejo;

  printf("Ingresar numero: ");
  scanf("%d", &num);

  numEspejo = invertir(num, 0);

  printf("\nEl numero espejo es: %d\n", numEspejo);

  return 0;
}
