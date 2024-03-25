#include <stdio.h>


void dupli(int arre[])

{

   arre[0] = arre[0] * 2;

}

void doble(int a)

{

  a = a * 2;

}

int main()

{

   int a[3] = {1,2,3}, num = 3;

   dupli(a);

   doble(num);

  printf("%d",a[0] + num);

  return 0;

}
