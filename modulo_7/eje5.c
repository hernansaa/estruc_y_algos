#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
  
  int dni;
  char nombre[20];
  float saldo;
  struct lista *sig;

}nodo;


void cargar(nodo *registro){

  printf("Ingresar dni: ");
  scanf("%d", &registro -> dni);

  if (registro -> dni == 0)
    registro -> sig == NULL;

  else {

    printf("Ingresar nombre: ");
    scanf("%s", registro -> nombre);

    printf("Ingresar saldo: ");
    scanf("%f", &registro -> saldo);

    registro -> sig = (nodo*)malloc(sizeof(nodo));
    cargar(registro -> sig);
  }
}


void mostrar(nodo *registro){

  if (registro -> sig != NULL){
    printf("DNI: %d\n", registro -> dni);
    printf("Nombre: %s\n", registro -> nombre);
    printf("Saldo: %f\n", registro -> saldo);

    mostrar(registro -> sig);
  }
  else {
    printf("No hay mas elementos para mostrar.\n");
  }

}


void generar(nodo *r, nodo *n){

  while (r -> sig != NULL){
    
    if(r -> saldo < 0){
      n -> dni = r -> dni;
      strcpy(n->nombre, r->nombre);
      n -> saldo = r -> saldo;

      n -> sig = (nodo*)malloc(sizeof(nodo));
      n = n -> sig;
    }
    r = r -> sig;
  }
  n -> sig = NULL;
}


int main(){

  nodo *datos=NULL;
  nodo *saldos_negativos=NULL;
  
  datos = (nodo*)malloc(sizeof(nodo));
  saldos_negativos = (nodo*)malloc(sizeof(nodo));

  cargar(datos);
  printf("#MOSTRAR REGISTROS:\n");
  mostrar(datos);
  printf("MOSTRAR REGISTROS SALDOS NEGATIVOS:\n");
  generar(datos, saldos_negativos);
  mostrar(saldos_negativos);
}

