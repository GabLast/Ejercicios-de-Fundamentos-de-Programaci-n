#include <stdlib.h>
#ifndef _pilaEstatica
#define _pilaEstatica

typedef struct
{
    int tamanoPila;
    float *Pila;
    int posicionActual;
}Pila;

Pila* iniciarPila();
void verificarEspacioPila(Pila *);
void push(Pila *, float);
float pop(Pila *);
int sizepila(Pila *);
short isEmpty(Pila *);
float peek(Pila *);

#endif // _pilaEstatica
