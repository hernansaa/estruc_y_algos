/* Calcular el índice de masa corporal ingresando el peso de una persona en kilos y su
estatura en metros. Este índice se obtiene realizando el cociente entre el peso y el
cuadrado de la estatura. */

#include <stdio.h>

int main()

{

    float peso, estatura, indice;

    printf("Ingresar el peso: \n");
    scanf("%f", &peso);

    printf("Ingresar la estatura: \n");
    scanf("%f", &estatura);

    indice = peso / (estatura*estatura);

    printf("El peso es %f, la estatura %f, entonces el indice es %f", peso, estatura, indice);

    return 0;

}

