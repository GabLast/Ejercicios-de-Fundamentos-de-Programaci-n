#include <stdlib.h>
#include "ListaEnlazada.h"

Nodo* inicializarLista()
{
    Nodo *head = NULL;
    return head;
}

Nodo* insertarValorInicio(Nodo *head, int valor)
{
    Nodo *temp = (Nodo*)malloc(sizeof(Nodo));
    temp->data = valor;
    temp->next = head;

    head = temp;

    return head;
}

Nodo* insertarEnPosicionX(Nodo *head, int data, int posicion)
{
    Nodo *temp1 = (Nodo*)malloc(sizeof(Nodo));
    Nodo *temp2 = (Nodo*)malloc(sizeof(Nodo));

    temp1->data = data;

    if(posicion == 1)
    {
        //insertar en la cabeza/pos1
        temp1->next = head;
        head = temp1;
        return head;

        //return head = insertarValorInicio(head, data);
    }

    int i;
    temp2 = head;

    for(i = 0; i < posicion; i++)
    {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;

    return head;
}

Nodo* borrarNodoEnPosicionX(Nodo *head, int posicionABorrar)
{

    Nodo *temp1 = (Nodo*)malloc(sizeof(Nodo));
    Nodo *temp2 = (Nodo*)malloc(sizeof(Nodo));
    temp1 = head;

    if(posicionABorrar == 1)
    {
        //borrar cabeza
        head = temp1->next;
        free(temp1);
        return head;
    }

    int i;
    for(i=0; i<posicionABorrar; i++)
    {
        temp1 = temp1->next; //temp1 apunta al nodo a borrar
    }

    temp2 = temp1->next; // nodo a borrar
    temp1->next = temp2->next; //nodo siguiente al nodo a borrar

    free(temp2);


    return head;
}

void imprimirLista(Nodo *head)
{
    while(head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}
