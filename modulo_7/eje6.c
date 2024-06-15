#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
  int codmat;
  char nombre[15];
  struct lista * sig;
}nodo;


void cargar(nodo *r){

  printf("Ingresar Codigo de Materia: ");
  scanf("%d", &r -> codmat);

  if (r -> codmat == 0)
    r -> sig == NULL;
  else {
    printf("Ingresar nombre alumno: ");
    scanf("%s", r -> nombre);

    r -> sig = (nodo*)malloc(sizeof(nodo));
    cargar(r->sig);
  }
  
  return;
}


void mostrar(nodo *r){

  if (r -> sig != NULL){
    printf("Codigo Materia: %d\n", r -> codmat);
    printf("Nombre Alumno: %s\n", r -> nombre);
    mostrar(r -> sig);
  }
}


void alumnosMaterias(nodo *r){
  
  printf("VER ENUNCIADO\n");

}


int materiaMax(nodo *r){

  int max=0, cont=0, codmat_max=0;
  nodo *aux = r;

  printf("\n");

  while (r->sig != NULL){

    if (aux->codmat == r->codmat){
      printf("Cod Materia: %d, Nombre: %s\n", r->codmat, r->nombre);
      cont++;
    }
    r = r->sig;
  }
  printf("Cont codmat(%d): %d\n", aux->codmat, cont);
  if (cont>max){
    max=cont;
    codmat_max=aux->codmat;
  }

  if (aux->codmat != r->codmat)
    materiaMax(aux->sig);

  printf("Codmat MAX: %d\n", codmat_max);

  return codmat_max;
}



int main(){

  nodo *prin;
  nodo *alumnos_una_materia;
  int max;

  prin = (nodo*)malloc(sizeof(nodo));

  cargar(prin);
  mostrar(prin);
  printf("\nMOSTRAR LOS ALUMNOS POR MATERIA: \n");

  max = materiaMax(prin);
  printf("EL CODMATERIA CON MAXIMA CNT DE ALUMNOS ES: %d\n", max);

  return 0;
}





