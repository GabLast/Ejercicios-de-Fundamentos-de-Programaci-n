#include <stdlib.h>
#include <math.h>
#include "monticulo.h"

const int ALTURA = 10;

Monticulo* inicializar(short esMin)
{
    Monticulo *nuevoHeap = (Monticulo*)malloc(sizeof(Monticulo));
    nuevoHeap->tamano = pow(2, ALTURA) - 1;
    nuevoHeap->posicionActual = 0;
    nuevoHeap->altura = ALTURA;
    nuevoHeap->esMin = esMin;
    nuevoHeap->elementos = (float*)calloc(nuevoHeap->tamano, sizeof(float));
    return nuevoHeap;
}

void verificarEspacio(Monticulo *heap)
{
    if(heap->posicionActual < heap->tamano)
        return;

    heap->altura++;
    heap->tamano = pow(2, heap->altura);
    heap->elementos = (float*)realloc(heap->elementos, heap->tamano);
}

void insertar(Monticulo *heap, float elemento)
{
    verificarEspacio(heap);

    *(heap->elementos+heap->posicionActual) = elemento;
    heap->posicionActual++;
    heapifyUP(heap, heap->posicionActual-1);
}

int IndicePadre(int indice)
{
    int result = (indice-1)/2;
    return result < 0 ? 0 : result;
}

int IndiceHijoIzquierdo(Monticulo *heap, int indice)
{
    int result = (indice*2)+1;
    return result < heap->posicionActual ? result : -1;

}

int IndiceHijoDerecho(Monticulo *heap, int indice)
{
    int result = (indice*2)+2;
    return result < heap->posicionActual ? result : -1;
}

void swapElementos(float* desde, float* hasta)
{
    float burbuja;
    burbuja = *desde;
    *desde = *hasta;
    *hasta = burbuja;
}

void heapifyUP(Monticulo *heap, int indice)
{
    //Condiciones de parada/paso base
    if(indice == 0)
        return;

    int indicePadre = IndicePadre(indice);
     if(heap->esMin && *(heap->elementos+indicePadre) < *(heap->elementos+indice))
       return;
    if(!heap->esMin && *(heap->elementos+indicePadre) > *(heap->elementos+indice))
        return;

    //Swap
    swapElementos(heap->elementos+indicePadre, heap->elementos+indice);
    //recursion
    heapifyUP(heap, indicePadre);
}

float getTop(Monticulo *heap)
{
    return *(heap->elementos);
}

float poll(Monticulo *heap)
{
    if(heap->posicionActual == 0)
        return *heap->elementos;

    float raiz = getTop(heap);

    swapElementos(heap->elementos, heap->elementos+(heap->posicionActual-1));
    heap->posicionActual--;

    heapifyDOWN(heap, 0);

    return raiz;
}

void heapifyDOWN(Monticulo *heap, int indice)
{
    int indiceMenor = IndiceHijoIzquierdo(heap, indice);
    //axioma #1
    if(indiceMenor < 0)
        return;

    //Evaluando indice menor con min heaps
    int indiceDerecho = IndiceHijoDerecho(heap, indice);
    if(heap->esMin && indiceDerecho >= 0 &&
       *(heap->elementos+indiceMenor) > *(heap->elementos+indiceDerecho))
        indiceMenor = indiceDerecho;

    // Segundo axioma para el Min Heap:
    if(heap->esMin && *(heap->elementos+indice) < *(heap->elementos+indiceMenor))
        return;

    // Evaluando índice menor con Max Heaps:
    if(!heap->esMin && indiceDerecho >= 0 &&
       *(heap->elementos+indiceMenor) < *(heap->elementos+indiceDerecho))
        indiceMenor = indiceDerecho;

    // Segundo axioma para el Max Heap:
    if(!heap->esMin && *(heap->elementos+indice) > *(heap->elementos+indiceMenor))
        return;

    swapElementos(heap->elementos+indice, heap->elementos+indiceMenor);

    heapifyDOWN(heap, indiceMenor);
}

int Size(Monticulo *heap)
{
    return heap->posicionActual;
}

int isEmpty(Monticulo *heap)
{
    return heap->posicionActual == 0;
}
