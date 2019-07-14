#include <stdio.h>
#include <stdlib.h>
#include "ListaEnlazada.h"

int main()
{
    Nodo *lista = inicializarLista();

    int valor, i, posicion;

    for(i=0;i<5;i++)
    {
        printf("Valor: ");
        scanf("%d", &valor);
        printf("\n");
        lista = insertarValorInicio(lista, valor);
    }

    printf("\nLista:\n");
    imprimirLista(lista);

    do
    {
        printf("\nValor y posicion: ");
        scanf("%d %d", &valor, &posicion);
        if(valor!=0)
            lista = insertarEnPosicionX(lista, valor, posicion);

    }while(valor != 0);

    printf("\nLista:\n");
    imprimirLista(lista);

    do
    {
        printf("\nPosicion a borrar(-1 para salir): ");
        scanf("%d", &posicion);
        if(posicion!=-1)
            lista = borrarNodoEnPosicionX(lista, posicion);

        printf("\nLista:\n");
        imprimirLista(lista);
    }while(posicion != -1);

    return 0;
}

