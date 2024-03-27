/*Leer un texto carácter a carácter, terminado en PUNTO. Mostrar cuántas
palabras tienen más de 3 letras*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  int c, cont=0, contp=0;

  printf("Ingrese una texto terminado en un punto.\n");
  c = getchar();


  while (c != '.'){
    
    while (c != ' ' && c != '.'){
      cont++;
      putchar(c);
      c = getchar();
    }
    
    if (cont > 3){
      contp++;
    }
    
    printf(" (%d - ", cont);
    printf("%d)\n", contp);

    if (c == ' '){
      // Leer el siguiente caracter si es un espacio.
      c = getchar();
    }
    
    cont = 0;
  }

  printf("La cantidad de palabras con mas de 3 letras es: %d\n", contp);

  return 0;
}
