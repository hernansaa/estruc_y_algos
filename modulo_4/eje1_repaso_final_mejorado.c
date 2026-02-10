/*Leer un texto carácter a carácter, terminado en PUNTO. Mostrar cuántas
palabras tienen más de 3 letras*/

#include <stdio.h> 

int main() {
    
    int c, cont_letra=0, cont_palabra=0, cont_palabra_mas=0;

    printf("Escribir una frase terminada en '.': \n");
    
    c = getchar();
    
    printf("\n");
    
    while (c != '.') {
        
        while (c != ' ' && c != '.') {
            cont_letra++;
            putchar(c);
            c = getchar();
        }
        
        cont_palabra++;
        
        if (cont_letra > 3) {
            cont_palabra_mas++;
        }
        
        printf(" (Palabra nro %d: - Cant Letras: %d) \n", cont_palabra, cont_letra);
        
        while (c == ' ') {
            c = getchar();
        }
        
        cont_letra=0;
    }
    
    printf("\nCantidad de palabras: %d \n", cont_palabra);
    
    printf("\nCantidad de palabras con mas de 3 letras: %d \n", cont_palabra_mas);
    
    return 0;
}


