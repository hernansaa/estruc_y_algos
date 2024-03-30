/* 6. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar el texto
intercambiando la última letra con la anteúltima de las palabras de 2 o más letras.*/

#include <stdio.h>

int main(){

  int c, anteultima, ultima, contc=0;

  while (c != '.'){

    while (c != ' ' && c != '.'){
      ultima = c;
      putchar(c);
      if (c == ' ')
        putchar('x');
      c = getchar();
    }

    printf(" ");

    if (c == ' ')
      c = getchar();

  }


  printf("\n");

  return 0;
}
