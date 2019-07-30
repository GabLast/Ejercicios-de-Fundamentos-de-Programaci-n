#include <stdlib.h>
#include "Lists.h"

Lista* iniciarlizarLista()
{
    Lista *nueva = (Lista*)malloc(sizeof(Lista));
    nueva->head = NULL;

    return nueva;
}

void insertarValorInicio(Lista *listado, int valor)
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->data = valor;
    nuevoNodo->next = listado->head; //esto es null cuando esta vacia
    listado->head = nuevoNodo;
    listado->tam++;
    return;
}

void agregarEnCola(Lista *listado, int valor)
{
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->data = valor;
    nuevoNodo->next = NULL;

    Nodo *temp;
    temp = listado->head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = nuevoNodo;
    listado->tam++;

    return;
}

void insertarEnPosicionX(Lista *listado, int valor, int posicion)
{
    Nodo *temp1 = (Nodo*)malloc(sizeof(Nodo));
    Nodo *temp2 = (Nodo*)malloc(sizeof(Nodo));

    temp1->data = valor;

    if(posicion == 0)
    {
        temp1->next = listado->head;
        listado->head = temp1;
        return;
    }

    int i;
    temp2 = listado->head;

    for(i = 0; i < posicion-1; i++)
    {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;

    listado->tam++;

    return;
}

void borrarNodoEnPosicionX(Lista *listado, int aBorrar)
{
    Nodo* temp1 = (Nodo*)malloc(sizeof(Nodo));
    Nodo* temp2 = (Nodo*)malloc(sizeof(Nodo));

    temp1 = listado->head;

    if(aBorrar == 0)
    {
        listado->head = temp1->next;
        listado->tam--;
        free(temp1);
        return;
    }

    int i;

    for(i = 0; i < aBorrar-1; i++)
    {
        temp1 = temp1->next;
    }

    temp2 = temp1->next;
    temp1->next = temp2->next;
    listado->tam--;

    free(temp2);
    return;
}

void imprimirLista(Lista *listado)
{
    Nodo *temp = listado->head;

    if(temp == NULL)
        printf("La lista esta vacia");

    printf("\nValores: ");
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
    return;
}
