/*2. Leer números enteros hasta cargar un arreglo de 10 elementos donde los primeros 5 son positivos y los restantes negativos.
a) Mostrar los primeros 4 elementos mayores del arreglo.
b) Generar otro arreglo intercalando el número positivo con los
números negativos. Mostrarlo.*/

#include <stdio.h>

void cargar(int vec[]);

int main() {
    
    int vec[10];
    
    cargar(vec);
    
}

// UTILS
void cargar(int vec[]) {
    
    int i=0, num=0;
    
    do {
        printf("Ingresar numero: ");
        scanf("%d", &num);
        
        if (num >= 0 && i < 5) {
            vec[i] = num;
            i++;
        }
        else if (num < 0 && i >=5){
            vec[i] = num;
            i++;
        }
        else {
            printf("El numero no es aceptable para esta posicion. \n");
        }
        
    } while (i < 10);
        
}

