#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <sys/time.h>

const int MAXIMO = 500000, MIN = 0;

double contador = 0;

void generarValores(int [], int);
void mostrarValores(int [], int);

void mergeSortV2(int [], int );
void MergeV2(int [], int [], int , int [], int );

void quickSort(int [], int);
void quickSortRecursivo(int [], int, int);
int particionar(int [], int, int);

void ordenacionBurbuja(int [], int);
void ordenacionInsercion(int [], int);
void ordenacionSeleccion(int [], int);

void Swap(int [], int, int);
void SwapPunteros(int *, int *);


void mergeSortRecursivo(int [], int, int);
void Merge(int [], int, int, int[], int, int[], int);

int main()
{
    srand(time(NULL));

    int arreglo[MAXIMO];

    /*
    struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);   // Instante inicial
    pasos = insertionsort(elementos[i], pruebas[i], &algoritmo);   // Ejecutar algoritmo
    gettimeofday(&tf, NULL);   // Instante final
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;*/


    generarValores(arreglo, MAXIMO);

    //printf("\nValores sin ordenar: ");
    //mostrarValores(arreglo, MAXIMO);

    //ordenacionBurbuja(arreglo, MAXIMO);
    //ordenacionSeleccion(arreglo, MAXIMO);
    //ordenacionInsercion(arreglo, MAXIMO);

    //mergeSortV2(arreglo, MAXIMO);
    //quickSort(arreglo, MAXIMO);

    //mergeSortRecursivo(arreglo, 0, MAXIMO-1);

    //printf("\nValores Ordenados: ");
    //mostrarValores(arreglo, MAXIMO);

    //printf("Pasos: %.0lf\n", contador);
    long tiempo = clock();
    printf("Tiempo:%.25f\n", (float)tiempo/CLOCKS_PER_SEC);

    return 0;
}

void generarValores(int arreglo[], int tamano)
{
    int i;
    for(i=0;i<tamano;i++)
    {
        arreglo[i] = rand() % (MAXIMO - MIN + 1) + MIN;
    }

}

void mostrarValores(int arreglo[], int tamano)
{
    int i;

    for(i = 0; i < tamano; i++)
    {
        printf("%d   ", arreglo[i]);
    }
    printf("\n\n");
}

void ordenacionBurbuja(int arreglo[], int tamano)
{
    int i, j;

    for(i = 0; i < tamano; i++)
    {
        for(j = 0; j < (tamano-i-1) ; j++)
        {
            if(arreglo[j] > arreglo[j+1])
            {
                Swap(arreglo, j, j+1);
                contador++;
            }
            contador++;
        }
        contador++;
    }
}


void ordenacionInsercion(int arreglo[], int tamano)
{
    int i, j, valorActual;

    for(i = 1; i < tamano; i++)
    {
        valorActual = arreglo[i];
        j = i-1;

        while(j >= 0 && arreglo[j] > valorActual)
        {
            arreglo[j+1] = arreglo[j];
            j--;
            contador++;
        }
        contador++;
        arreglo[j+1] = valorActual;
    }
}

void ordenacionSeleccion(int arreglo[], int tamano)
{
    int i,j, indiceMinimo;

    for(i = 0; i < tamano; i++)
    {
        indiceMinimo = i;

        for(j = i+1; j < tamano; j++)
        {
            if(arreglo[j] < arreglo[indiceMinimo])
            {
                contador++;
                indiceMinimo = j;
            }
            contador++;
        }
        contador++;
        Swap(arreglo, indiceMinimo, i);
    }
}

void mergeSortV2(int arreglo[], int tamano)
{
    contador++;
    if(tamano < 2)
        return;

    int mitad = tamano/2;
    int izquierdo[mitad];
    int derecho[tamano - mitad];
    int i;

    for(i = 0; i < mitad; i++)
    {
        contador++;
        izquierdo[i] = arreglo[i];
    }


    for(; i < tamano; i++)
    {
        derecho[i-mitad] = arreglo[i];
        contador++;
    }
    mergeSortV2(izquierdo, mitad);
    mergeSortV2(derecho, tamano-mitad);

    MergeV2(arreglo, izquierdo, mitad, derecho, tamano-mitad);
}

