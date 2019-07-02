#include <stdio.h>
#include <stdlib.h>
#include "pilaEstatica.h"

//pilas
// push, pop, peek, size, isempty

void mostrarEncabezadoHistograma();
void mostrarElementoHistograma(int, float, float);
void mostrarPieHistograma(int, float);

int main()
{
    int cantidad = 0;
    float nuevoValor, total = 0;
    Pila *unaPila;
    unaPila = iniciarPila();

    do
    {
        printf("Digite un valor (-1 para concluir):");
        scanf("%f", &nuevoValor);

        if(nuevoValor >= 0)
        {
            push(unaPila, nuevoValor);
            total += nuevoValor;
        }

    }while(nuevoValor >= 0);


    mostrarEncabezadoHistograma();

    while(!isEmpty(unaPila))
    {
        cantidad++;
        nuevoValor = pop(unaPila);
        mostrarElementoHistograma(cantidad, nuevoValor, nuevoValor/total*100);
        printf("\n\n");
    }

    mostrarPieHistograma(cantidad, total);

    return 0;
}

void mostrarEncabezadoHistograma()
{
    system("cls");
    printf("\tHistograma\n\n");
    printf("No.:\tValor:\tProporcion:\n");
}

void mostrarElementoHistograma(int secuencia, float valor, float proporcion)
{
    int cantidadDeCaracteres = (int)proporcion;

    printf("%d\t%.2f\t", secuencia, valor);

    while(cantidadDeCaracteres-- > 0)
    {
        printf("%c", 219);
    }

    printf(" %.2f%%\n", proporcion);
}

void mostrarPieHistograma(int cantidad, float total)
{
    printf("Numero de elementos mostrados: %d. Total: %.2f", cantidad, total);
}
