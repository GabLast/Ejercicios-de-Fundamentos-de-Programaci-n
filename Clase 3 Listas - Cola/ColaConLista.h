#include <stdlib.h>

#ifndef ColaConLista
#define ColaConLista


typedef struct Nodo
{
    float valor;
    struct Nodo *next;

}Nodo;

void inicializarCola();
void enQueue(float );
void deQueue(float *);
short isEmpty();
float getFront();

//void verificarEspacio();
//int sizeQueue();
#endif // ColaConLista
