#include <stdlib.h>
#ifndef _ListaDobleCirc
#define _ListaDobleCirc

typedef struct
{
    int id;
    char *titulo;
    int anio;
    char *clasificacion;
    float calificacion;
    float duracion;
    int cantidadGeneros;
    char **generos;
    char *sinopsis;
}Pelicula;

typedef struct sNodo
{
    Pelicula data;
    struct sNodo *anterior;
    struct sNodo *siguiente;
}Nodo;

typedef struct
{
    Nodo *cabeza;
    int cantidad;
}Lista;

Lista* InicializarLista();
void agregarPeli(Pelicula, Nodo*);
void eliminarPeli(Lista*, Nodo*);
Nodo* buscarPorID(Lista *, int );
Nodo* buscarPeliPorAnyo(Lista*, int);
void ordenarPeliConSeleccion(Lista*);
Nodo* copiarNodo(Nodo*);
void intercambiar(Nodo *, Nodo *);



#endif // _ListaDobleCirc
