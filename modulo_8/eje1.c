#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int num;
  struct lista * sig;
}nodo;


void cargar(nodo *h){

  printf("Ingresar un numero: ");
  scanf("%d", &h->num);

  if (h->num == 1000){
    h->sig == NULL;
  }
  else{
    h->sig = (nodo*)malloc(sizeof(nodo));
    cargar(h->sig);
  }
  return;
}


void mostrar(nodo *h){

  if (h->sig != NULL){
    printf("%d\n", h->num);
    mostrar(h->sig);
  }
}


void agregarTerceroConsecutivo(nodo *h){

  nodo *aux=NULL;

  while(h->sig != NULL){
    if (h->sig->num == h->num+1 && h->sig->sig->num == h->num+2){
      aux = (nodo*)malloc(sizeof(nodo));
      aux->num = h->num+3; //valor a insertar
      h = h->sig->sig;
      aux->sig = h->sig; 
      h->sig = aux;
    }
    h = h->sig;
  }
}


void eliminarPrimerConsec(nodo *h){

  nodo *aux=NULL;

  while(h->sig != NULL && h->sig->sig != NULL){

    if (h->sig->num == h->num+1 && h->sig->sig->num == h->num+2){
      aux = h->sig->sig;
      free(h->sig);
      h->sig = aux;
    }
    else{
      h = h->sig;
    }
  }
}


void eliminarSegundoConsec(nodo *h){

  nodo *aux=NULL;

  while (h->sig != NULL && h->sig->sig != NULL){

    if (h->sig->num == h->num+1 && h->sig->sig->num == h->num+2){
      aux = h->sig->sig->sig;
      free(h->sig->sig);
      h->sig->sig = aux;
    }
    else{
      h=h->sig;
    }
  }
}


void eliminar(nodo *h){ // DEBERIA ELMINAR DESDE P a Q inclusive, arrelgar esa parte.

  int num1=30, num2=100;
  nodo *aux=NULL;

  while (h->sig != NULL && h->sig->sig != NULL){
    if (h->num == num1 && h->sig->num != num2){
      aux = h->sig->sig;
      printf("Eliminando %d y %d\n",h->num, h->sig->num);
      free(h->sig);
      h->sig = aux;
    }
    else{
      h = h->sig;
    }
  }
  return;
}


nodo* eliminarListaCompleta(nodo *h){

  nodo *aux=NULL;

  while (h->sig != NULL){
    aux = h->sig;
    printf("Eliminando %d\n", h->num);
    free(h);
    h = aux;
  }
  return h;
}


nodo* eliminarMenoresPorCabeza(nodo *h){

  int num=20;
  nodo *aux=NULL;

  while (h->num < num){
    aux = h->sig;
    free(h);
    h = aux;
  }
  return h;
}


void eliminarMenoresEnLista(nodo *h){

  int num=20;
  nodo *aux=NULL;

  while (h->sig != NULL && h->sig->sig != NULL){

    if (h->sig->num < num){
      aux = h->sig->sig;
      free(h->sig);
      h->sig = aux;
    }
    else{
      h = h->sig;
    }
  }
}


int main(){

  nodo *prin=NULL;

  prin = (nodo*)malloc(sizeof(nodo));

  cargar(prin);
  mostrar(prin);
  printf("\nMostrar Lista con tercero consecutivo:\n");
  agregarTerceroConsecutivo(prin);
  mostrar(prin);
  printf("\nMostrar Lista con Primer Consec eliminado:\n");
  eliminarPrimerConsec(prin);
  mostrar(prin);
  printf("\nMostrar Lista con Segundo Consec eliminado:\n");
  eliminarSegundoConsec(prin);
  mostrar(prin);
  
  printf("\nEliminando de P a Q:\n");
  eliminar(prin);
  printf("\nMostrar Lista con eliminaciones de P a Q:\n");
  mostrar(prin);
  
  //ELIMINA LA LISTA COMPLETA, COMENTADO PARA SEGUIR TRABAJANDO CON ESA LISTA.
  //printf("\nMostrar Lista eliminada completamente:\n");
  //prin = eliminarListaCompleta(prin);
  //mostrar(prin);

  printf("\nMostrar Lista con elementos menores a M eliminados:\n");
  prin = eliminarMenoresPorCabeza(prin);
  printf("Eliminados por cabeza de lista");
  mostrar(prin);
  printf("Eliminados en la lista");
  eliminarMenoresEnLista(prin);
  mostrar(prin);

  /*5. Desarrollar un procedimiento para invertir una lista lineal, 
   * es decir, cambiar sus enlaces para que aparezcan en orden inverso.*/

  //printf("Lista invertida");
  //invertir(prin);
  //mostrar(prin);

  return 0;
}




