/* . Ingresar el día y la cotización del dólar durante un mes. Calcular y mostrar el día
donde hubo la mayor cotización. */

#include <stdio.h>

int main()

{
    int dia, dia_max;
    float cotizacion, max;

    for (dia=1; dia<=30; dia+=1)

    {
        printf("Ingresar cotizacion %d \n", dia);

        scanf("%f", &cotizacion);

        if (cotizacion > max)
        {
            max = cotizacion;
            dia_max = dia;
        }

    }

    printf("La mayor cotizacion fue %f en el dia %d", max, dia_max);

return 0;
}
