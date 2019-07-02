#include <stdlib.h>
#include "PilaConListas.h"

void iniciarPila(Nodo *cabeza)
{
    cabeza = NULL;
}

Nodo* push(Nodo *cabeza, float valor)
{
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));

    nuevoNodo->valor = valor;
    nuevoNodo->next = cabeza;
    cabeza = nuevoNodo;

    return cabeza;
}

Nodo* pop(Nodo *cabeza, float *elemento)
{
    Nodo *temp = cabeza;
    *elemento = cabeza->valor;
    cabeza = cabeza->next;
    free(temp);

    return cabeza;
}

short isEmpty(Nodo *cabeza)
{
    return cabeza == NULL;
}

int peek(Nodo *cabeza)
{
    return cabeza->valor;
}
