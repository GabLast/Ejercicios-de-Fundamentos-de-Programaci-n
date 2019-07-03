#include <stdlib.h>

#ifndef _PilaPlatos
#define _PilaPlatos

typedef struct
{
   int tam;
   int *Pila;
   int cantidad;
   int pos[2];
   int lim[2];
}ConjuntoPilas;

ConjuntoPilas* IniciarPila(int );

void ConjuntoPilasPush(ConjuntoPilas*, int, int);
int ConjuntoPilasPop(ConjuntoPilas*, int);
int Size(ConjuntoPilas*);
short isEmpty(ConjuntoPilas*, int);
int VerificarEspacio(ConjuntoPilas *pila);

#endif // _PilaPlatos
