#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "listaDobleCircular.h"


typedef enum
{
    Salir = 0,
    Agregar,
    Modificar,
    Eliminar,
    Insertar,
    Explorar,
    Buscar,
    Ordenar
}eSeleccionMenu;

eSeleccionMenu mostrarMenu();
void mostrarMarco();
void mostrarMarco3Columnas();
void agregarNuevaPeli(Lista *);
void explorarPeliculas(Lista *);
void mostrarPeliculaEnColumna(Pelicula, int);
void mostrarSinopsis(int col, int fil, int limite, char *texto);

const int COL2 = 26, COl3 = 51, LIMCOLUMNA = 24;

int main()
{
    Lista *listadoPeliculas = InicializarLista();
    eSeleccionMenu opcionActual;

    do
    {
        opcionActual = mostrarMenu();

        switch(opcionActual)
        {
            case Agregar:
                agregarNuevaPeli(listadoPeliculas);
                break;
            case Modificar:
                break;
            case Eliminar:
                break;
            case Insertar:
                break;
            case Explorar:
                explorarPeliculas(listadoPeliculas);
                break;
            case Buscar:
                break;
            case Ordenar:
                break;
        }

    }while(opcionActual != Salir);


    return 0;
}

void mostrarMarco()
{
    int i;

    system("cls");
    //Bloque del titulo
    printf("%c", 201); //Esquina superior izquierda
    for(i=0; i<63; i++)
    {
        printf("%c", 205); // Lineas horizontales
    }
    printf("%c\n", 187); // Esquina superior derecha


    //Titulo espacio

    for(i =0; i<3; i++)
    {
        printf("%c\t\t\t\t\t\t\t\t%c\n", 186,186); //Laterales
    }

    //Separador del bloque del titulo
    printf("%c", 204); //Esquina superior izquierda
    for(i=0; i<63; i++)
    {
        printf("%c", 205); // Lineas horizontales
    }
    printf("%c\n", 185); // Esquina superior derecha
    //-------------------------------------------

    for(i =0; i<18; i++)
    {
        printf("%c\t\t\t\t\t\t\t\t%c\n", 186,186); //Laterales
    }
    printf("%c", 200); //Esquina inferior izquierda

    for(i=0; i<63; i++)
    {
        printf("%c", 205); // Lineas horizontales
    }
    printf("%c\n", 188); // Esquina inferior derecha
}

eSeleccionMenu mostrarMenu()
{
    int seleccion;

    do
    {
        mostrarMarco();
        gotoxy(25,3);
        printf("Gesti%cn de Pel%cculas", 162, 161);
        gotoxy(5,7);
        printf("1: Agregar una pel%ccula al final", 161);
        gotoxy(5,9);
        printf("2: Modificar una pel%ccula dado un ID", 161);
        gotoxy(5,11);
        printf("3: Eliminar una pel%ccula dado un ID", 161);
        gotoxy(5,13);
        printf("4: Agregar una pel%ccula en orden de a%co", 161,164);
        gotoxy(5,15);
        printf("5: Explorar las pel%ccula registradas", 161);
        gotoxy(5,17);
        printf("6: Buscar una pel%ccula por a%co", 161,164);
        gotoxy(5,19);
        printf("7: Ordenar las pel%ccula registradas", 161);
        gotoxy(5,22);
        printf("0: Salir de la aplicaci%cn", 162);

        fflush(stdin);
        _setcursortype(0);
        seleccion = getch() - 48;

    }while(seleccion < 0 || seleccion > 7);

    _setcursortype(1);

    return seleccion;
}

