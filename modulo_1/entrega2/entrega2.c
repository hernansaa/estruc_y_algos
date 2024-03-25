#include <stdio.h>
#include <stdlib.h>

int main() {

    int num, contd=1, acumd=0, cont_abundantes=0, cont_deficientes=0, total_nums=0;

    printf("#Ingresar numero: ");
    scanf("%d", &num);

    while (num != 0) {

        while (num != contd) {

            printf("Dividir por %d \n", contd);

            if (num % contd == 0) {
                acumd += contd;
                printf("El numero %d, es divisible por %d \n", num, contd);
            }
            else
                printf("El numero %d, no es divisible por %d \n", num, contd);

            contd++;
        }

        printf("------------------------------------- \n");
        printf("La suma de los divisores es %d \n", acumd);
        if (acumd > num){
            printf("El numero %d es abundante \n", num);
            cont_abundantes++;
        }
        else {
            printf("El numero %d es deficiente \n", num);
            cont_deficientes++;
        }
        printf("------------------------------------- \n");

        total_nums = cont_abundantes + cont_deficientes;

        printf("Total numeros deficientes y abundantes: %d \n", total_nums);
        printf("Porcentaje deficientes: %d \n", (cont_deficientes*100) / total_nums);
        printf("Porcentaje abundantes: %d \n", (cont_abundantes*100) / total_nums);

        // Resetear contadores y acumuladores de divisores
        // (No reseteo contadores de abundantes y deficientes)
        contd = 1;
        acumd = 0;
        printf("Contador y acumulador reseteados");

    printf("\n------------------------------------- \n");

    printf("#Ingresar numero: ");
    scanf("%d", &num);

    }

return 0;
}
