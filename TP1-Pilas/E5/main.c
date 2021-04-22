/**
5. Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA
contenga los elementos cargados originalmente en ella, pero en orden inverso.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila dada, aux1, aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    char opcion;

    do
    {
        leer(&dada);
        printf("\n\n ESC para salir - Presione cualquier tecla para continuar. ");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    printf("\n\n Pila dada ....... ");
    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        apilar(&aux1, desapilar(&dada));
    }

    while(!pilavacia(&aux1))
    {
        apilar(&aux2, desapilar(&aux1));
    }

    while(!pilavacia(&aux2))
    {
        apilar(&dada, desapilar(&aux2));
    }

    printf("\n\n Pila dada ....... ");
    mostrar(&dada);

    return 0;
}
