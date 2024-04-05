/*Leer un texto desde el teclado compuesto por palabras,
donde las palabras pueden estar separadas por uno o mas blancos y teniendo en cuenta que puede haber uno o mas blancos
antes de la primer palabra y después de la ultima, se pide:

a) Calcular la cantidad de palabras del texto que tengan todas las vocales y que sean de longitud par.

b) Calcular el promedio de las longitudes de las palabras que empiezan con una 'A' y finalizan con una 'N'.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int c,primera,ultima,cont_p=0,cont_c=0,suma=0,cont_h=0,promedio;

    printf("ingrese la frase que desea evaluar: ");

    c=getchar();


    while(c!='.')
    {


        while(c==' ' && c!='.')
        {
            c=getchar();
        }
        primera=c;


        cont_c=0;
        while(c!=' ' && c!='.')

        {
            ultima=c;
            putchar(c);
            c=getchar();
            cont_c++;

        }

        printf(" %d",cont_c);
        printf("\n");


        if(cont_c%2==0 && c=='a' && c=='e' && c=='i' && c=='o' && c=='u')
        {
            cont_p++;
        }


        if (c==' ')
        {
            c=getchar();
        }

        suma=0;

        if (primera=='A' && ultima=='N' )
        {
            cont_h++;


        }



    }
    //promedio=suma/cont_h;

    printf("\n%d es la cantidad de palabras de longuitud par y que contienen todas las vocales",cont_p);
    printf("\n");
    printf("\nel promedio de las palabras que empiezan con A y terminan con N es de %d",cont_h);
    printf("\n");

    return 0;
}
