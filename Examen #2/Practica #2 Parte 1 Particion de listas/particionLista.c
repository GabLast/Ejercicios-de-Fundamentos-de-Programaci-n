#include <stdlib.h>
#include "particionLista.h"

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

void particionarLista(Nodo *head, int pivote)
{
    int i;
    Nodo *temp = (Nodo*)malloc(sizeof(Nodo));
    temp = head;

    while(head != NULL)
    {
        if(head->data < pivote)
        {
            printf("%d ", head->data);
        }
        head = head->next;
    }

    //head = temp;

    while(temp != NULL)
    {
        if(temp->data >= pivote)
        {
            printf("%d ", temp->data);
        }
        temp = temp->next;
    }
    return;
}

void imprimirLista(Nodo *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
