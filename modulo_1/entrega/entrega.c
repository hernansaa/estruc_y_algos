/* 1. Generar los primeros cuatro números malvados (No se deben ingresar valores por teclado).
Los números malvados son todo número natural cuya expresión en base 2 (binaria) contiene un número
par de unos. Por ejemplo, 12 y 15 son números malvados ya que 12=11002 y 15=11112. */

#include <stdio.h>
#include <stdlib.h>

int main(){

    int num=0, cont=1, cont_unos=0, cont_malvados=0, base, residuo, num_dividido;

    while (cont_malvados <= 3) { // Dejara de calcular cuando encuentre los 4 primeros numeros malvados

        num = cont;
        printf("------------------------------\n");
        printf("Binario de: %d \n", num);
        printf("------------------------------\n");

        //Convertir a binario

        while (num != 0) {

            base = 2;
            num_dividido = num / base;
            residuo = num % base;

            printf("%d / 2 = %d | Residuo: %d \n", num, num_dividido, residuo);

            if (residuo == 1)
                cont_unos++;

            num = num_dividido;

        }

        printf("\nContador unos: %d ", cont_unos);

        if (cont_unos % 2 == 0){
            printf("(ES MALVADO) \n", num);
            cont_malvados++;
        }

        else
            printf("(NO ES MALVADO) \n");

        cont_unos = 0;
        cont++;
    }

    printf("\n");
    printf("------------------------------\n");
    printf("Fin Contador Malvados: %d total.\n", cont_malvados);
    printf("------------------------------\n");

return 0;
}
