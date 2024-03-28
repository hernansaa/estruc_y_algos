/*5. Leer un texto carácter a carácter terminado en PUNTO. Contar cuantas palabras
empiezan y terminan con la misma letra. */

#include <stdio.h>

int main(){

  int c, primera, ultima, cont=0;

  printf("Ingresar un texto terminando con un punto:\n");
  c = getchar();

  while (c != '.'){

    primera = c;

    while (c != ' ' && c != '.'){
      ultima = c;
      c = getchar();
    }

    if (primera == ultima)
      cont++;

    primera = ' ';
    ultima = ' ';

    if (c == ' ')
      c = getchar();

  }

  printf("Cantidad de palabras que empiezas y terminan con misma letra: %d\n", cont);

  return 0;
}
