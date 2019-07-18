#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 1000, MIN = 0;

void capturarValores(int [], int);
void generarValores(int [], int);
long generarValoresRecursivos(int [], int, int);
void mostrarValores(int [], int);
int busquedaLineal(int [], int, int);
int busquedaLinealRecursiva(int [], int, int, int);
int busquedaBinaria(int [], int, int);
int busquedaBinariaRecursiva(int [], int, int, int);
void mergeSortRecursivo(int [], int, int);
void Merge(int [], int, int, int[], int, int[], int);
void mergeSortV2(int [], int );
void MergeV2(int [], int [], int , int [], int );

int main()
{
    srand(time(NULL));

    int n, aBuscar, posicion;

    printf("Digite el tama%co del arreglo: ", 164);
    scanf("%d", &n);

    int arreglo[n];

    //capturarValores(arreglo, n);
    generarValores(arreglo, n);
    printf("\nValores sin ordenar: ");
    mostrarValores(arreglo, n);


    mergeSortRecursivo(arreglo, 0, n-1);
    //mergeSortV2(arreglo, n);

    printf("\nValores Ordenados: ");
    mostrarValores(arreglo, n);

    printf("\n\nDigite un valor a buscar: ");
    scanf("%d", &aBuscar);

    printf("\nB%csqueda Lineal\n", 163);
    posicion = busquedaLineal(arreglo, n, aBuscar);
    if(posicion >= 0)
        printf("Posici%cn del valor: %d", 162, posicion+1);
    else
        printf("El valor %d no se encuentra en la lista.", aBuscar);


    printf("\n\nB%csqueda Binaria\n", 163);
    posicion = busquedaBinaria(arreglo, n, aBuscar);
    if(posicion >= 0)
        printf("Posici%cn del valor: %d", 162, posicion+1);
    else
        printf("El valor %d no se encuentra en la lista.", aBuscar);

    printf("\n\n");
    return 0;
}


void capturarValores(int arreglo[], int tamano)
{
    int i;

    for(i = 0; i < tamano; i++)
    {
        printf("%d: ", i+1);
        scanf("%d", &arreglo[i]);
    }

}

void generarValores(int arreglo[], int tamano)
{
    long sumatoria = generarValoresRecursivos(arreglo, tamano, 0);
    printf("\n\nLa sumatoria de los aleatorios es: %d\n\n", sumatoria);
}

long generarValoresRecursivos(int arreglo[], int tamano, int pos)
{
    if(pos >= tamano)
        return 0;

    arreglo[pos] = rand() % (MAX - MIN + 1) + MIN;

    return arreglo[pos] + generarValoresRecursivos(arreglo, tamano, pos+1);
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

int busquedaLineal(int arreglo[], int tamano, int aBuscar)
{
    //Esto es un curry
    return busquedaLinealRecursiva(arreglo, tamano, aBuscar, 0);
}

int busquedaLinealRecursiva(int arreglo[], int tamano, int aBuscar, int pos)
{
    if(pos >= tamano)
        return -1;

    return arreglo[pos] == aBuscar ? pos : busquedaLinealRecursiva(arreglo, tamano, aBuscar, pos+1);

}

int busquedaBinaria(int arreglo[], int tamano, int aBuscar)
{
    return busquedaBinariaRecursiva(arreglo, aBuscar, 0, tamano-1);
}

int busquedaBinariaRecursiva(int arreglo[], int aBuscar, int limInferior, int limSuperior)
{
    int centro;

    if(limInferior > limSuperior)
        return -1;

    centro = (float)limInferior/2 + (float)limSuperior/2;

    if(arreglo[centro] == aBuscar)
        return centro;
    else if(arreglo[centro] > aBuscar) //manera creciente
        return busquedaBinariaRecursiva(arreglo, aBuscar, limInferior, centro-1);
    else
        return busquedaBinariaRecursiva(arreglo, aBuscar, centro+1, limSuperior);
}

void mergeSortRecursivo(int arreglo[], int limInferior, int limSuperior)
{
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
        izquierdo[i-limInferior] = arreglo[i];

    for(; i <= limSuperior; i++)
        derecho[i-limInferior-tamanoIzquierdo] = arreglo[i];

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
    }

    // copiando al resto de los valores del arreglo que contiene elementos faltantes

    while(i<tamIzquierdo)
        arreglo[limInferior++] = izquierdo[i++];

    while(j<tamDerecho)
        arreglo[limInferior++] = derecho[j++];
}

void mergeSortV2(int arreglo[], int tamano)
{
    if(tamano < 2)
        return;

    int mitad = tamano/2;
    int izquierdo[mitad];
    int derecho[tamano - mitad];
    int i;

    for(i = 0; i < mitad; i++)
        izquierdo[i] = arreglo[i];

    for(; i < tamano; i++)
        derecho[i-mitad] = arreglo[i];

    mergeSortV2(izquierdo, mitad);
    mergeSortV2(derecho, tamano-mitad);

    MergeV2(arreglo, izquierdo, mitad, derecho, tamano-mitad);
}

void MergeV2(int arreglo[], int izquierdo[], int tamanoIzquierdo, int derecho [], int tamanoDerecho)
{
    int i = 0, j = 0, k = 0;

    //se comparan los dos arreglos
    while(i < tamanoIzquierdo && j < tamanoDerecho)
    {
        if(izquierdo[i] < derecho[j])
            arreglo[k++] = izquierdo[i++];
        else
            arreglo[k++] = derecho[j++];
    }

    //se insertan los valores del arreglo que poseia valores
    while(i < tamanoIzquierdo)
        arreglo[k++] = izquierdo[i++];

    while(j < tamanoDerecho)
        arreglo[k++] = derecho[j++];

}
