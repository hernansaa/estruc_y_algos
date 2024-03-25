/* Ingresar la edad y sueldo de los empleados de una empresa hasta que ambas sean
cero. Calcular y mostrar:
a) El promedio de edad de los que ganan más de $10000
b) El sueldo de aquellas personas mayores a 58 años, sabiendo que
cobran un plus del 5% de su sueldo.
c) El porcentaje de empleados cuyo sueldo es menor a 15000, que está
entre 15000 y 20000, y mayor a 20000. */

#include <stdio.h>

int main()
{
    int edad, cont=0, cont_edad_sueldo_alto=0;
    float cont_sueldo_alto=0, cont_sueldo_medio=0, cont_sueldo_bajo=0;
    float sueldo, sumador_edad_sueldo_alto=0, prom_sueldo_alto;

    printf("Ingresar edad: ");
    scanf("%d", &edad);

    printf("Ingresar sueldo: ");
    scanf("%f", &sueldo);

    while (edad !=0 && sueldo !=0)
    {

        if (sueldo > 10000) {
            sumador_edad_sueldo_alto += edad;
            cont_edad_sueldo_alto += 1;
        }

        if (edad > 58) {
            printf("El sueldo con plus del 5 por ciento de la persona mayor de 58 anios es: %f \n", sueldo * 1.05);
        }

        if (sueldo < 15000) {
            cont_sueldo_bajo += 1;
        }

        if (sueldo < 20000 && sueldo > 15000) {
            cont_sueldo_medio += 1;
        }

        if (sueldo > 20000) {
            cont_sueldo_alto += 1;
        }

        cont+=1;

        printf("Ingresar edad: ");
        scanf("%d", &edad);

        printf("Ingresar sueldo: ");
        scanf("%f", &sueldo);
    }

    printf("El promedio de edad de los que ganan mas de $10000, es %f \n", sumador_edad_sueldo_alto/cont_edad_sueldo_alto);

    printf("El total de empleados es: %d \n", cont);

    printf("Porcentajes sueldo alto: %f \n", cont_sueldo_alto/cont) * 100;
    printf("Porcentajes sueldo medio: %f \n", (cont_sueldo_medio/cont) * 100);
    printf("Porcentajes sueldo bajo: %f \n", (cont_sueldo_bajo/cont) * 100);


return 0;
}
