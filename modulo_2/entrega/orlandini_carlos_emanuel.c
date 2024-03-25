/*Leer desde el teclado números enteros y cargar un vector con aquellos números pares.
 el fin de carga finaliza cuando se lee un cero o 100 números .
 Si el vector tiene elementos, mostrarlo; si no mostrar una leyenda indicando que no hay elementos y finalizar el programa.
si hay datos se pide informar y realizar cada punto en una función:

a) Ingresar un numero por teclado y eliminar todos los números que se encuentren entre el promedio de los números ingresados
en el arreglo y la mitad del numero ingresado.

b) Insertar un cero en la posición siguiente a todos los valores (im????)pares que estén entre el máximo y el promedio
de los datos del vector. Mostrar el vector.

c) Ordenar el vector de mayor a menor y mostrar el vector.*/

#include<stdio.h>
#include<stdlib.h>
/*--------------------->PROTOTIPOS DE FUNCIONES<--------------------------------*/
int cargar(int a[]);
void mostrar(int a[],int n);
void ordenar(int vec[],int cont);
float promedio(int vec[],int cont);
int eliminar(int vec[],int cont,float p);
int maximo(int vec[],int cont);
int insertar(int vec[],int cont,int m);

/*--------------------->PROGRAMA PRICIPAL<--------------------------------*/
int main()
{
    int vec_pares[100],cant,n,valor_max,ins_cero;
    float prom;

    cant=cargar(vec_pares);
    printf("el arreglo con los numeros pares es: ");
    mostrar (vec_pares,cant);
    valor_max=maximo(vec_pares,cant);
    prom=promedio(vec_pares,cant);
    printf("\n el promedio de los valores del vector es %f ",prom);
    n=eliminar(vec_pares,cant,prom);
    printf("el arreglo con los numeros eliminados es:\n ");
    mostrar(vec_pares,n);
    printf("\nel valor maximo del vector es: %d \n",valor_max);
    printf("DEBUGGGGG Cantidad dimension ANTES DE INSERTAR: %d\n", n); // DEBUB 
    ins_cero=insertar(vec_pares,n,valor_max);
    printf("el arreglo con los valores insertados es: \n ");
    printf("DEBUGGGGG Cantidad dimension DESPUES DE INSERTAR: %d\n", n); // DEBUB
    mostrar(vec_pares,ins_cero);
    ordenar(vec_pares,cant);
    printf("\nel arreglo con los valores ordenados de mayor a menor es: \n");
    mostrar(vec_pares,cant);

    return 0;
}

/*--------------------->DESARROLLO DE FUNCIONES<--------------------------------*/

int cargar(int a[])
{
    int num,i=0;

    printf("ingrese un numero para el arreglo: ");
    scanf("%d",&num);

    while (num!=0)
    {
        if (num%2==0)
        {
           a[i]=num;
           i++;
        }
        printf("ingrese un numero para el arreglo: ");
        scanf("%d",&num);


    }

    return i;

}


void mostrar(int a[],int dim)
{
    int i;
    for(i=0;i<dim;i++)
    {


        printf("\n a[%d]=%d\n",i,a[i]);

    }
    return;

}


float promedio(int vec[],int cont)
{
    int i;
    float sum=0,p;

    for (i=0;i<cont;i++)

    {
        sum=sum+vec[i];

    }

    p=sum/cont;

    return p;
}


int eliminar(int vec[],int cont,float p)
{
    int num,i=0,j=0;

    printf("\n ingrese un valor cualquiera: ");
    scanf("%d",&num);
        while (i<cont)
        {
            if((vec[i]>p && vec[i]<(num/2)) || (vec[i]<p && vec[i]>(num/2)))
                {
                    for (j=i;j<cont;j++)
                    {
                        vec[j]=vec[j+1];
                    }
                    cont--;


                }
             else
                    i++;

        }
        return cont;
}


int maximo(int vec[],int cont)
{
    int i,max=0;
    for(i=0;i<cont;i++)
    {
        if(vec[i]>max)
        {
            max=vec[i];

        }
    }
    return max;
}


int insertar(int vec[],int cont,int m)
{
    int i=0,j=0;
    
    while (i<cont)
    {
        if (vec[i]<=m)
        {
            for(j=cont;j>i;j--)
            {

                    vec[j]=vec[j-1];

            }

            vec[i+1]=0;
            cont ++;
            i=i+2;
        }
        else
            i++;
    }
    return cont;

}


void ordenar(int vec[],int cont)
{
    int i,j,aux;

    for(i=0;i<cont;i++)
    {
        for(j=i+1;j<cont;j++)
        {
            if(vec[i]<vec[j])
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }

    }
}
