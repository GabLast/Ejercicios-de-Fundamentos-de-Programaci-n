#include <stdlib.h>
#ifndef _Colah
#define _Colah

typedef struct
{
    float *elementos;
    int tamano;
    int primerIndice;
    int ultimoIndice;
    int cantidad;

}Cola;

short isEmpty(Cola *);
float getFront (Cola *);
void enQueue(Cola *, float);
float deQueue(Cola *);
void verificarEspacio(Cola *);
int sizeQueue(Cola *);
Cola *InicializarCola();

#endif // _Colah
