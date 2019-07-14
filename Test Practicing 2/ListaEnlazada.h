#include <stdlib.h>
#ifndef _Lista
#define _Lista

typedef struct Nodo
{
    int data;
    struct Nodo *next;
}Nodo;

Nodo* inicializarLista();
Nodo* insertarValorInicio(Nodo *, int );
void imprimirLista(Nodo *);
Nodo* insertarEnPosicionX(Nodo *, int , int);
Nodo* borrarNodoEnPosicionX(Nodo *, int);
#endif // _Lista

