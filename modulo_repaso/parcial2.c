/* Crear y mostrar una lista que contenga dos números enteros (termina con ambos números en cero).

Generar una lista nueva con el promedio de ambos números.

Insertar en la lista original la mitad del valor de cada número si la suma de los números es mayor a 15.

Eliminar aquellos nodos donde el primer valor es múltiplo del segundo valor.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int num1;
  int num2;
  struct lista *sig;
} nodo;

typedef struct lista1{
  int prom;
  struct lista1 *sig;
} nodo1;


void cargar(nodo *r){
 
  printf("Ingresar numero 1: ");
  scanf("%d", &r->num1);
  printf("Ingresar numero 2: ");
  scanf("%d", &r->num2);
  r->sig = (nodo*)malloc(sizeof(nodo));

  if (r->num1 != 0 && r->num2 != 0){
    cargar(r->sig);
  }
  else
    r->sig = NULL;
}


void mostrar(nodo *r){

  if (r->sig != NULL){
    printf("num1: %d\n", r->num1);
    printf("num2: %d\n", r->num2);
    mostrar(r->sig);
  }
}


void generar(nodo *r, nodo1 *h){

  if (r->sig != NULL){
    h->prom = (r->num1 + r->num2) / 2;
    h->sig = (nodo1*)malloc(sizeof(nodo1));
    generar(r->sig, h->sig);
  }
  else
    r->sig = NULL;
}


void mostrar1(nodo1 *h){

  if (h->sig != NULL){
    printf("%d\n", h->prom);
    mostrar1(h->sig);
  }
}

//NO LO PIDE EN REALIDAD, LO HAGO PARA REPASAR

nodo* insertar(nodo *r){

  nodo *aux = NULL;

  if ((r->num1 + r->num2) > 15){
    aux = (nodo*)malloc(sizeof(nodo));
    aux->num1 = 000;
    aux->num2 = 000;
    aux->sig = r;
    r = aux;
  }
  return r;
}


void insertar1(nodo *r){

  nodo *aux = NULL;

  while(r->sig != NULL){
    if ((r->num1+r->num2) > 15){
      aux = (nodo*)malloc(sizeof(nodo));
      aux->num1 = 999;
      aux->num2 = 999;
      aux->sig = r->sig;
      r->sig = aux;
      r = r->sig->sig;
    }
    else
      r=r->sig;
  }
}


nodo* eliminar(nodo *r){

  nodo *aux = NULL;

  while ((r->num1 % r->num2) == 0){
    aux = (nodo*)malloc(sizeof(nodo));
    aux = r->sig;
    free(r);
    r = aux;
  }
  return r;
}


void eliminar1(nodo *r){

  nodo *aux = NULL;

  while (r->sig != NULL && r->sig->sig != NULL){
    
    if ((r->sig->num1 % r->sig->num2) == 0){
      aux=(nodo*)malloc(sizeof(nodo));
      aux = r->sig->sig;
      free(r->sig);
      r->sig=aux;
    }
    else
      r= r->sig;

  }
}



int main(){

  nodo *prin=NULL;
  nodo1 *prin1=NULL;

  prin = (nodo*)malloc(sizeof(nodo));
  prin1 = (nodo1*)malloc(sizeof(nodo1));

  cargar(prin);
  mostrar(prin);

  printf("Lista con los Promedios: \n");
  generar(prin, prin1);
  mostrar1(prin1);

  printf("Lista despues de insertar en cabeza: \n");
  prin = insertar(prin);
  mostrar(prin);

  printf("Despues de insertar en Lista: \n");
  insertar1(prin);
  mostrar(prin);

  printf("Despues de eliminar en Cabeza de Lista: \n");
  prin = eliminar(prin);
  mostrar(prin);

  printf("Despues de eliminar en Lista: \n");
  eliminar1(prin);
  mostrar(prin);

  return 0;
}



