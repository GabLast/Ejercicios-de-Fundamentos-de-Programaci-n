#include <stdio.h>
#include <stdlib.h>
#include "Colas.h"
#include "conio.c"

typedef enum
{
    Encolar = 1, Decolar = 2, MostrarTodo = 3, Salir = 4
}eOpcionesMenu;

typedef enum
{
    Arriba, Abajo, Izquierda, Derecha, Enter, Ninguno = -1
}eFlechas;

eOpcionesMenu mostrarmenu();
eFlechas capturarFlecha();

int main()
{
    eOpcionesMenu opcionSeleccionada;
    Cola *unaCola = InicializarCola();
    float valores;

    do
    {
        opcionSeleccionada = mostrarmenu();

        switch(opcionSeleccionada)
        {
            case Encolar:
                printf("\nDigite un valor: ");
                scanf("%f", &valores);
                if(valores != -1)
                    enQueue(unaCola, valores);
                break;

            case Decolar:
                if(!isEmpty(unaCola))
                    printf("\n\n%.2f\n", deQueue(unaCola));
                fflush(stdin);
                getch();
                break;

            case MostrarTodo:
                while(!isEmpty(unaCola))
                    printf("\n\n%.2f\n", deQueue(unaCola));
                fflush(stdin);
                getch();
                break;

            case Salir:
                valores = 0;
                break;
        }

    }while(opcionSeleccionada != Salir);


    return 0;
}

eOpcionesMenu mostrarmenu()
{
    eOpcionesMenu seleccion = Encolar;
    _setcursortype(0);
    fflush(stdin);

    do
    {
        textbackground(BLACK);
        clrscr();
        textbackground(seleccion == Encolar ? WHITE : BLACK);
        printf("\t1: Agregar valor.\n");
        textbackground(seleccion == Decolar ? WHITE : BLACK);
        printf("\t2: Mostrar valor.\n");
        textbackground(seleccion == MostrarTodo ? WHITE : BLACK);
        printf("\t3: Mostrar todos los valores.\n");
        textbackground(seleccion == Salir ? WHITE : BLACK);
        printf("\t4: Salir.");


        switch(capturarFlecha())
        {
            case Arriba:
                seleccion == Encolar ? seleccion = Salir : seleccion--;
                break;
            case Abajo:
                seleccion == Salir ? seleccion = Encolar : seleccion++;
                break;
            case Enter:
                return seleccion;
            default:
                continue;
        }
    }while(1);

}

eFlechas capturarFlecha()
{
    fflush(stdin);
    if(getch() == 13)
        return Enter;

    switch(getch())
    {
        case 72:
            return Arriba;
        case 80:
            return Abajo;
        case 77:
            return Derecha;
        case 75:
            return Izquierda;
        default:
            return Ninguno;
    }
    getch();
}
