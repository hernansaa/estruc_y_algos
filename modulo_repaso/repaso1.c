/* Crear y mostrar una lista donde cada nodo tiene dos números enteros (termina con -1).

-Insertar el consecutivo de cada nodo si la suma de sus elementos es mayor a 10.
-Eliminar aquellos nodos donde ambos números son pares.
-Generar una lista con la suma de los elementos de cada nodo. */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int num1;
  int num2;
  struct lista *sig;
} nodo;


typedef struct lista1 {
  int sum;
  struct lista1 *sig;
} nodo1;


void cargar(nodo *r){

  printf("Ingresar primer numero: ");
  scanf("%d", &r->num1);
  
  printf("Ingresar segundo numero: ");
  scanf("%d", &r->num2);
  
  if (r->num1 == -1 && r->num2 == -1){
    r->sig = NULL;
  }
  else{
    r->sig = (nodo*)malloc(sizeof(nodo));
    cargar(r->sig);
  }
  return;
}


void mostrar(nodo *r){

  if (r->sig != NULL){
    printf("num1: %d\n", r->num1);
    printf("num2: %d\n", r->num2);
    mostrar(r->sig);
  }
  return;
}

void insertar2(nodo *r){

  nodo *aux = NULL;

  while (r->sig != NULL){
    if ((r->num1+r->num2) > 10){
      aux = (nodo*)malloc(sizeof(nodo));
      aux->num1 = r->num1+1; //valor a insertar
      aux->num2 = r->num2+1; //valor a insertar
      aux->sig = r->sig;
      r->sig = aux;
      r = r->sig->sig;
    }
    else
      r = r->sig;
  }
  return;
}


nodo* eliminar1(nodo *r){

  nodo *aux=NULL;

  while (r->num1 % 2 == 0 && r->num2 % 2 == 0){
    aux = r->sig;
    free(r);
    r = aux;
  }
  return r;
}


void eliminar2(nodo *r){

  nodo *aux=NULL;

  while (r->sig != NULL && r->sig->sig != NULL){
    if (r->sig->num1 % 2 == 0 && r->sig->num2 % 2 == 0){
      aux = r->sig->sig;
      free(r->sig);
      r->sig = aux;
    }
    else
      r = r->sig;
  }
  return;
}


void generar(nodo *r, nodo1 *h){

  if (r->sig != NULL){
    h->sum = r->num1 + r->num2;
    h->sig = (nodo1*)malloc(sizeof(nodo1));
    generar(r->sig, h->sig);
  }

}


void mostrar2(nodo1 *h){

  if (h->sig != NULL){
    printf("%d\n", h->sum);
    mostrar2(h->sig);
  }
}


int main(){

  nodo *prin=NULL;
  nodo1 *prin1=NULL;

  prin = (nodo*)malloc(sizeof(nodo));
  prin1 = (nodo1*)malloc(sizeof(nodo1));

  cargar(prin);
  printf("Mostrar Lista:\n");
  mostrar(prin);

  printf("Insertar en la lista\n");
  insertar2(prin);
  mostrar(prin);

  printf("Eliminar en Cabeza de lista\n");
  prin = eliminar1(prin);
  mostrar(prin);

  printf("Eliminar La de lista\n");
  eliminar2(prin);
  mostrar(prin);

  printf("Mostrar Lista Generada con las sumas\n");
  generar(prin, prin1);
  mostrar2(prin1);

  return 0;
}
