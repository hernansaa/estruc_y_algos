/* 1. Se ingresan los datos de vuelos a distintas ciudades para obtener estadísticas. 
Paraello se pide: Día de vuelo, nombre de la ciudad, capacidad del avión y cantidad 
depasajes vendidos.
Estos datos se ingresan hasta que el día de vuelo sea cero.Mostrar los datos 
ingresados.Calcular y mostrar:
a) La ciudad y el día con la mayor cantidad de pasajes vendidos
b) El porcentaje de pasajes vendidos de cada ciudad.
c) Mostar las ciudades en forma ordenada de menor a mayor según lacantidad de pasajes 
vendidos */

#include <stdio.h>

void mostrar(int vec[]);
void calcularPorcentajes(int ciudad[10],int capacidad[], int pasajes[]);
void ordenarMenoramayor(int vec[], int ciudad[]);
int encontrarMax(int vec[]);

int main() {
  
  int dia_vuelo[10], capacidad_avion[10], cant_pasajes_vendidos[10], nombre_ciudad[10];
  int i, max_index;

  for (i=0; i<3; i++) {

    printf("Dia: ");
    scanf("%d", &dia_vuelo[i]);

    printf("-Nombre de la ciudad: ");
    scanf("%d", &nombre_ciudad[i]);

    printf("-Capacidad del avion: ");
    scanf("%d", &capacidad_avion[i]);

    printf("-Cantidad pasajes vendidos: ");
    scanf("%d", &cant_pasajes_vendidos[i]);
    
  }
 

  //printf("%4s %13s %13s %13s\n", "Dia", "Ciudad", "Capacidad", "Pasajes");

  printf("Dia: \n");
  mostrar(dia_vuelo);
  
  printf("Ciudad: \n");
  mostrar(nombre_ciudad);

  printf("Capacidad Avion: \n");
  mostrar(capacidad_avion);
  
  printf("Pasajes vendidos: \n");
  mostrar(cant_pasajes_vendidos);


  max_index = encontrarMax(cant_pasajes_vendidos);
  printf("-El dia con mayor pasajes vendidos fue %d para la ciudad de %d.\n", dia_vuelo[max_index], nombre_ciudad[max_index]);

  calcularPorcentajes(nombre_ciudad, capacidad_avion, cant_pasajes_vendidos);

  ordenarMenoramayor(cant_pasajes_vendidos, nombre_ciudad);


return 0;
} // Finalizacion de main

//Muestra la informacion ingresada en forma tabulada
void mostrar(int vec[]) {
  
  int i;

  //printf("%4s %13s\n", "Index", "Elemento");
  for (i=0; i<3; i++) {
    printf("%13d\n", vec[i]);
  }
}

//Encuentra y retorna el indice del dia con mayor cantidad de pasajes vendidos
int encontrarMax(int vec[]) { 

  int i, max=0, max_index;

  for (i=0; i<3; i++) { 
    if (vec[i] > max) {
      max_index = i;
      max = vec[i];
    }
  }

  return max_index;
}

//Calcula los porcentajes de pasajes vendidos por ciudad y los muestra
void calcularPorcentajes(int nombre_ciudad[10], int capacidad[], int pasajes[]) {

  int i;
  float porcentaje;
  
  for (i=0; i<3; i++) {
    porcentaje = ((float)pasajes[i] / (float)capacidad[i]) * 100;
    printf("-Porcentaje pasajes vendidos en ciudad %d es %f por ciento. \n", nombre_ciudad[i], porcentaje);
  }
  
}

//Ordena ciudades de menor a mayor segund cantidad de pasajes vendidos
void ordenarMenoramayor(int vec[], int ciudad[]) {

  int i, j, aux, aux_ciudad;

  for (i=0; i<3-1; i++) {
    for (j=i+1;j<3; j++) {
      if (vec[i] > vec[j]) {
        aux = vec[i];
        vec[i] = vec[j];
        vec[j] = aux;

        aux_ciudad = ciudad[i];
        ciudad[i] = ciudad[j];
        ciudad[j] = aux_ciudad;

      }
    } 
  }
  
  for (i=0; i<3; i++) {
    printf("Pasajes: %d, Ciudad: %d\n", vec[i], ciudad[i]);
  }

}











