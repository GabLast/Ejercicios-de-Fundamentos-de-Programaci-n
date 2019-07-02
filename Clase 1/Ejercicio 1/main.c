#include <stdio.h>
#include <stdlib.h>



int main()
{
    int m,n;
    printf("Digitar filas y columnas\n");
    scanf("%d", &m);
    scanf("%d", &n);

    int matriz[m][n];
    int i, j;
    for(i=0; i < m; i++)
    {
        for(j=0; j < n; j++)
        {
            printf("Numero:\n");
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("Matriz:\n");

    for(i = 0; i < m; i++)
    {
        for( j = 0; j < n; j++)
        {
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Inverso de la matriz\n");

    for(j = 0; j < n; j++)
    {
        for( i = 0; i < m; i++)
        {
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
