/* 3. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar cuántas palabras
tienen más de 2 letras y terminan con “s”.*/

#include <stdio.h>


int main() {
    
    int c, contl=0, contp=0, ult=0;
    
    printf("Ingresar frase terminada en punto.\n");
    c = getchar();
    
    while (c != '.') {
        
        while (c != ' ' && c != '.'){
            contl++;
            putchar(c);
            ult = c;
            c = getchar();
        }
        
        if (contl > 2 && ult == 115){
            contp++;
        } 
        
        printf("(%d)(%d) ", contl, ult); // PARA DEBUGGIN.
        
        while (c == ' ')
            c = getchar();
        
        
        contl=0;
    }
    
    printf("\nCantidad de palabras con mas de 2 letras y terminan con s: %d", contp);
    
}
