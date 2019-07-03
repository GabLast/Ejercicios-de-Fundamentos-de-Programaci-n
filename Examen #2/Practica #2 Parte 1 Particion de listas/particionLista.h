#include <stdlib.h>

#ifndef _partList
#define _partList


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
void particionarLista(Nodo *, int);



#endif // _partList
