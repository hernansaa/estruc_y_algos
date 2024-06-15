/* 4. Dada la siguiente lista simplemente enlazada que contiene la siguiente información:
DNI: entero positivo de hasta 8 dígitos.
Nombre: cadena de 15 caracteres
Tipo de cuenta: carácter (C,E,A)
Saldo: real
Siguiente: puntero al próximo elemento de la lista.
Desarrollar un procedimiento que busque en la lista un nodo cuyo DNI sea igual a uno
dado. El mismo devolverá un puntero al nodo hallado o NULL, si no existiera tal nodo. */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{

  int dni;
  char nombre;
  char tipo_cuenta;
  float saldo;  
  struct lista *sig;

} nodo;


void cargar(nodo *h){
  
  printf("Ingresar DNI: ");
  scanf("%d", &h -> dni);

  if (h->dni == 0)
    h->sig = NULL;

  else {
    printf("Ingresar nombre: ");
    scanf("%s", &h-> nombre);

    h -> sig = (nodo*)malloc(sizeof(nodo));
    cargar(h->sig);
  }
}


void mostrar(nodo *h){

  if (h -> sig != NULL){
    printf("\n%d", h->dni);
    mostrar(h -> sig);
  }
  printf("\n");
}


void buscar(nodo *h){

  if (h -> sig != NULL){
    if (h -> dni == 33895183){
      printf("El puntero al dni es: %d", h->dni);
    }
    else {
      printf("No es el dni\n");
      buscar(h->sig);
    }
  }

}



int main(){

  nodo *prin;
  prin = (nodo*)malloc(sizeof(nodo));
  cargar(prin);
  mostrar(prin);
  

  buscar(prin);

}












