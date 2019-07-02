#include <stdlib.h>
#include "PilaEnlazada.h"

Pila* inicializarPila()
{
    Pila *nueva = (Pila*)malloc(sizeof(Pila));
    nueva->cantidad = 0;
    nueva->tope = NULL;

    return nueva;
}

void push(Pila *pila, float elemento)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->data = elemento;
    nuevo->siguiente = pila->tope;
    pila->tope = nuevo;
    pila->cantidad++;

}

float pop(Pila *pila)
{
    float resultado = pila->tope->data;

    Nodo *temp = pila->tope;
    pila->tope = pila->tope->siguiente;

    free(temp);
    pila->cantidad--;

    return resultado;
}
float peek(Pila *pila)
{
    return pila->tope->data;
}

short isEmpty(Pila *pila)
{
    return pila->cantidad == 0;
}
