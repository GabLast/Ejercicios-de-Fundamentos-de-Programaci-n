#include <stdio.h>
#include <stdlib.h>
#include "pilaDePlatos.h"

int main()
{
   int i, j, numPilas;

   printf("Num Pilas: ");
   scanf("%d", &numPilas);

   ConjuntoPilas* pilas = IniciarPila(numPilas);

   ConjuntoPilasPush(pilas, 321, 0);
   ConjuntoPilasPush(pilas, 22, 1);
   ConjuntoPilasPush(pilas, 41, 2);
   ConjuntoPilasPush(pilas, 43, 0);
   ConjuntoPilasPush(pilas, 235, 1);
   ConjuntoPilasPush(pilas, 326, 2);
   ConjuntoPilasPush(pilas, 437, 0);


   for (i = 0; i < numPilas; i++)
   {
      for(j = 0; j < numPilas; j++)
         printf("#%d: %d\n", i + 1, ConjuntoPilasPop(pilas, i));
      printf("\n");
   }

   return 0;
}
