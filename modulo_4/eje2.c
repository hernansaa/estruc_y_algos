/*2. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar el texto con un
blanco y eliminando las palabras de 1 letra.*/

#include <stdio.h>


int main(){

  int c, contc=0, contp=0;
  
  printf("Ingrese un texto terminado en un punto.\n");
  c = getchar();

  while (c != '.'){

    while (c != ' ' && c != '.'){
      putchar(c);
      c = getchar();
      contc++;
    }
    contp++;

    if (contc > 0) //cambiar
      printf("(%d:%d) ", contc, contp);

    contc = 0;

    if (c == ' '){
      c = getchar();
    }

  }

  printf("\n");

  return 0;
}



