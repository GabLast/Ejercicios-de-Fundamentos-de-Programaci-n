#include <stdlib.h>
#ifndef _PilaH
#define _PilaH

typedef struct sNodo
{
    float data;
    struct sNodo *siguiente;
}Nodo;

typedef struct
{
    Nodo *tope;
    int cantidad;
}Pila;

Pila* inicializarPila();
void push(Pila *, float );
float pop(Pila *);
float peek(Pila *);
short isEmpty(Pila *);

#endif // _PilaH