void MergeV2(int arreglo[], int izquierdo[], int tamanoIzquierdo, int derecho[], int tamanoDerecho)
{
    int i = 0, j = 0, k = 0;

    contador++;

    //se comparan los dos arreglos
    while(i < tamanoIzquierdo && j < tamanoDerecho)
    {
        if(izquierdo[i] < derecho[j])
            arreglo[k++] = izquierdo[i++];
        else
            arreglo[k++] = derecho[j++];
        contador++;
    }

    //se insertan los valores del arreglo que poseia valores
    while(i < tamanoIzquierdo)
    {
        arreglo[k++] = izquierdo[i++];
        contador++;
    }
    while(j < tamanoDerecho)
    {
        arreglo[k++] = derecho[j++];
        contador++;
    }


}

void quickSort(int arreglo[], int tamano)
{
    contador++;
    quickSortRecursivo(arreglo, 0, tamano-1);
}

void quickSortRecursivo(int arreglo[], int limInferior, int limSuperior)
{
    int indicePivote;
    //if(limInferior >= limSuperior)
    //    return;
    if(limInferior < limSuperior)
    {
        contador++;
        indicePivote = particionar(arreglo, limInferior, limSuperior);
        quickSortRecursivo(arreglo, limInferior, indicePivote-1);
        quickSortRecursivo(arreglo, indicePivote+1, limSuperior);
    }

}


int particionar(int arreglo[], int limInferior, int limSuperior)
{
    int pivote = arreglo[limInferior];
    int i = limInferior + 1;
    int j = i;

    for(; i <= limSuperior; i++)
    {
        if(arreglo[i] < pivote)
        {
            Swap(arreglo, i, j);
            j++;
        }
        contador++;
    }

    SwapPunteros(&arreglo[limInferior], &arreglo[j-1]);

    return j-1;
}


void Swap(int arreglo[], int indiceInicio, int indiceFinal)
{
    int burbuja;
    burbuja = arreglo[indiceInicio];
    arreglo[indiceInicio] = arreglo[indiceFinal];
    arreglo[indiceFinal] = burbuja;
    contador++;
}

void SwapPunteros(int *a, int *b)
{
    int *burbuja = (int*)malloc(sizeof(int));
    *burbuja = *a;
    *a = *b;
    *b = *burbuja;
    contador++;
}

void mergeSortRecursivo(int arreglo[], int limInferior, int limSuperior)
{
    contador++;
    if(limInferior == limSuperior)
        return;

    int tamanoIzquierdo, tamanoDerecho, i;

    if(((limSuperior - limInferior) + 1) % 2)
    {
        tamanoIzquierdo = (limSuperior - limInferior) / 2;
        tamanoDerecho = ((limSuperior - limInferior) / 2) + 1;
    }
    else
        tamanoIzquierdo = tamanoDerecho = (limSuperior - limInferior) / 2 + 1;

    int izquierdo[tamanoIzquierdo], derecho[tamanoDerecho];

    for(i = limInferior; i < tamanoIzquierdo; i++)
    {
        izquierdo[i-limInferior] = arreglo[i];
        contador++;
    }
    for(; i <= limSuperior; i++)
    {
        contador++;
        derecho[i-limInferior-tamanoIzquierdo] = arreglo[i];
    }
    mergeSortRecursivo(izquierdo, 0, tamanoIzquierdo-1);
    mergeSortRecursivo(derecho, 0, tamanoDerecho-1);
    Merge(arreglo, limInferior, limSuperior, izquierdo, tamanoIzquierdo, derecho, tamanoDerecho);
}

void Merge(int arreglo[], int limInferior, int limSuperior, int izquierdo[], int tamIzquierdo, int derecho[], int tamDerecho)
{
    int i = 0, j = 0;

    while(i < tamIzquierdo && j < tamDerecho)
    {
        if(izquierdo[i] <= derecho[j])
            arreglo[limInferior] = izquierdo[i++];
        else
            arreglo[limInferior] = derecho[j++];

        limInferior++;
        contador++;
    }

    // copiando al resto de los valores del arreglo que contiene elementos faltantes

    while(i<tamIzquierdo)
    {
        contador++;
        arreglo[limInferior++] = izquierdo[i++];
    }

    while(j<tamDerecho)
    {
        contador++;
        arreglo[limInferior++] = derecho[j++];
    }

}
