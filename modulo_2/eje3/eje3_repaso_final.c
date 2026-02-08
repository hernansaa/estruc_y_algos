/* 3. Ingresar los datos de las cuentas de distintos clientes de un banco. Ellos son:
▪ Nro. de cuenta
▪ Nombre y Apellido
▪ Tipo de cuenta (1. caja de ahorro, 2. cuenta corriente)
▪ Saldo.
 La carga de datos finaliza cuando el número de cuenta es 0.

 Calcular y mostrar:
a) Los datos ordenados de menor a mayor por número de cuenta
b) El nombre y apellido y el tipo de cuenta con menor saldo.
c) Generar un vector con todos los datos de aquellos clientes que
tienen saldo negativo. Mostrarlo.
d) El porcentaje de clientes que tiene un saldo en la cuenta mayor a
$100.000.
e) Se ingresan los datos de una cuenta nueva a insertarla en el vector
de tal manera que la información siga ordenada por número de cuenta.
(desplazando los elementos a derecha). */

#include <stdio.h>

int cargar(int nro_cuenta[], char nom_ape[][50], int tipo_cuenta[], float saldo[]);
void mostrar(int nro_cuenta[], char nom_ape[][50], int tipo_cuenta[], float saldo[], int dim);


int main() {
    
    int nro_cuenta[10], tipo_cuenta[10], dim; 
    float saldo[10];
    char nom_ape[10][50];
    
    dim = cargar(nro_cuenta, nom_ape, tipo_cuenta, saldo);
    mostrar(nro_cuenta, nom_ape, tipo_cuenta, saldo, dim);
    
}

// UTILS
int cargar(int nro_cuenta[], char nom_ape[][50], int tipo_cuenta[], float saldo[]) {
    
    int i=0, dim=0;
    
    printf("Numero cuenta: \n");
    scanf("%d", &nro_cuenta[i]);
    
    while (nro_cuenta[i] != 0) {
        
        printf("Nombre y apellido: \n");
        scanf("%s", nom_ape[i]);
        
        printf("Tipo cuenta: \n");
        scanf("%d", &tipo_cuenta[i]);
        
        printf("Saldo: \n");
        scanf("%f", &saldo[i]);
        
        i++;
        dim=i;
        
        printf("Numero cuenta: \n");
        scanf("%d", &nro_cuenta[i]);
    }
    return dim;   
}


void mostrar(int nro_cuenta[], char nom_ape[][50], int tipo_cuenta[], float saldo[], int dim) {
    
    int i=0;
    
    printf("Nro cuenta  Nom y Ape   Tipo cuenta     Saldo\n");
    for (i=0; i<dim; i++){
        printf("%10d %10s %14d %10f\n", nro_cuenta[i], nom_ape[i], tipo_cuenta[i], saldo[i]);
    }
}






