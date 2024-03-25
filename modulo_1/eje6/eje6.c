/* Ingresar números hasta que dicho número sea negativo. Por cada número leído,
ingresar esa cantidad de números y obtener:
a) El promedio de cada lote leído.
b) Contar la cantidad de números pares de todos los números leídos. */

#include <stdio.h>
#include <stdlib.h>

int main()
{

    float cont=0, cnt_pares;
    float num, prom;


    while (num >= 0) {

        cont+=1;

        printf("Ingresar numero: ");
        scanf("%f", &num);

        printf("%f \n", cont);

        printf("%f \n", (num/cont) * 100);

    }

return 0;
}
