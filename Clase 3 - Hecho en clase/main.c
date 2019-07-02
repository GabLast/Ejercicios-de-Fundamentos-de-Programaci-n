#include <stdio.h>
#include <stdlib.h>
#include "PilaEnlazada.h"

int main()
{
    Pila *unapila = inicializarPila();

    push(unapila, 32.2);
    push(unapila, 23.1);
    push(unapila, 22.3);
    push(unapila, 64.5);
    push(unapila, 54.3);
    push(unapila, 1.3);
    push(unapila, 543.3);
    push(unapila, 32.2);
    push(unapila, 76.5);

    while(!isEmpty(unapila))
    {
        printf("%.2f\n", pop(unapila));
    }
    return 0;
}
