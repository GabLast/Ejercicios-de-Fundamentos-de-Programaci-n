#include <stdlib.h>

#ifndef _List
#define _List

typedef struct Nodo
{
    int data;
    struct Nodo *next;
}Nodo;

typedef struct
{
    Nodo *head;
    int tam;
}Lista;

Lista* iniciarlizarLista();
void agregarEnCola(Lista *, int);
void insertarValorInicio(Lista *, int );
void imprimirLista(Lista *);
void insertarEnPosicionX(Lista *, int , int);
void borrarNodoEnPosicionX(Lista *, int);

#endif // _List
