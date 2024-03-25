/* Ingresar números hasta que dicho número sea negativo. Calcular y mostrar:
a) Cantidad de números mayores a 4 y menores a 25.
b) Promedio de aquellos números múltiplos de 6.
c) El menor número leído. */

#include <stdio.h>

int main()
{

    int num, mayores_de_4=0, menores_de_25=0, min=0;
    float multiplos_de_6=0, suma_multiplos_de_6=0;

    printf("Ingresar numero: \n");
    scanf("%d", &num);
    min = num;

    while (num >= 0)
    {
        if (num > 4)
            mayores_de_4 += 1;

        if (num < 25)
         menores_de_25 += 1;

        if (num % 6 == 0)
        {
            multiplos_de_6 += 1;
            suma_multiplos_de_6 += num;

        }

        if (num < min)
            min = num;

        printf("Ingresar numero: \n");
        scanf("%d", &num);

    }

    // Punto A
    printf("La cantidad de mayores a 4 es %d \n", mayores_de_4);
    printf("La cantidad de menores a 25 es %d \n", menores_de_25);

    // Punto B
    printf("El promedio de los multiplos de 6 es %f\n", suma_multiplos_de_6 / multiplos_de_6);

    // Punto C
    printf("El menor numero leido es: %d", min);


return 0;
}

