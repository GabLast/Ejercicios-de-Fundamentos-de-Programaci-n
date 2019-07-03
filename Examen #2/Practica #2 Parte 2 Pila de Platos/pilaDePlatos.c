#include <stdlib.h>
#include "pilaDePlatos.h"

const int TAM = 10;

ConjuntoPilas* IniciarPila(int numPilas)
{
   int i;
   ConjuntoPilas *nuevaPila;
   nuevaPila = (ConjuntoPilas *)malloc(sizeof(ConjuntoPilas));

   for (i = 0; i < numPilas; i++)
      nuevaPila->pos[i] = 0;

   nuevaPila->tam = TAM;
   nuevaPila->cantidad = 0;
   nuevaPila->Pila = (int*) malloc(TAM * sizeof(int));

   for (i = 0; i < numPilas; i++)
      nuevaPila->lim[i] = (TAM / numPilas) * i;

   return nuevaPila;
}

int VerificarEspacio(ConjuntoPilas *pila)
{
    return pila->cantidad < pila->tam;
}

void ConjuntoPilasPush(ConjuntoPilas *pila, int elemento, int numPila)
{
    if(VerificarEspacio(pila)) //si tiene espacio
        *(pila->Pila + pila->pos[numPila] + pila->lim[numPila]) = elemento;

    pila->pos[numPila]++;
    pila->cantidad++;

}

int ConjuntoPilasPop(ConjuntoPilas *pila, int numPila)
{
    if (isEmpty(pila, numPila))
        return -1;

    int valor = *(pila->Pila + pila->pos[numPila] + pila->lim[numPila] - 1);
    pila->pos[numPila]--;
    pila->cantidad--;
    return valor;
}

short isEmpty(ConjuntoPilas *pila, int numPila)
{
   return pila->pos[numPila] == 0;
}
