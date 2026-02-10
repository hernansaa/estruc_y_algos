/*2. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar el texto con un
blanco y eliminando las palabras de 1 letra.*/

#include <stdio.h>


int main() {
    
    int c, contl=0;
    
    printf("Ingrese un texto terminado en un punto.\n");
    c = getchar();
    
    while (c != '.') {
        
        while (c != '.' && c != ' ') {
            
            contl++;
            putchar(c);
            c = getchar();
        }    
        
        printf("(%d) ", contl); // Agrego cantidad de letras, solo para DEBUG.
        
        while (c == ' ') {
            c = getchar();
        }
        
        
        contl=0;
    }
    
}
