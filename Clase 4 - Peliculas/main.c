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
void capturarPelicula(Lista *, Nodo *, short);
void explorarPeliculas(Lista *, Nodo *);
void mostrarPeliculaEnColumna(Pelicula, int);
void mostrarSinopsis(int col, int fil, int limite, char *texto);
//Nodo* buscarPorID(Lista *, int);
void modificarPeli(Lista*);
void borrarPelicula(Lista*);
void buscarPeliculaPorAnio(Lista*);
void ordenarPeliculasPorAnio(Lista*);

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
                capturarPelicula(listadoPeliculas, NULL, 0);
                break;
            case Modificar:
                modificarPeli(listadoPeliculas);
                break;
            case Eliminar:
                borrarPelicula(listadoPeliculas);
                break;
            case Insertar:
                capturarPelicula(listadoPeliculas, NULL, 1);
                break;
            case Explorar:
                explorarPeliculas(listadoPeliculas, NULL);
                break;
            case Buscar:
                buscarPeliculaPorAnio(listadoPeliculas);
                break;
            case Ordenar:
                ordenarPeliculasPorAnio(listadoPeliculas);
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

void capturarPelicula(Lista *listado, Nodo *aModificar, short enOrden)
{
    int seleccion, i, j=0;
    short generosSeleccionados[] = {0,0,0,0,0,0,0,0,0};
    Pelicula nuevaPelicula;
    system("cls");
    mostrarMarco();

    gotoxy(10,3);
    if(aModificar == NULL)
        printf("Agregando nueva pel%ccula al final de la lista", 161);
    else
        printf("Modificando Pel%ccula existente.",162);

    gotoxy(5,7);
    printf("ID: ");
    if(aModificar != NULL)
    {
        printf("%d", aModificar->data.id);
    }
    else
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
            printf("Agregando nueva pel%ccula al final de la lista", 161);

            gotoxy(5,7);
            printf("Seleccione los g%cneros de la pel%ccula:", 130, 161);
            gotoxy(5,8);
            printf("1: Acci%cn", 162);
            gotoxy(16,8);
            printf("2: Aventura");
            gotoxy(29, 8);
            printf("3: Comedia");
            gotoxy(5,9);
            printf("4: Drama");
            gotoxy(16,9);
            printf("5: Terror");
            gotoxy(29, 9);
            printf("6: Musical");
            gotoxy(5,10);
            printf("7: Ciencia Ficci%cn", 162);
            gotoxy(25,10);
            printf("8: Suspenso");
            gotoxy(39, 10);
            printf("9: Infantil");
            gotoxy(5,11);
            printf("0: Salir");
            gotoxy(5,12);
            printf("Seleccione: ");
            fflush(stdin);
            seleccion = getch() - 48;
        }while(seleccion < 0 || seleccion > 9);

        if(seleccion != 0 && generosSeleccionados[seleccion - 1] > 0)
        {
            generosSeleccionados[seleccion - 1] = 0;
            j--;
        }else if(seleccion != 0 && generosSeleccionados[seleccion - 1] <= 0)
        {
            generosSeleccionados[seleccion - 1] = 1;
            j++;
        }
    }while(seleccion!=0);

    nuevaPelicula.cantidadGeneros = j;
    nuevaPelicula.generos = (char**)malloc(sizeof(char*)*j);

    for(i = 0, j = 0; i < 9; i++)
    {
        if(generosSeleccionados[i])
        {
            *(nuevaPelicula.generos+j) = (char*)calloc(20,sizeof(char));
            switch(i)
            {
                case 0:
                    strcpy(*(nuevaPelicula.generos+j), "Accion");
                    break;
                case 1:
                    strcpy(*(nuevaPelicula.generos+j), "Aventura");
                    break;
                case 2:
                    strcpy(*(nuevaPelicula.generos+j), "Comedia");
                    break;
                case 3:
                    strcpy(*(nuevaPelicula.generos+j), "Drama");
                    break;
                case 4:
                    strcpy(*(nuevaPelicula.generos+j), "Terror");
                    break;
                case 5:
                    strcpy(*(nuevaPelicula.generos+j), "Musical");
                    break;
                case 6:
                    strcpy(*(nuevaPelicula.generos+j), "Ciencia Ficcion");
                    break;
                case 7:
                    strcpy(*(nuevaPelicula.generos+j), "Suspenso");
                    break;
                case 8:
                    strcpy(*(nuevaPelicula.generos+j), "Infantil");
                    break;

            }
            j++;
        }
    }

    gotoxy(5,15);
    printf("Sinopsis (hasta 200 characteres): ");
    nuevaPelicula.sinopsis = (char*)malloc(200);
    fflush(stdin);
    gets(nuevaPelicula.sinopsis);

    if(aModificar == NULL && !enOrden)
        agregarPeli(nuevaPelicula, listado->cabeza->anterior);
    else if(aModificar == NULL && enOrden)
    {
        Nodo *despuesDe = buscarPeliPorAnyo(listado, nuevaPelicula.anio);
        agregarPeli(nuevaPelicula, despuesDe);
    }
    else
    {
        aModificar->data = nuevaPelicula;
    }
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