void agregarNuevaPeli(Lista *listado)
{
    int seleccion, i, contadorNumGeneros=0;
    short generosSeleccionados[] = {0,0,0,0,0,0,0,0,0};
    Pelicula nuevaPelicula;
    system("cls");
    mostrarMarco();
    gotoxy(10,3);
    printf("Agregando nueva pel%ccula al final de la lista", 163);
    gotoxy(5,7);
    printf("ID: ");
    scanf("%d", &nuevaPelicula.id);

    gotoxy(5,9);
    printf("T%ctulo: ",161);
    nuevaPelicula.titulo = (char*)malloc(100);
    fflush(stdin);
    gets(nuevaPelicula.titulo);

    gotoxy(5,11);
    printf("A%co: ",164);
    scanf("%d", &nuevaPelicula.anio);

    //clasificacion
    gotoxy(5, 13);
    do
    {
        printf("Seleccione una clasificaci%cn:", 162);
        gotoxy(5, 14);
        printf("1: G (Prop%csito General)",162);
        gotoxy(5, 15);
        printf("2: PG (Supervisi%cn Parental)",162);
        gotoxy(5,16);
        printf("3: PG-13 (No apto para menores de 13 a%cos)", 164);
        gotoxy(5,17);
        printf("4: R (Restringido para mayores de edad)");
        gotoxy(5,18);
        printf("5: NC-17 (Solo adultos)");
        gotoxy(5,19);
        printf("Seleccione: ");
        seleccion = getch() - 48;

    }while(seleccion < 0 || seleccion > 7);

    nuevaPelicula.clasificacion = (char*)calloc(6, sizeof(char));

    switch(seleccion)
    {
        case 1:
            strcpy(nuevaPelicula.clasificacion, "G");
            break;
        case 2:
            strcpy(nuevaPelicula.clasificacion, "PG");
            break;
        case 3:
            strcpy(nuevaPelicula.clasificacion, "PG-13");
            break;
        case 4:
            strcpy(nuevaPelicula.clasificacion, "R");
            break;
        case 5:
            strcpy(nuevaPelicula.clasificacion, "NC-17");
            break;
    }
    gotoxy(5,21);
    printf("Calificaci%cn: ", 162);
    scanf("%f", &nuevaPelicula.calificacion);

    gotoxy(5,23);
    printf("Duraci%cn: ",162);
    scanf("%f", &nuevaPelicula.duracion);

    //Mostrando los Generos
    do
    {
        do
        {
            system("cls");
            mostrarMarco();
            gotoxy(10,3);
            printf("Agregando nueva pel%ccula al final de la lista", 163);

            gotoxy(5,7);
            printf("Seleccione los g%cneros de la pel%ccula:", 130, 161);
            gotoxy(5,8);
            printf("1: Acci%cn", 162);
            gotoxy(14,8);
            printf("2: Aventura");
            gotoxy(25, 8);
            printf("3: Comedia");
            gotoxy(5,9);
            printf("4: Drama");
            gotoxy(14,9);
            printf("5: Terror");
            gotoxy(18, 9);
            printf("6: Musical");
            gotoxy(5,10);
            printf("7: Ciencia Ficci%cn", 168);
            gotoxy(14,10);
            printf("8: Suspenso");
            gotoxy(5, 10);
            printf("9: Infantil");
            gotoxy(14,10);
            printf("0: Salir");
            gotoxy(5,12);
            printf("Seleccione: ");
            fflush(stdin);
            seleccion = getch() - 48;
        }while(seleccion < 0 || seleccion > 9);

        if(seleccion != 0)
            generosSeleccionados[seleccion - 1] = generosSeleccionados[seleccion - 1] > 0 ? 0 : 1;

    }while(seleccion!=0);

    //simplemente inicializa la matriz para que realloc no de problemas
    nuevaPelicula.generos = (char**)malloc(sizeof(char*));

    for(i = 0; i < 9; i++)
    {
        if(generosSeleccionados[i])
        {
            contadorNumGeneros++;
            nuevaPelicula.generos = (char**)realloc(nuevaPelicula.generos, contadorNumGeneros);
            *(nuevaPelicula.generos+contadorNumGeneros) = (char*)calloc(20,sizeof(char));
            switch(i)
            {
                case 0:
                    strcpy(*(nuevaPelicula.generos+contadorNumGeneros), "Accion");
                    break;
                case 1:
                    strcpy(*(nuevaPelicula.generos+contadorNumGeneros), "Aventura");
                    break;
                case 2:
                    strcpy(*(nuevaPelicula.generos+contadorNumGeneros), "Comedia");
                    break;
                case 3:
                    strcpy(*(nuevaPelicula.generos+contadorNumGeneros), "Drama");
                    break;
                case 4:
                    strcpy(*(nuevaPelicula.generos+contadorNumGeneros), "Terror");
                    break;
                case 5:
                    strcpy(*(nuevaPelicula.generos+contadorNumGeneros), "Musical");
                    break;
                case 6:
                    strcpy(*(nuevaPelicula.generos+contadorNumGeneros), "Ciencia Ficcion");
                    break;
                case 7:
                    strcpy(*(nuevaPelicula.generos+contadorNumGeneros), "Suspenso");
                    break;
                case 8:
                    strcpy(*(nuevaPelicula.generos+contadorNumGeneros), "Infantil");
                    break;

            }
        }
    }

    //----------------------------------------------------

    printf("\n\tSinopsis (hasta 200 characteres): ");
    nuevaPelicula.sinopsis = (char*)malloc(200);
    fflush(stdin);
    gets(nuevaPelicula.sinopsis);

    agregarPeli(listado, nuevaPelicula);
}

