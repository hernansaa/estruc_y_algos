/*2. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar el texto con un
blanco y eliminando las palabras de 1 letra.*/

#include <stdio.h>


int main() {
    
    int c, contl=0;
    char aux[100];
    
    printf("Ingrese un texto terminado en un punto.\n");
    c = getchar();
    
    while (c != '.') {
        
        while (c != '.' && c != ' ') {
            // putchar(c); // Lo saque para que no imprima, y que imprima desde el aux.
            aux[contl] = c; 
            contl++;
            c = getchar();
        }    
        
        // Ahora imprimimos solo si hay mas de 1 letra en la palabra.
        if (contl > 1) {
            printf(" %s", aux);
        }
        
        // Si c es un blanco, que siga pasando hasta que no lo sea (para evitar que cuente blancos como palabras.)
        while (c == ' ') {
            c = getchar();
        }
        
        // Resetea el contador de letras para quedar listo para contar las letras de la siguiente palabra.
        contl=0;
        
        // Resetear el aux para que cargue la siguiente palabra sin basaura.
        for (int i=0; i<100; i++) {
            aux[i] = 0;
        }
    
        
    }
    
    return 0;
}
