#include <stdio.h>
#include <stdlib.h>

const int DIM = 9, MAX = 9;

void capturarMatriz(short matrizSudoku[DIM][DIM]);
void mostrarMatriz(short matrizSudoku[DIM][DIM]);
short resolverSudoku(short matrizSudoku[DIM][DIM]);
short resolverSudokuBackTracking(short matrizSudoku[DIM][DIM], int, int);
short esValido(short matrizSudoku[DIM][DIM], int ,int);


int main()
{


    short matrizSudoku[9][9] = {{0, 0, 0, 0, 0, 0, 0, 2, 0},
                                {0, 0, 0, 0, 0, 0, 8, 0, 0},
                                {0, 1, 5, 0, 6, 0, 3, 0, 0},
                                {1, 0, 2, 0, 9, 0, 5, 0, 0},
                                {0, 0, 9, 0, 0, 0, 0, 0, 4},
                                {4, 0, 0, 0, 5, 0, 0, 0, 0},
                                {0, 0, 4, 5, 0, 0, 0, 7, 0},
                                {0, 0, 0, 8, 0, 6, 0, 1, 0},
                                {0, 3, 0, 0, 0, 2, 0, 5, 0}};

    //capturarMatriz(matrizSudoku);
    printf("Sudoku sin resolver:\n\n");
    mostrarMatriz(matrizSudoku);

    if(!resolverSudoku(matrizSudoku))
    {
        printf("\nSudoku no es valido.\n");
    }else
    {
        printf("\n\nSudoku resuelto:\n\n");
        mostrarMatriz(matrizSudoku);
    }

    return 0;
}

void capturarMatriz(short matrizSudoku[DIM][DIM])
{
    int i, j;

    for(i=0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            printf("[%d,%d]", i+1, j+1);
            scanf("%d", &matrizSudoku[i][j]);
        }
    }
}

void mostrarMatriz(short matrizSudoku[DIM][DIM])
{
    int i, j;

    for(i = 0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            printf(" %d\t", matrizSudoku[i][j]);
        }
        printf("\n");
    }
}

short resolverSudoku(short matrizSudoku[DIM][DIM])
{
    return resolverSudokuBackTracking(matrizSudoku, 0, 0);
}

short resolverSudokuBackTracking(short matrizSudoku[DIM][DIM], int x, int y)
{
    int tanteoActual;
    if(y >= DIM)
        return 1;

    if(x >= DIM)
        return resolverSudokuBackTracking(matrizSudoku, 0, y+1);

    if(matrizSudoku[y][x] != 0)
        return resolverSudokuBackTracking(matrizSudoku, x+1, y);

    for(tanteoActual = 1; tanteoActual <= DIM; tanteoActual++)
    {
        matrizSudoku[y][x] = tanteoActual;

        if(esValido(matrizSudoku, x, y))
        {
            if(resolverSudokuBackTracking(matrizSudoku, x+1, y))
                return 1;
        }
    }

    matrizSudoku[y][x] = 0;

    return 0;
}

short esValido(short matrizSudoku[DIM][DIM], int x, int y)
{
    int i, j;
    short encontrado;

    // Fila
    encontrado = 0;
    for(i = 0; i < DIM; i++) //fila se queda constante mientras que se revisan las columnas
        encontrado += matrizSudoku[y][i] == matrizSudoku[y][x] ? 1 : 0;
    if(encontrado > 1)
        return 0;

    // Columna
    encontrado = 0;
    for(i = 0; i < DIM; i++) //columna se queda constante mientras que se revisan las columnas
        encontrado += matrizSudoku[i][x] == matrizSudoku[y][x] ? 1 : 0;
    if(encontrado > 1)
        return 0;

    //Sub-bloque
    encontrado = 0;
    for(i = y - (y % 3); i < (y -(y % 3) + 3) ; i++)
    {
        for(j = x- (x % 3); j < (x -(x % 3) + 3) ; j++)
        {
            encontrado += matrizSudoku[i][j] == matrizSudoku[y][x] ? 1 : 0;
        }
    }
    if(encontrado > 1)
        return 0;

    return 1;
}
