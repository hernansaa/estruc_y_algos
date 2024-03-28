/* 3. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar cuántas palabras
tienen más de 2 letras y terminan con “s”.*/

#include <stdio.h>

int main(){

  int c, contc=0, contp=0, aux;

  printf("Ingresar un texto terminado en un punto:\n");
  c = getchar();

  while (c != '.'){

    while (c != ' ' && c != '.'){
      putchar(c);
      contc++;
      aux = c;
      c = getchar();
    }

    printf("(%d)(%d) ", contc, aux); // Es para debuguear.

    if (contc > 2 && aux == 's')
      contp++;

    contc = 0;

    if (c == ' ')
      c = getchar();
  }

  printf("\n");
  printf("-La cantidad de palabras terminadas en 's' con mas de 2 letras es: %d\n", contp);

  return 0;
}
