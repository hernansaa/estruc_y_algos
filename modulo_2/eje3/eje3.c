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

int cargar(int num_cuenta[], char nombre_apellido[][50], int tipo_cuenta[], float saldo[]);
void mostrar(int num_cuenta[], char nombre_apellido[][50], int tipo_cuenta[], float saldo[], int dim);
void mostrarVector(float vec[], int dim);
void mostrarVectorInt(int vec[], int dim);
int menorSaldo(int num_cuenta[], float saldo[]);
int generar(int num_cuenta[], char nombre_apellido[][50], int tipo_cuenta[], float saldo[], float saldos_negativos[]);
float calcularPorcenjes(float vec[], int dim);
int insertar(int vec[], int dim);

int main() {

  int num_cuenta[5]={0}, tipo_cuenta[5]={0}, pos_min, dim_saldos, dim_carga, dim_insertar;
  float saldo[5]={0}, saldos_negativos[5], porcentaje;
  char nombre_apellido[5][50]={0};
  
  printf("REALIZAR LA CARGA EN LOS VECTORES:\n");
  dim_carga = cargar(num_cuenta, nombre_apellido, tipo_cuenta, saldo);
  cargar(num_cuenta, nombre_apellido, tipo_cuenta, saldo);
  printf("\nDIM CARGA: %d\n", dim_carga);
  
  printf("\nMOSTRAR DATOS:\n");
  mostrar(num_cuenta, nombre_apellido, tipo_cuenta, saldo, dim_carga);

  pos_min = menorSaldo(num_cuenta, saldo);
  printf("\nPosition minimo: %d\n", pos_min);
  printf("El nombre y apellido con el menor saldo es %s y tiene un tipo de cuenta %d\n", nombre_apellido[pos_min], tipo_cuenta[pos_min]);

  dim_saldos = generar(num_cuenta, nombre_apellido, tipo_cuenta, saldo, saldos_negativos);
  printf("\nDim saldos negativos: %d\n", dim_saldos);
  mostrarVector(saldos_negativos, dim_saldos);

  porcentaje = calcularPorcenjes(saldo, dim_carga);
  printf("\nPORCENTAJE CLIENTES CON SALDO MAYOR A 100k: %f\n", porcentaje);

  printf("\nINSERTAR CUENTA NUEVA:\n");
  insertar(num_cuenta, dim_carga);
  dim_insertar = insertar(num_cuenta, dim_carga);
  mostrarVectorInt(num_cuenta, dim_insertar);

return 0;
} // END MAIN

int cargar(int num_cuenta[], char nombre_apellido[][50], int tipo_cuenta[], float saldo[]) {

  int i=0, dim=0;
  
  printf("\nNumero de cuenta:");
  scanf("%d", &num_cuenta[i]);

  while (num_cuenta[i] != 0) {

    printf("Nombre y apellido:");
    scanf("%s", nombre_apellido[i]);
    
    printf("Tipo de cuenta:");
    scanf("%d", &tipo_cuenta[i]);
    
    printf("Saldo:");
    scanf("%f", &saldo[i]);
    
    i++;
    dim = i;

    printf("\nNumero de cuenta:");
    scanf("%d", &num_cuenta[i]);
  }
  return dim;
}

void mostrar(int num_cuenta[], char nombre_apellido[][50], int tipo_cuenta[], float saldo[], int dim) {

  int i, j, aux;
  
  printf("%5s %15s %20s %15s %15s \n","INDEX", "N_CUENTA", "NOMBRE_Y_APELLIDO", "TIPO_CUENTA", "SALDO");
  
  for (i=0; i<dim; i++) {

    for (j=i+1; j<dim; j++) { 
    
      if (num_cuenta[i] > num_cuenta[j]) { 
        aux = num_cuenta[i];
        num_cuenta[i] = num_cuenta[j];
        num_cuenta[j] = aux;
      }

    } 
    printf("%5d %15d %20s %15d %15f\n", i, num_cuenta[i], nombre_apellido[i], tipo_cuenta[i], saldo[i]);
  } 

}


void mostrarVector(float vec[], int dim) {

  int i;

  printf("%5s %10s\n", "INDEX", "VALOR");
  for (i=0; i<dim; i++) {
    printf("%5d: %10f\n", i, vec[i]);
  }
}

void mostrarVectorInt(int vec[], int dim) {

  int i;

  printf("%5s %10s\n", "INDEX", "VALOR");
  for (i=0; i<dim; i++) {
    printf("%5d %10d\n", i, vec[i]);
  }
}


int menorSaldo(int num_cuenta[], float saldo[]) {

  int i, pos_min = 0;
  float min = saldo[0];

  for (i=0; i<5; i++) {
    if (saldo[i] < min && num_cuenta[i] != 0) {
      min = saldo[i];
      pos_min = i;
    }
  }
  return pos_min;
}

// Solo guardo en el nuevo vector los saldos negativos. Esperando aclaracion consigna.
int generar(int num_cuenta[], char nombre_apellido[][50], int tipo_cuenta[], float saldo[], float saldos_negativos[]) {

  int i, dim=0;

  for (i=0; i<5; i++) {
    if (saldo[i] < 0) {
      saldos_negativos[i] = saldo[i];
      dim++;
    }
  }
  return dim;
}


float calcularPorcenjes(float vec[], int dim) {

  int i, cont=0;

  for (i=0; i<=dim; i++) {
    if (vec[i] > 100000) {
      cont++;
    }
  }
  return ((float)cont / (float)dim) * 100;
}

// Falta agregar la lectura del numero de cuenta y que quede ordenado por numero de cuenta.
int insertar(int vec[], int dim) {

  int i=0, j=0;

  while (i < dim) {

    if (vec[i] == dim) {

      for (j=dim; j>i; j--){
        vec[j]=vec[j-1];
      }

    vec[i+1] = 3; // En 3 deberia ir el numero de cuenta a insertar.
    dim++;
    i=i+2;
    }
    else 
      i++;
  }
  return dim;
}




















