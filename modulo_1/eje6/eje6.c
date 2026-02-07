/* Ingresar números hasta que dicho número sea negativo. Por cada número leído, ingresar esa cantidad de números y obtener:
a) El promedio de cada lote leído.
b) Contar la cantidad de números pares de todos los números leídos. */

#include <stdio.h>

int main()
{
    int i=0, num=0, cont=0, cont_numeros_pares=0, cont_lote=0, num_lote=0, sum_lote=0;
    
    while (num >= 0)
    {
        printf("\n\n---------------------------");
        printf("\nIngresar numero: ");
        scanf("%d", &num);
        
        if (num >= 0)
        {
            printf("\n-El numero ingresado es %d, entonces ingresa %d numeros para este lote:\n", num, num);
            for (i=1; i<=num; i++)
            {
                printf("\n --%d)Ingresar numero: ", i);
                scanf("%d", &num_lote);
                printf("---numero ingresado: %d", num_lote);
                sum_lote = sum_lote + num_lote;
                cont_lote++;
                
                if (num_lote % 2 == 0)
                {
                    cont_numeros_pares++;
                }
            }
            printf("\n\nCantidad numeros del lote: %d", cont_lote);
            printf("\nSuma del lote: %d", sum_lote);
            printf("\nPromedio del lote: %d", sum_lote / cont_lote);
            
            
            if (num % 2 == 0)
            {
                cont_numeros_pares++;
            }
            
            cont_lote=0;
            sum_lote=0;
            num_lote=0;
        }
    }
    
    printf("\n>Cantidad numeros pares: %d", cont_numeros_pares);
}
