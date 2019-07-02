#include <stdlib.h>
#ifndef _monticuloh
#define _monticuloh

typedef struct
{
    int tamano;
    int posicionActual;
    int altura;
    short esMin;
    float *elementos;
}Monticulo;

void verificarEspacio(Monticulo *heap);
Monticulo* inicializar(short esMin);
void insertar(Monticulo *heap, float elemento);
float getTop(Monticulo *heap);
float poll(Monticulo *heap);
void swapElementos(float* desde, float* hasta);
void heapifyUP(Monticulo *heap, int indice);
void heapifyDOWN(Monticulo *heap, int indice);
int IndicePadre(int indice);
int IndiceHijoIzquierdo(Monticulo *heap, int indice);
int IndiceHijoDerecho(Monticulo *heap, int indice);
int Size(Monticulo *heap);
int isEmpty(Monticulo *heap);


#endif // _monticulo
