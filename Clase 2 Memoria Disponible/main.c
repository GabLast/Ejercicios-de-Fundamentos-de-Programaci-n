#include <stdio.h>
#include <stdlib.h>

//programa que permita determinar la cantidad de memoria disponible para ese proceso

int main()
{
    int *proceso;
    int contador=0;

    do
    {
        contador++;

    }while(proceso = (int*)malloc(sizeof(int)) != NULL);

    printf("%d\n", contador*sizeof(int));
    return 0;
}
