/*4. Leer un texto carácter a carácter, terminado en PUNTO y repetirlo reemplazando
los grupos ‘vl’ por ‘bl’.*/

#include <stdio.h>

int main(){

  int c, aux;

  printf("Escribir un texto seguido de un punto:\n");
  c = getchar();
  
  while (c != '.'){

    while (c != ' ' && c != '.'){
      if (c == 'v'){
        printf("b");
        c=getchar();
        if (c == 'l')
           printf("l");
      }
      else 
        putchar(c);
      
      c = getchar();
    }

    printf(" ");

    if (c == ' ')
      c = getchar();
  }

  printf("\n");

  return 0;
}

