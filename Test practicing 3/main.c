#include <stdio.h>
#include <stdlib.h>
#include "Lists.h"

int main()
{
    Lista *listado = iniciarlizarLista();
    int valor, i, posicion, posBorrar;


    printf("Digite los valores: ");
    for(i = 0; i < 3; i++)
    {
        scanf("%d", &valor);
        insertarValorInicio(listado, valor);
        //agregarEnCola(listado, valor);
    }
    agregarEnCola(listado, 1);
    imprimirLista(listado);

    printf("Valor y posicion: ");
    scanf("%d %d", &valor, &posicion);
    insertarEnPosicionX(listado, valor, posicion-1);
    imprimirLista(listado);

    printf("Posicion a eliminar: ");
    scanf("%d", &posBorrar);
    borrarNodoEnPosicionX(listado, posBorrar-1);
    imprimirLista(listado);
    return 0;
}
