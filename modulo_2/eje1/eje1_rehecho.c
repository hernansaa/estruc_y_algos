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

int calcularPorcentaje(int capacidad_avion[], int cant_pasajes_vendidos[], int ciudad_index);
int encontrarMax(int vec[], int n);
int cargar(int dia_vuelo[], char nombre_ciudad[][30], int capacidad_avion[], int cant_pasajes_vendidos[]);
void mostrarInt(int vec[], int n);
void mostrarStr(char vec[][30], int n);


int main()
{
    int cant, dia_vuelo[10], capacidad_avion[10], cant_pasajes_vendidos[10];
    int max_index=0;
    char nombre_ciudad[10][30];
    
    cant = cargar(dia_vuelo, nombre_ciudad, capacidad_avion, cant_pasajes_vendidos);
    
    max_index = encontrarMax(cant_pasajes_vendidos, cant);
    
    printf("DIA    VALOR\n");
    mostrarInt(dia_vuelo, cant);
    
    printf("CIUDAD    VALOR\n");
    mostrarStr(nombre_ciudad, cant);
    
    printf("\nCiudad y dia mayor pasajes vendidos: %s (%d pasajes vendidos)  \n", nombre_ciudad[max_index], cant_pasajes_vendidos[max_index]);
    
    printf("\nPorcentaje pasajes vendidos de esa ciudad: ");
    printf("%d", calcularPorcentaje(capacidad_avion, cant_pasajes_vendidos, max_index));
    
   return 0; 
}


// FUNCIONES UTILITARIAS

int calcularPorcentaje(int capacidad_avion[], int cant_pasajes_vendidos[], int ciudad_index)
{
    float porcentaje = ((float)cant_pasajes_vendidos[ciudad_index] / (float)capacidad_avion[ciudad_index]) * 100;
    
    return porcentaje;
}


int encontrarMax(int vec[], int n)
{
    int i, max=0, max_index=0;
    
    for (i=0; i<n; i++)
    {
        if (vec[i] > max){
            max = vec[i];
            max_index = i;
        }
    }
    return max_index;
}


int cargar(int dia_vuelo[], char nombre_ciudad[][30], int capacidad_avion[], int cant_pasajes_vendidos[])
{
    int i=0;
    
    printf("Dia vuelo: ");
    scanf("%d", &dia_vuelo[i]);
    
    while (dia_vuelo[i] != 0) 
    {
        printf("Ciudad: ");
        scanf("%s", nombre_ciudad[i]);
        
        printf("Capacidad avion: ");
        scanf("%d", &capacidad_avion[i]);
        
        printf("Cantidad pasajes vendidos: ");
        scanf("%d", &cant_pasajes_vendidos[i]);
        
        i++;
        
        printf("Dia vuelo: ");
        scanf("%d", &dia_vuelo[i]);
    }
    return i;
}

void  mostrarInt(int vec[], int n)
{
    int i;
 
    for (i=0; i<n; i++)
    {
        printf("%8d %8d \n", i, vec[i]);
    }
}

void  mostrarStr(char vec[][30], int n)
{
    int i;
 
    for (i=0; i<n; i++)
    {
        printf("%8d %8s \n", i, vec[i]);
    }
}
