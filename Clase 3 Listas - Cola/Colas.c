#include <stdlib.h>
#include "Colas.h"

const int TAM = 10;

Cola* InicializarCola()
{
    Cola *nuevaCola = (Cola*)malloc(sizeof(Cola));
    nuevaCola->tamano = TAM;
    nuevaCola->primerIndice = 0;
    nuevaCola->ultimoIndice = -1;
    nuevaCola->elementos = (float*)calloc(TAM, sizeof(float));
    nuevaCola-> cantidad = 0;
    return nuevaCola;
}

void enQueue(Cola *cola, float elemento)
{
    //Si no hay espacio, redimensionar arreglo
    verificarEspacio(cola);

    cola->ultimoIndice++;
    if(cola->ultimoIndice > cola->tamano)
    {
        cola->ultimoIndice = 0;
    }

    *(cola->elementos+cola->ultimoIndice) = elemento;
    cola->cantidad++;
}

int sizeQueue(Cola *cola)
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
}

float deQueue(Cola *cola)
{
    if(isEmpty(cola))
        return 0;

    float respuesta = *(cola->elementos+cola->primerIndice);

    cola->primerIndice++;
    if(cola->primerIndice >= cola->tamano)
        cola->primerIndice = 0;

    cola->cantidad--;

    return respuesta;
}

short isEmpty(Cola *cola)
{
    return cola->cantidad == 0;
}

float getFront (Cola *cola)
{
    if(isEmpty(cola))
        return 0;

    return *(cola->elementos+cola->primerIndice);
}
