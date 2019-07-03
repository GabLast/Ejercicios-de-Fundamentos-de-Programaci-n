#include <stdio.h>
#include <stdlib.h>
#include "particionLista.h"

int main()
{

    Nodo *lista = inicializarLista();

    int i, valor, pivote, numIngresar;
    printf("Pivote y Cantidad de valores: ");
    scanf("%d %d", &pivote, &numIngresar);

    printf("Valores: ");
    for(i = 0; i < numIngresar; i++)
    {
        scanf("%d", &valor);
        lista = insertarValorInicio(lista, valor);
    }
    printf("\nLista normal:\n");
    imprimirLista(lista);

    printf("\n\nLista particionada por el pivote %d\n", pivote);
    particionarLista(lista, pivote);

}
