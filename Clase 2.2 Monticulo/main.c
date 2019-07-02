#include <stdio.h>
#include <stdlib.h>

#include "monticulo.h"

int main()
{
    Monticulo *unheap;
    int num;
    unheap = inicializar(1);

    printf("Ingresar valores (-1 para terminar proceso):\n");
    do
    {
        scanf("%d", &num);
        insertar(unheap, num);
    }while(num != -1);

    printf("\nTamano del heap: %d\n", Size(unheap));

    while(!isEmpty(unheap))
    {
        printf("%.2f\n", poll(unheap));
    }


    return 0;
}
