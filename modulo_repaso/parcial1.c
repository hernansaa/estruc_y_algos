/* Crear una lista con tres numeros enteros que termina con el primer valor en 0. Mostrarla.
Generar otra lista con la suma de los tres numeros del nodo si la suma de los mismos supera a 10.
Insertar antes de cada nodo otro nodo con la mitad de cada valor del nodo.
Eliminar aquellos nodos cuya productoria es menor a 30.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {

  int num1;
  int num2;
  int num3;
  struct lista *sig;

} nodo;


typedef struct lista1 {
  int num;
  struct lista1 *sig;
} nodo1;


void cargar(nodo *r){

  printf("Ingresar primer numero: ");
  scanf("%d", &r->num1);

  if (r->num1 == 0){
    r->sig == NULL;
  }
  else{
    printf("Ingresar segundo numero: ");
    scanf("%d", &r->num2);
    printf("Ingresar tercer numero: ");
    scanf("%d", &r->num3);
    r->sig = (nodo*)malloc(sizeof(nodo));
    cargar(r->sig);
  }
  return;
}


void mostrar(nodo *r){

  if (r->sig != NULL){
    printf("num1: %d\n", r->num1);
    printf("num2: %d\n", r->num2);
    printf("num3: %d\n", r->num3);
    printf("-\n");
    mostrar(r->sig);
  }
}



void generar(nodo *r, nodo1 *h){

  while (r->sig != NULL){
    if ((r->num1 + r->num2 + r->num3) > 10){
      h->num = r->num1 + r->num2 + r->num3;
      h->sig = (nodo1*)malloc(sizeof(nodo1));
      h = h->sig;
    }
    r = r->sig;
  }
  h = h->sig;  //hace falta o no? 
}

void mostrar1(nodo1 *h){

  if (h->sig != NULL){
    printf("Suma: %d\n", h->num);
    printf("-\n");
    mostrar1(h->sig);
  }
}


nodo* insertarEnCabeza(nodo *r){

  nodo *aux = NULL; 

    aux = (nodo *)malloc(sizeof(nodo));
    aux->num1 = (r->num1/2); //valor a insertar
    aux->num2 = (r->num2/2);
    aux->num3 = (r->num3/2);
    aux->sig = r;
    r = aux;
  
  return r;
}


void insertarEnLista(nodo *r){

  nodo *aux=NULL;

  while (r->sig != NULL){
    aux = (nodo *)malloc(sizeof(nodo));
    aux->num1 = (r->sig->num1/2); //valor a insertar
    aux->num2 = (r->sig->num2/2);
    aux->num3 = (r->sig->num3/2);
    aux->sig = r->sig;
    r->sig = aux;
    
    r = r->sig->sig;
  }
}


nodo* eliminarEnCabeza(nodo *r){

  nodo *aux=NULL;

  while ((r->num1*r->num2*r->num3) < 30){
    aux = r->sig;
    free(r);
    r = aux;
  }
  return r;
}


void eliminarEnLista(nodo *r){

  nodo *aux=NULL;

  while (r->sig != NULL && r->sig->sig != NULL){
    if ((r->num1*r->num2*r->num3) < 30){
      aux = r->sig->sig;
      free(r->sig);
      r->sig = aux;
    }
    else{
      r = r->sig;
    }
  }
}


int main(){

  nodo *prin;
  nodo1 *prin1;
  
  prin = (nodo*)malloc(sizeof(nodo));
  prin1 = (nodo1*)malloc(sizeof(nodo1));

  cargar(prin);
  mostrar(prin);
  
  generar(prin, prin1);
  mostrar1(prin1);

  printf("Insertar En Cabeza de Lista: \n");
  prin = insertarEnCabeza(prin);
  mostrar(prin);

  printf("Insertar En Lista: \n");
  insertarEnLista(prin);
  mostrar(prin);

  printf("Eliminar nodos cuya productoria es menor a 30:\n");
  printf("Eliminar en Cabeza:\n");
  prin = eliminarEnCabeza(prin);
  mostrar(prin);
  printf("Eliminar en la Lista:\n");
  eliminarEnLista(prin);
  mostrar(prin);

  return 0;
}



