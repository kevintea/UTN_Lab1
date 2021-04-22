/**
1.	Sumar los elementos de una pila (usar variables).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "pila.h"

#define ESC 27


int main()
{
    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);
    int total=0;

    char opcion;

    ///CICLO DE CARGA POR USUARIO
    do
    {
        printf("\n Cargando Pila Dada:\n\n");
        leer(&dada);
        printf("\n\n\t ESC para Salir - Presione cualquier tecla para continuar.");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    printf("\n\n Pila Dada:\n");
    mostrar(&dada);

    ///MIENTRAS DADA NO ESTE VACIA SUMAMOS SUS ELEMENTOS DESAPILANDO SUS TOPES
    while(!pilavacia(&dada))
    {
        total=total+tope(&dada);
        apilar(&aux, desapilar(&dada));
    }
    ///DEVOLVEMOS LOS ELEMENTOS A DADA
    while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    printf("\n\n La suma de los elementos de Dada es: %d\n\n", total);
    return 0;
}
