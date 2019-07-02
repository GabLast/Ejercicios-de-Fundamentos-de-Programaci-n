#include <stdio.h>
#include <stdlib.h>

void capturarTam(int *tamanoA);
void capturarValores(int *tamanoA, int *arreglo);
void imprimirValores(int *tamanoA, int *arreglo);
void ordenacionInsercion(int *tamanoA, int *arreglo);

int main()
{

    int tamanoA, *arreglo;
    printf("Tamano del arreglo:\n");
    capturarTam(&tamanoA);

    arreglo = (int*)calloc(tamanoA, sizeof(int));

    printf("Ingresar valores\n\n");
    capturarValores(&tamanoA, arreglo);

    printf("Valores digitados:\n");
    imprimirValores(&tamanoA, arreglo);

    printf("\nValores ordenados:\n");
    ordenacionInsercion(&tamanoA, arreglo);
    imprimirValores(&tamanoA, arreglo);
    return 0;
}

void capturarTam(int *tamanoA)
{
    do
    {
        scanf("%d", tamanoA);
    }while(tamanoA < 0);

}

void capturarValores(int *tamanoA, int *arreglo)
{
    int i;

    for(i = 0; i < *tamanoA; i++)
    {
        do
        {
            printf("Escribir un valor positivo:\n");
            scanf("%d", (arreglo+i));
        }while (*(arreglo+i) < 0);

    }
}

void imprimirValores(int *tamanoA, int *arreglo)
{
    int i;

    for(i = 0; i < *tamanoA; i++)
    {
        printf("%d\t", *(arreglo+i));
    }
}

void ordenacionInsercion(int *tamanoA, int *arreglo)
{
    int i, j, valorActual;

    for(i = 1; i < *tamanoA; i++)
    {
        valorActual = *(arreglo+i);
        j = i-1;

        while(j >= 0 && *(arreglo+j) > valorActual)
        {
            *(arreglo+j+1) = *(arreglo+j);
            j--;
        }
        *(arreglo+j+1) = valorActual;
    }
}
