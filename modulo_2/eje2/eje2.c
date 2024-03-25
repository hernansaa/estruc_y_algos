/*2. Leer números enteros hasta cargar un arreglo de 10 elementos donde los primeros
5 son positivos y los restantes negativos.
a) Mostrar los primeros 4 elementos mayores del arreglo.
b) Generar otro arreglo intercalando el número positivo con los
números negativos. Mostrarlo.*/

#include <stdio.h>

void cargar(int vec[]);
void mostrar(int vec[], int n);
void calcularMaxs(int vec[], int n);
void generarIntercalar(int vec_1[], int vec_2[]);

int main() {

  int vec_a[10], vec_b[10], n=10; 

  printf("\n#Realizar la Carga\n");
  cargar(vec_a);
  
  printf("\n#Mostrar elementos\n");
  mostrar(vec_a, n);
  
  printf("\n#Calcular y mostrar los primeros 4 maximos\n");
  calcularMaxs(vec_a, n);
  mostrar(vec_a, 4);

  printf("#Generar arreglo intercalando positivos y negativos\n");
  generarIntercalar(vec_a, vec_b);
  mostrar(vec_b, n);

return 0;
} // FIN MAIN


void cargar(int vec[]) {

  int num, i=0, j=5, cont=0;

  while (cont < 10) {

    printf("-Ingresar numero:");
    scanf("%d", &num);

    if (num > 0 && i < 5) {
      vec[i] = num;
      i++;
      cont++;
    }

    if (num < 0 && j < 10) {
      vec[j] = num;
      j++;
      cont++;
    }

  }

}


void mostrar(int vec[], int n) {

  int i;

  printf("ELEMENTO   VALOR\n");
  for (i=0; i<n; i++) {
    printf("%8d %8d\n", i, vec[i]);
  }

}


void calcularMaxs(int vec[], int n) {
  
  int i, j, aux;

  for (i=0; i<n-1; i++) {
    for (j=i+1; j<n; j++) {
      if (vec[i] < vec[j]) {
        aux = vec[i];
        vec[i] = vec[j];
        vec[j] = aux;
      }
    }
  }

}


void generarIntercalar(int vec_1[], int vec_2[]) {

  int i, j=0;

  for (i=0; i<5; i++) {
    vec_2[j] = vec_1[i];
    j=j+2;
  }

  j=1;

  for (i=5; i<10;i++){
    vec_2[j] = vec_1[i];
    j=j+2;
  }

}






