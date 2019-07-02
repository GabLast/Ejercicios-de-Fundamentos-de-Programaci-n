#include <stdlib.h>

#ifndef _PilaconLista
#define _PilaconLista

typedef struct Nodo
{
    int valor;
    struct Nodo *next;

}Nodo;

void iniciarPila(Nodo *);
Nodo* push(Nodo *, float );
Nodo* pop(Nodo *, float *);
short isEmpty(Nodo *);
int peek(Nodo *);

#endif // _PilaconLista
