#include <stdio.h>
#include <stdlib.h>


void crear_archivo() {

  int i=0, codart, cantart;
  float preciounit;
  FILE *archivo;

  if ((archivo=fopen("archivo.dat","w")) == NULL){
    printf("\nNo se puede abrir el archivo!");
  }
  else {
    printf("Ingrese el Codigo de Articulo (0 para terminar): ");
    scanf("%d", &codart);

    while (codart !=0){
      printf("Cantidad de Articulo: ");
      scanf("%d", &cantart);
      printf("Precio Unitario: ");
      scanf("%f", &preciounit);

      fprintf(archivo, "%d  %d  %f\n", codart, cantart, preciounit);
      printf("Ingrese el Codigo de Articulo (0 para terminar): ");
      scanf("%d", &codart);
    }
  }
  fclose(archivo);

  return;
}


int generar_vector(int vec[100]) {

  int i=0, codart, cantart;
  float preciounit;
  FILE *archivo;

  if ((archivo=fopen("archivo.dat", "r")) == NULL)
    printf("\nNo se puede abrir el archivo!");

  while (!feof(archivo)){
    fscanf(archivo, "%d  %d  %f", &codart, &cantart, &preciounit);
    vec[i] = cantart * preciounit; 
    i++;
  }
  fclose(archivo);
  
  return i-1;
}


void mostrar_vector(int vec[100], int dim){

  int i=0;

  for (i=0; i<dim; i++){
    printf("Total %d: %d\n", i, vec[i]);
  }
}


int mostrar_max(int vec[100]) {

  int i=0, codart, cantart, max=0, pos_max=0;
  float preciounit;
  FILE *archivo;

  if ((archivo=fopen("archivo.dat", "r")) == NULL)
    printf("\nNo se puede abrir el archivo!");

  while (!feof(archivo)){
    fscanf(archivo, "%d  %d  %f", &codart, &cantart, &preciounit);
    if (cantart > max){
      max = cantart;
      pos_max = codart;
    }
    i++;
  }
  fclose(archivo);
  
  return pos_max;
}



int main(){

  int totales[100], dim_vec;

  crear_archivo();
  dim_vec = generar_vector(totales);
  mostrar_vector(totales, dim_vec);
  printf("%d\n", mostrar_max(totales));

  return 0;
}
















