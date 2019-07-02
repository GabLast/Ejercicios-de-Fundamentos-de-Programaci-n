#include <stdio.h>
#include <stdlib.h>
#include "PilaConListas.h"

void mostrarEncabezadoHistograma();
void mostrarElementoHistograma(int, float, float);
void mostrarPieHistograma(int, float);

int main()
{
    int cantidad = 0;
    float nuevoValor, elemento, total = 0;
    Nodo *unaPila;
    iniciarPila(unaPila);


    do
    {
        printf("Digite un valor (-1 para concluir):");
        scanf("%f", &nuevoValor);

        if(nuevoValor >= 0)
        {
            unaPila = push(unaPila, nuevoValor);
            total += nuevoValor;
        }

    }while(nuevoValor >= 0);

    mostrarEncabezadoHistograma();
    while(!isEmpty(unaPila))
    {
        cantidad++;
        unaPila = pop(unaPila, &elemento);
        nuevoValor = elemento;
        mostrarElementoHistograma(cantidad, nuevoValor, nuevoValor/total*100);
        printf("\n\n");
    }

    mostrarPieHistograma(cantidad, total);

    return 0;
}

void mostrarEncabezadoHistograma()
{
    //system("cls");
    printf("\n\tHistograma\n\n");
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
