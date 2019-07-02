#include <stdio.h>
#include "pilaEstatica.h"

const int TAM = 100;

Pila* iniciarPila()
{
    Pila *nuevaPila = (Pila*)malloc(sizeof(Pila));
    nuevaPila->posicionActual = 0;
    nuevaPila->tamanoPila = TAM;
    nuevaPila->Pila = (float*)malloc(TAM * sizeof(float));
    return nuevaPila;
}

void verificarEspacioPila(Pila *pila)
{
    if((pila->posicionActual+1) < pila->tamanoPila)
        return;

    pila->Pila = (float*)realloc(pila->Pila, pila->tamanoPila + TAM);
    pila->tamanoPila = pila->tamanoPila + TAM;
}

void push(Pila *pila, float elemento)
{
    verificarEspacioPila(pila);

    *(pila->Pila + pila->posicionActual) = elemento;
    //pila->Pila[pila->posicionActual] = elemento;
    pila->posicionActual++;
}

float pop(Pila *pila)
{
    float valor = *(pila->Pila + pila->posicionActual-1);
    pila->posicionActual--;

    return valor;
}

int sizepila(Pila *pila)
{
    return pila->posicionActual;
}

short isEmpty(Pila *pila)
{
    return pila->posicionActual == 0;
}

float peek(Pila *pila)
{
    float valor = pop(pila);
    push(pila, valor);
    return valor;
}
