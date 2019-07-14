#include <stdlib.h>
#include "listaDobleCircular.h"

Lista* InicializarLista()
{
    Lista *nuevaLista = (Lista*)malloc(sizeof(Lista));
    nuevaLista->cantidad = 0;
    nuevaLista->cabeza = (Nodo*)malloc(sizeof(Nodo));
    nuevaLista->cabeza->data.id = -1;
    nuevaLista->cabeza->siguiente = nuevaLista->cabeza;
    nuevaLista->cabeza->anterior = nuevaLista->cabeza;
    return nuevaLista;
}

void agregarPeli(Pelicula elemento, Nodo *despuesDe)
{
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));

    nuevoNodo->data = elemento;
    nuevoNodo->siguiente = despuesDe->siguiente;
    nuevoNodo->anterior = despuesDe;
    despuesDe->siguiente->anterior = nuevoNodo;
    despuesDe->siguiente = nuevoNodo;

    return;
}

Nodo* buscarPorID(Lista *listadoPeliculas, int id)
{
    Nodo *nodoActual = listadoPeliculas->cabeza->siguiente;

    while(nodoActual->data.id != -1)
    {
        if(nodoActual->data.id == id)
            return nodoActual;

        nodoActual = nodoActual->siguiente;
    }
    return NULL;
}


void eliminarPeli(Lista *listadoPeliculas, Nodo *aEliminar)
{
    if(aEliminar ->data.id == -1)
        return;

    aEliminar->anterior->siguiente = aEliminar->siguiente;
    aEliminar->siguiente->anterior = aEliminar->anterior;

    free(aEliminar);
}

Nodo* buscarPeliPorAnyo(Lista *listadoPeliculas, int anyo)
{
    Nodo *nodoActual = listadoPeliculas->cabeza->siguiente;

    while(nodoActual->data.id != -1)
    {
        if(nodoActual->data.anio > anyo)
            return nodoActual->anterior;

        nodoActual = nodoActual->siguiente;
    }

    return nodoActual->anterior;
}

Nodo* copiarNodo(Nodo *original)
{
    Nodo *copia = (Nodo*)malloc(sizeof(Nodo));

    copia->data = original->data;
    copia->anterior = original->anterior;
    copia->siguiente = original->siguiente;

    return copia;
}

void intercambiar(Nodo *primero, Nodo *segundo)
{
    Nodo *auxPrimero = copiarNodo(primero);

    primero->anterior->siguiente = segundo;
    primero->anterior = segundo->anterior;
    primero->siguiente->anterior = segundo;
    primero->siguiente = segundo->siguiente;

    segundo->siguiente = auxPrimero->siguiente;
    segundo->anterior->siguiente = primero;
    segundo->anterior = auxPrimero->anterior;
    primero->siguiente->anterior = primero;

    free(auxPrimero);
}

void ordenarPeliConSeleccion(Lista *listadoPeliculas)
{
    Nodo *nodoActual = listadoPeliculas->cabeza->siguiente;
    Nodo *nodoMenor;
    Nodo *temp;

    while(nodoActual->data.id != -1)
    {
        nodoMenor = nodoActual;
        temp = nodoActual->siguiente;

        while(temp->data.id != -1)
        {
            if(temp->data.anio < nodoMenor->data.anio)
            {
                nodoMenor = temp;
            }
            temp = temp->siguiente;
        }
        intercambiar(nodoActual, nodoMenor);
        nodoActual = nodoActual->siguiente;
    }

    return;
}
