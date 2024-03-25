/* Se ingresan la cantidad de autos vendidos en los últimos 9 años. Calcular y mostrar:
a) El año que se vendieron la mayor cantidad de autos.
b) La cantidad total de autos vendidos */

#include <stdio.h>

int main()
{
    int cantidad, ano, max_autos=0, max_ano=0, total=0;

    for (ano=1; ano<=9; ano+=1)

    {

        printf("Ingresar cantidad de autos vendidos en el ano %d \n", ano);
        scanf("%d", &cantidad);

        if (cantidad > max_autos)
        {
            max_autos = cantidad;
            max_ano = ano;
        }

        total += cantidad;

    }

    printf("El ano que mas autos se vendio fue el ano %d, donde se vendieron %d autos. \n", max_ano, max_autos);
    printf("El total de autos vendidos en los 9 anos es %d. \n", total);

return 0;
}