void explorarPeliculas(Lista *listado, Nodo *aConsultar)
{
    char seleccion;
    Nodo *nodoActual = (Nodo*)malloc(sizeof(Nodo));

    if(aConsultar == NULL)
        nodoActual = listado->cabeza->siguiente;
    else
        nodoActual = aConsultar;

    do
    {
        if(nodoActual->data.id == -1)
        {
            mostrarMarco();
            gotoxy(2,15);
            printf("No hay pel%culas que mostrar. ",161);
            system("pause");
            break;
        }
        mostrarMarco3Columnas();

        mostrarPeliculaEnColumna(nodoActual->data, 2);

        if(nodoActual->anterior->data.id == -1)
            mostrarPeliculaEnColumna(nodoActual->anterior->anterior->data, 1);
        else
            mostrarPeliculaEnColumna(nodoActual->anterior->data, 1);

        if(nodoActual->siguiente->data.id == -1)
            mostrarPeliculaEnColumna(nodoActual->siguiente->siguiente->data, 3);
        else
            mostrarPeliculaEnColumna(nodoActual->siguiente->data, 3);


        fflush(stdin);
        gotoxy(20,25);
        printf("'X': Salir. 'A': Anterior. 'D': Siguiente.");
        seleccion = getch();

        if(tolower(seleccion) == 'a')
        {
            nodoActual = nodoActual->anterior;
            if(nodoActual->data.id == -1)
                nodoActual = nodoActual->anterior;
        }
        else if(tolower(seleccion) == 'd')
        {
            nodoActual = nodoActual->siguiente;
            if(nodoActual->data.id == -1)
                nodoActual = nodoActual->siguiente;
        }
    }while(tolower(seleccion) != 'x');
}

void mostrarPeliculaEnColumna(Pelicula aMostrar, int numColumna)
{
    int colActual, i = 0;

    if(numColumna <= 1)
        colActual = 1;
    else if(numColumna == 2)
        colActual = COL2;
    else
        colActual = COl3;

    gotoxy(colActual+1, 3);
    printf("ID: %4.4d - %.*s", aMostrar.id, LIMCOLUMNA, aMostrar.titulo);
    gotoxy(colActual+1, 5);
    printf("A%co: %4d", 164, aMostrar.anio);
    gotoxy(colActual +1, 6);
    printf("%.1f/10 - %.1fmins", aMostrar.calificacion, aMostrar.duracion);
    gotoxy(colActual+1, 7);
    printf("Clasif.: %.20s", aMostrar.clasificacion);
    gotoxy(colActual+1, 8);
    printf("G%cneros: ",130);

    while(i < aMostrar.cantidadGeneros)
    {
        gotoxy(colActual+3, 9+i);
        printf("%.*s", LIMCOLUMNA, *(aMostrar.generos+i));
        i++;
    }

    mostrarSinopsis(colActual+1, 10+i, LIMCOLUMNA, aMostrar.sinopsis);
}

