#include <stdlib.h>
#include "ColaConLista.h"

#ifndef ColaConListaC
#define ColaConListac

Nodo *front, *rear;

void inicializarCola()
{
    front = rear = NULL;
}

void enQueue(float elemento)
{
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = elemento;
    nuevoNodo->next = NULL;
    //La cola esta vacia
    if(front == NULL && rear == NULL)
    {
        front = rear = nuevoNodo;
        return;
    }
    rear->next = nuevoNodo;
    rear = nuevoNodo;
}

void deQueue(float *valor)
{
    Nodo *temp = front;
    *valor = temp->valor;

    if(front == rear)
    {
        front = rear = NULL;
    }else
    {
        front = front->next;
    }

    free((temp));
}


short isEmpty()
{
    return front == NULL;
}

float getFront()
{
    if(isEmpty())
        return 0;

    return front->valor;
}

/*int sizeQueue(Cola *cola)
{
    return cola->cantidad;
}

void verificarEspacio(Cola *cola)
{
    int i;
    if(sizeQueue(cola) < cola->tamano)
        return;

    float *nuevoespacio = (float*)malloc(cola->tamano*2);

    i = cola->primerIndice;
    while(i != cola->ultimoIndice)
    {
         *(nuevoespacio++) = *(cola->elementos + i++);

         if(i == cola->tamano)
         {
             i = 0;
         }
    }
    cola->elementos = nuevoespacio-cola->cantidad;
    cola->primerIndice = 0;
    cola->ultimoIndice = cola->cantidad-1;
    cola->tamano = cola->tamano*2;
}*/

#endif // ColaConListaC
