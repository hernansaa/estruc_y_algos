/*Leer un texto desde el teclado carácter a carácter terminado en punto, 
se pide utilizando solo las funciones putchar() y getchar():

Leer un texto desde el teclado compuesto por palabras, donde las palabras 
pueden estar separadas por uno o mas blancos y teniendo en cuenta que puede 
haber uno o mas blancos antes de la primer palabra y después de la ultima, 
se pide:

a) Calcular la cantidad de palabras del texto que tengan al menos todas las 
vocales y que sean de longitud par.

b) Calcular el promedio de las longitudes de las palabras que empiezan con 
una 'A' y finalizan con una 'N'.

Recuerde modularizar su programa*/

#include <stdio.h>

int main(){

  int c, primerc, ultimoc, contc=0, contp=0, a=0, e=0, i=0, o=0, u=0;
  float acum=0, contpprom=0;

  printf("Escribir un texto hasta un PUNTO:\n");
  c = getchar();

  while (c != '.'){

    primerc = c;

    while (c != ' ' && c != '.'){
      putchar(c);

      // Verifica la existencia de vocal y cambia valor a 1 en respectiva variable.
      if (c == 'a')
        a = 1;
      if (c == 'e')
        e = 1;
      if (c == 'i')
        i = 1;
      if (c == 'o')
        o = 1;
      if (c == 'u')
        u = 1;
      
      ultimoc = c;
      contc++;
      c = getchar();
    }

    printf(" (longitud: %d, 1er caracter: %d, Ultimo caracter: %d)", contc, primerc, ultimoc);

    // Verifica que la palabra sea par y que esten todas las vocales.
    if (contc % 2 == 0){
      printf("\n-Verificando si estan todas las vocales en la palabra...\n");
      if (a == 1 && e == 1 && i == 1 && o == 1 && u == 1){
        contp++;
        printf("#Tiene todas las vocales.\n\n");
      }
      else 
        printf("#No tiene todas las vocales.\n\n");
    }
    else
      printf("\n#No es par, entonces no verifica esa condicion para verificar vocales.\n\n");

    // Calcula el promedio de las palabras comenzadas en 'A' y finalizadas con 'N'.
    if (primerc == 'A' && ultimoc == 'N'){
      acum = acum + contc;
      contpprom++;
      printf("\nEl acumulador de longitudes esta en: %f\n\n", acum);
    }

    // Resetea los valores de las vocales.
    a = 0;
    e = 0;
    i = 0;
    o = 0;
    u = 0;

    //Resetea el contardor de caracteres.
    contc = 0;

    // Resetea primer y ultimo caracter.
    primerc = 0;
    ultimoc = 0;

    if (c == ' ')
      c = getchar();

  }

  printf("##La cantidad de palabras de longitud par con todas las vocales es: %d\n", contp);
  printf("##El promedio de longitud de palabras comenzadas con A y terminadas con N es: %f\n", acum / contpprom);
  
  return 0;
}