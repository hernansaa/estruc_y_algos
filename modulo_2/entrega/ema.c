#include<stdio.h>
#include<stdlib.h>



/*--------------------->PROTOTIPOS DE FUNCIONES<--------------------------------*/
int cargar(int a[]);
void mostrar(int a[],int n);
void ordenar(int vec[]);
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
    ins_cero=insertar(vec_pares,cant,valor_max);
    printf("el arreglo con los valores insertados es: \n ");
    mostrar(vec_pares,ins_cero);


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
    int i=0,j;
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


void ordenar(int vec[])
{
    int i,j,aux;

    for(i=0;i<10;i++)
    {
        for(j=i+1;j<10;j++)
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