void mostrarSinopsis(int col, int fil, int limite, char *texto)
{
    int i = 0, tamano = strlen(texto);
    char *nuevotexto = (char*)malloc(sizeof(char*)*tamano);
    strcpy(nuevotexto, texto);
    while(tamano > 0)
    {
        gotoxy(col, fil+1);
        printf("%.*s", limite, nuevotexto);
        nuevotexto = strcpy(nuevotexto, nuevotexto+limite);
        i++;
        tamano -= limite;
    }
    gotoxy(col, fil+i+1);
}


void modificarPeli(Lista *listadoPeliculas)
{
    int idPeli;
    Nodo *nodoActual;

    system("cls");
    mostrarMarco();
    gotoxy(10,3);
    printf("Modificando Pel%ccula existente", 161);
    gotoxy(5,7);
    printf("Digite el ID de la pel%ccula que desea modificar: ",161);
    scanf("%d", &idPeli);
    nodoActual = buscarPorID(listadoPeliculas, idPeli);

    if(nodoActual == NULL)
    {
        gotoxy(5,9);
        printf("Esta pel%ccula no existe. Presione cualquier letra para continuar...",161);
        fflush(stdin);
        getch();
        return;
    }

    capturarPelicula(listadoPeliculas, nodoActual, 1);
}

void borrarPelicula(Lista *listadoPeliculas)
{
    int idPeli;
    Nodo *nodoActual;

    system("cls");
    mostrarMarco();
    gotoxy(10,3);
    printf("Eliminando una Pel%ccula", 161);
    gotoxy(5,7);
    printf("Digite el ID de la pel%ccula que desea eliminar: ",161);
    scanf("%d", &idPeli);
    nodoActual = buscarPorID(listadoPeliculas, idPeli);

    if(nodoActual == NULL)
    {
        gotoxy(5,9);
        printf("Esta pel%ccula no existe. Presione cualquier letra para continuar",161);
        fflush(stdin);
        getch();
        return;
    }

    eliminarPeli(listadoPeliculas, nodoActual);
}

void buscarPeliculaPorAnio(Lista *listadoPeliculas)
{
    int anio;
    Nodo *nodoActual;

    system("cls");
    mostrarMarco();
    gotoxy(10,3);
    printf("Buscando Pel%ccula existente por a%co", 161,164);
    gotoxy(5,7);

    do
    {
        printf("Digite el a%co de la pel%ccula: ",164, 161);
        scanf("%d", &anio);

        if(anio < 0)
        {
            gotoxy(5,8);
            printf("El a%co no puede ser negativo",164);
        }
    }while(anio<0);

    nodoActual = buscarPeliPorAnyo(listadoPeliculas, anio);

    if(nodoActual->data.id == -1)
    {
        gotoxy(5,9);
        printf("La lista est%c vac%ca. Presione una tecla para continuar...",160,161);
        fflush(stdin);
        getch();
        return;
    }
   explorarPeliculas(listadoPeliculas, nodoActual);
}

void ordenarPeliculasPorAnio(Lista *listadoPeliculas)
{

    ordenarPeliConSeleccion(listadoPeliculas);
    /*Nodo *uno = listadoPeliculas->cabeza->siguiente;
    Nodo *dos = listadoPeliculas->cabeza->anterior;
    printf("\n");
    printf("%d - %s // %d - %s", uno->data.id, uno->data.titulo, dos->data.id, dos->data.titulo);

    intercambiar(uno, dos);

    uno = listadoPeliculas->cabeza->siguiente;
    dos = listadoPeliculas->cabeza->anterior;
    printf("\n\n\n");
    printf("%d - %s // %d - %s", uno->data.id, uno->data.titulo, dos->data.id, dos->data.titulo);

    fflush(stdin);*/
    system("cls");
    gotoxy(4,10);
    system("pause");
}
