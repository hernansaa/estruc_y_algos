#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  int i;
  char nom [30], mejor [30];
  float prom, auxprom;

  auxprom = 0.0;
  
  for ( i = 1; i <= 10; i ++){

    printf ("Ingrese el nombre del alumno:");
    scanf ( " %[^\n]", nom);
    printf ("Su promedio es:");
    scanf ("%f", & prom);
      if (prom > auxprom){
        auxprom = prom;
        strcpy (mejor, nom);
      }
  }
  
  printf ("El mejor alumno es %s con un promedio de %.2f", mejor, auxprom);
 
  return 0;
}
