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

void agregarPeli(Lista *listado, Pelicula elemento)
{
    Nodo nuevoNodo;
    nuevoNodo.data = elemento;
    nuevoNodo.siguiente = listado->cabeza;
    nuevoNodo.anterior = listado->cabeza->anterior;
    listado->cabeza->anterior->siguiente = &nuevoNodo;
    listado->cabeza->anterior = &nuevoNodo;
}

void eliminarPeli(Lista*, int);
void insertarPeli(Lista* , Pelicula, int);
Nodo* buscarPeli(Lista*, int);
Lista* ordenarPeli(Lista*);