void mostrarMarco3Columnas()
{
    int i;

    system("cls");
    //Bloque del titulo
    printf("%c", 201); //Esquina superior izquierda
    for(i=0; i<24; i++)
        printf("%c", 205); // Lineas horizontales
    printf("%c", 203);
    for(i=0; i<24; i++)
        printf("%c", 205); // Lineas horizontales
    printf("%c", 203);
    for(i=0; i<24; i++)
        printf("%c", 205); // Lineas horizontales
    printf("%c\n", 187); //esquina superior derecha


    for(i =2; i<24; i++)
    {
        gotoxy(0,i);
        printf("%c", 186);
        gotoxy(26,i);
        printf("%c", 186);
        gotoxy(51,i);
        printf("%c", 186);
        gotoxy(77,i);
        printf("%c", 186);
    }

    printf("%c", 200); //Esquina inferior izquierda

    for(i=0; i<24; i++)
        printf("%c", 205); // Lineas horizontales
    printf("%c", 202);
    for(i=0; i<24; i++)
        printf("%c", 205); // Lineas horizontales
    printf("%c", 202);
    for(i=0; i<24; i++)
        printf("%c", 205); // Lineas horizontales
    printf("%c\n", 188); // Esquina inferior derecha

}

void explorarPeliculas(Lista *listado)
{
    char seleccion;

    Nodo *nodoActual = listado->cabeza->siguiente;

    do
    {
        mostrarMarco3Columnas();
        if(nodoActual->data.id == -1)
        {
            printf("No hay pel%culas que mostrar",161);
            break;
        }
        mostrarPeliculaEnColumna(nodoActual->data, 2);
    }while(tolower(seleccion) != 'x');

}

void mostrarPeliculaEnColumna(Pelicula aMostrar, int numColumna)
{
    int colActual, i = 0;

    if(numColumna ==1)
        colActual = 0;
    else if(numColumna ==2)
        colActual = COL2;
    else
        colActual = COl3;

    gotoxy(colActual+1, 3);
    printf("%4.4d - %.*s\n",aMostrar.id, LIMCOLUMNA, aMostrar.titulo);
    gotoxy(colActual+1, 5);
    printf("%4d - %.1f/10 - %.1fmins", aMostrar.anio, aMostrar.calificacion, aMostrar.duracion);
    gotoxy(colActual+1, 7);

    printf("Clasif.: %.20s", aMostrar.clasificacion);
    gotoxy(colActual+1, 9);
    while(aMostrar.generos+i != EOF)
    {
        printf(".*s", LIMCOLUMNA, *(aMostrar.generos+1));
        i++;
        gotoxy(colActual+1, 9+i);
    }

    mostrarSinopsis(colActual+1, 10+i, LIMCOLUMNA, aMostrar.sinopsis);
}

void mostrarSinopsis(int col, int fil, int limite, char *texto)
{
    int i = 0;
    while(strlen(texto) > 0)
    {
        gotoxy(col, fil+1);
        printf("%.*s", limite, texto);
        texto = strcpy(texto, texto+limite); //texto += limite;
        i++;
    }
}
