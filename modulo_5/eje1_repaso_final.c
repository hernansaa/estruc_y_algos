/*Diseñar un algoritmo recursivo que permita hacer la división por restas sucesivas.*/

#include <stdio.h>

int dividir(int dividendo, int divisor) {
    
    // Caso base
    if (dividendo < divisor)
        return 0;
    
    return dividir((dividendo-divisor), divisor) + 1;
}


int main() {

    int dividendo=8, divisor=2, res=0;
    
    res = dividir(dividendo, divisor);
    
    printf("%d", res);
}

