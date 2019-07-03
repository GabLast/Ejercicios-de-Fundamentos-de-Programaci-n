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
void agregarPeli(Lista*, Pelicula);
void eliminarPeli(Lista*, int);
void insertarPeli(Lista* , Pelicula, int);
Nodo* buscarPeli(Lista*, int);
Lista* ordenarPeli(Lista*);





#endif // _ListaDobleCirc
