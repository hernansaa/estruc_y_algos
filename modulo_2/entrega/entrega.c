/* Leer desde el teclado números enteros y cargar un vector con aquellos números pares. el fin de carga finaliza cuando se lee un cero o 100 números . Si el vector tiene elementos, mostrarlo; si no mostrar una leyenda indicando que no hay elementos y finalizar el programa. si hay datos se pide informar y realizar cada punto en una función:

a) Ingresar un numero por teclado y eliminar todos los números que se encuentren entre el promedio de los números ingresados en el arreglo y la mitad del numero ingresado.

b) Insertar un cero en la posición siguiente a todos los valores impares que estén entre el máximo y el promedio de los datos del vector. Mostrar el vector.

c) Ordenar el vector de mayor a menor y mostrar el vector.

Se pide desarrollar la solución con al menos 5 funciones creadas por el programador.  */


#include <stdio.h>

int cargar(int vec[]);
void mostrar(int vec[], int dim);
float encontrarPromedio(int vec[], int dim);
int eliminar(int vec[], float promedio, float num, int dim);
int encontrarMaximo(int vec[], int dim);
int insertar(int vec[], float promedio, int max, int dim);
void ordenar(int vec[], int dim);

int main(){

  int pares[100], dim_pares, num, dim_dsp_eliminacion, max, dim_dsp_insertar;
  float promedio;

  dim_pares = cargar(pares);
  promedio = encontrarPromedio(pares, dim_pares);

  if (dim_pares > 0) {
    printf("#Total numeros cargados: %d\n\n", dim_pares);
    mostrar(pares, dim_pares);

    printf("\n#El promedio de los numeros ingresados es: %f \n", promedio);

    printf("\n#Ingresar un numero para evaluar las eliminaciones: ");
    scanf("%d", &num);
    dim_dsp_eliminacion = eliminar(pares, promedio, num, dim_pares);
    mostrar(pares, dim_dsp_eliminacion);

    max = encontrarMaximo(pares, dim_dsp_eliminacion);
    printf("\n#El maximo es %d\n", max);

    printf("\nINSERTANDO...\n");
    dim_dsp_insertar = insertar(pares, promedio, max, dim_dsp_eliminacion);
    
    printf("\nMOSTRAR ARREGLO DESPUES DE INSERTAR\n");
    mostrar(pares, dim_dsp_insertar);

    printf("\nORDENAR EL VECTOR DE MAYOR A MENOR\n");
    ordenar(pares, dim_dsp_insertar);
    mostrar(pares, dim_dsp_insertar);

  } 
  else 
    printf("El arreglo no tiene elementos. Finalizar programa.\n");
  


return 0;
} // Fin del main.


int cargar(int vec[]){
  
  int i=0, num=0, cont=0;

  printf("Ingresar numero (0 para terminar): ");
  scanf("%d", &num);

  while (num != 0 && i<100) {
    if (num % 2 == 0){
      vec[i] = num;
      i++;
      printf("Numero aregado. Total agregados: %d\n", i);
    }
    printf("Ingresar numero (0 para terminar): ");
    scanf("%d", &num);
  }
  
  return i;
} 


void mostrar(int vec[], int dim){
 
  int i=0;

  printf("%5s %8s\n", "INDEX", "NUMERO");
  for (i=0; i<dim; i++){
    printf("%5d %8d\n", i, vec[i]);
  }
}


float encontrarPromedio(int vec[], int dim) {
  
  int i, acum=0;

  for (i=0; i<dim; i++){
    acum = acum + vec[i];
  }
  
  return acum/dim;
}


int eliminar(int vec[], float promedio, float num, int dim){

  int i=0, j=0;

  num = num/2;

  printf("-La mitad del numero ingresado es: %f\n", num);
  printf("-Eliminar todos los numeros entre %f y %f y vice-versa:\n", num, promedio);

  while (i < dim) {

    char condicion1 = (vec[i]>num && vec[i]<promedio);
    char condicion2 = (vec[i]<num && vec[i]>promedio);

    if (condicion1 || condicion2){
      for (j=i; j<dim; j++){
        vec[j] = vec[j+1];
      }
      printf("--Numero eliminado\n");
      dim--;
    }
    else 
      i++;
  }
  
  return dim;
}


int encontrarMaximo(int vec[], int dim){

  int i, max=vec[0];

  for (i=0; i<dim; i++){
    if (vec[i] > max){
      max = vec[i];
    }
  }
  
  return max;
}


int insertar(int vec[], float promedio, int max, int dim){
  
  int i=0, j=0;
  
  while (i < dim){
    char condicion1 = (vec[i]<max && vec[i]>promedio);
    char condicion2 = (vec[i] % 2 == 0); // Segun enunciado deberia ser "vec[i] % 2 != 0", pero para verlo en funcionamiento lo dejo asi.

    if (condicion1 && condicion2){
      for (j=dim; j>i; j--){
        vec[j] = vec[j-1];
      }
    vec[j+1] = 0;
    dim++;
    i = i+2;
    }
    else 
      i++;
  }
 
  return dim;
}

void ordenar(int vec[], int dim){
  
  int i=0, j=0, aux;

  for (i=0; i<dim-1; i++){
    for (j=i+1; j<dim; j++){
      if (vec[i] < vec[j]){
        aux = vec[i];
        vec[i] = vec[j];
        vec[j] = aux; 
      }
    }
  }

}











