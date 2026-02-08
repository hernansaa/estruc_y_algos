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
#include <string.h>

int cargar(int nro_cuenta[], char nom_ape[][50], int tipo_cuenta[], float saldo[]);
void mostrar(int nro_cuenta[], char nom_ape[][50], int tipo_cuenta[], float saldo[], int dim);
void ordenar(int nro_cuenta[], char nom_ape[][50], int tipo_cuenta[], float saldo[], int dim);
int obtenerMinimoSaldo(float saldo[], int dim);
int generar(int nro_cuenta[], char nom_ape[][50], int tipo_cuenta[], float saldo[], float saldos_negativos[], int dim);
void mostrarVectorFloat(float vec[], int dim);

int main() {
    
    int nro_cuenta[10], tipo_cuenta[10], dim, min_i, dim_a; 
    float saldo[10], saldos_negativos[10];
    char nom_ape[10][50];
    
    // CARGAR Y MOSTRAR DATOS
    dim = cargar(nro_cuenta, nom_ape, tipo_cuenta, saldo);
    printf("\nDatos cargados: \n");
    mostrar(nro_cuenta, nom_ape, tipo_cuenta, saldo, dim);
    
    // ORDERNAR DATOS DE MENOR A MAYOR POR NUMERO DE CUENTA
    printf("\nDatos ordenados de menor a mayor por nro de cuenta: \n");
    ordenar(nro_cuenta, nom_ape, tipo_cuenta, saldo, dim);
    mostrar(nro_cuenta, nom_ape, tipo_cuenta, saldo, dim);
    
    // CLIENTE MENOR SALDO
    min_i = obtenerMinimoSaldo(saldo, dim);
    printf("\nNombre y apellido cliente menor saldo: %s\n", nom_ape[min_i]);
    printf("\nTipo de cuenta cliente menor saldo: %d\n", tipo_cuenta[min_i]);
    
    // GENERAR VECTOR CON DATOS CLIENTES CON SALDOS NEGATIVOS
    dim_a = generar(nro_cuenta, nom_ape, tipo_cuenta, saldo, saldos_negativos, dim);
    mostrarVectorFloat(saldos_negativos, dim_a);
    
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


void ordenar(int nro_cuenta[], char nom_ape[][50], int tipo_cuenta[], float saldo[], int dim) {
    
    int i, j, aux_nro_cuenta, aux_tipo_cuenta;
    float aux_saldo;
    char aux_nom[50];
    
    for (i=0; i<dim-1; i++) {
        for (j=i+1; j<dim; j++) {
            if (nro_cuenta[i] > nro_cuenta[j]) {
                
                aux_nro_cuenta = nro_cuenta[i];
                nro_cuenta[i] = nro_cuenta[j];
                nro_cuenta[j] = aux_nro_cuenta;
                
                strcpy(aux_nom, nom_ape[i]);
                strcpy(nom_ape[i], nom_ape[j]);
                strcpy(nom_ape[j], aux_nom);
                
                aux_tipo_cuenta = tipo_cuenta[i];
                tipo_cuenta[i] = tipo_cuenta[j];
                tipo_cuenta[j] = aux_tipo_cuenta;
                
                aux_saldo = saldo[i];
                saldo[i] = saldo[j];
                saldo[j] = aux_saldo;
            }
        }
    }
    
}


int obtenerMinimoSaldo(float saldo[], int dim) {
    
    int i, min_i=0;
    float min=saldo[0];
    
    for (i=0; i<dim; i++) {
        if (saldo[i] < min) {
            min = saldo[i];
            min_i = i;
        }
    }

    return min_i;
}


int generar(int nro_cuenta[], char nom_ape[][50], int tipo_cuenta[], float saldo[], float saldos_negativos[], int dim) {
    
    int i, j=0;
    
    for (i=0; i<dim; i++) {
        
        if (saldo[i] < 0) {
            saldos_negativos[j] = saldo[i];
            j++;
        }
    }
    
    return j;
}


void mostrarVectorFloat(float vec[], int dim) {
    
    int i;
    
    printf("INDEX   SALDOS NEGATIVOS\n");
    for (i=0; i<dim; i++) {
        printf("%5d %10.2f", i, vec[i]);
    }
}


