/*7. Ingresar un texto carácter a carácter y determinar e informar cuantas palabras
capicúas hay de 2 o 3 letras.*/

#include <stdio.h>

int main(){

  int c, primera, segunda, tercera, contc=0;

  printf("Escribir un texto hasta escribir un punto:\n");
  c = getchar();

  while (c != '.'){

    primera = c

    while (c != ' ' && c != '.'){

      tercera = c;
      c = getchar();



    }

  }

  return 0;
}



