#include <stdio.h>
#include <stdlib.h>

int cargar(int vec[], int dim){

  int i=0, num=0, cont=0;

  while (cont != dim) {
    printf("Ingresar numero: ");
    scanf("%d", &num);
    vec[i] = num;
    i++;
    cont++;
    printf("Numero agregado. Total agregados %d\n", i);
  }

  return i;
}


int mostrar(int vec[], int dim){
  
  int i=0;

  printf("%5s %5s\n", "INDEX:", "NUMERO:");
  
  for (i=0; i<dim; i++){
    printf("%5d %8d\n", i, vec[i]);
  }

}


void crear_archivo(int vec[], int dim){

  int i=0;
  FILE *pares;

  if ((pares=fopen("pares.dat", "w")) == NULL)
    printf("\nNo se puede abrir el archivo!\n");
  else {
    for (i=0; i<dim; i++){
      if (vec[i] % 2 == 0)
        fprintf(pares,"%d\n", vec[i]);
    }
  }
  fclose(pares);

  return;
}


void mostrar_archivo(){

  int num=0;
  FILE *pares;

  if ((pares=fopen("pares.dat", "r")) == NULL)
    printf("\nNo se puede abrir el archivo!\n");
  else {
    while (!feof(pares)){
      fscanf(pares, "%d\n", &num);
      printf("\nNumero par: %d", num);
    }
    fclose(pares);
    printf("\n");
  }

  return; 
}

void mostrar_registro_3(){
  /* Observacion: Podria haber escrito el index en el archivo
   * asi sacaba el registro mas facil"""*/

  int num=0, reg=1;
  FILE *pares;

  if ((pares=fopen("pares.dat", "r")) == NULL)
    printf("\nNo se puede abrir el archivo!\n");
  else {
    while (!feof(pares)){
      fscanf(pares, "%d\n", &num);
      if (reg == 3){
        printf("\nNumero par en el registro numero 3: %d", num);
        printf("\nRegistro: %d", reg);
      }
      reg++;
    }
    fclose(pares);
    printf("\n");
  }

  return;
}


int main() {

  int enteros[30], dim=10;

  printf("Hola mundo\n");
  cargar(enteros, dim);
  mostrar(enteros, dim);
  crear_archivo(enteros, dim);
  mostrar_archivo();
  mostrar_registro_3();

  return 0;
}




