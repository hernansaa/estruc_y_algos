/* Ingresar números hasta que dicho número sea negativo. Calcular y mostrar:
a) Cantidad de números mayores a 4 y menores a 25.
b) Promedio de aquellos números múltiplos de 6.
c) El menor número leído. */

#include <stdio.h>

int main()
{
    int num=0, cant_nums_mayores_4=0, cant_nums_menores_25=0, cant_multiplos_6=0, sum_multiplos_6=0, prom_multiplos_6=0, min=0, cont=0;
    
    while (num >=0)
    {
        //printf("Numero ingresado: %d \n", num);
        printf("Contador: %d \n", cont);
        
        printf("Ingresar numero: ");
        scanf("%d", &num);
        
        if (cont == 0)
        {
            min=num;
        }
        
        if (num > 4 && num < 25) 
        {
            cant_nums_mayores_4 += 1;
        }
        
        if (num > 0 && num % 6 == 0)
        {
            cant_multiplos_6 = cant_multiplos_6 + 1;
            sum_multiplos_6 = sum_multiplos_6 + num;
            prom_multiplos_6 = sum_multiplos_6 / cant_multiplos_6;
        }
        
        if (num > 0 && num < min)
        {
            min = num;
        }
        
        cont = cont + 1;
    }
    
    printf("Numeros mayores a 4: %d \n", cant_nums_mayores_4);
    printf("Promedio numeros multiplos de 6: %d \n", prom_multiplos_6);
    printf("Numero minimo leido: %d", min);
    
    return 0;
}
