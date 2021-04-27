/**
7.	Determinar si un elemento buscado está dentro de una pila.
Al encontrarlo, finalizar la búsqueda.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    srand(time(NULL));
    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);
    int aBuscar;
    char opcion;

    ///CICLO PREVIO DE CARGA CON ELEMENTOS RANDOM
    for(int i=0; i<20; i++)
    {
        apilar(&dada, rand()%50);
    }

    ///CICLO DE CARGA POR EL USUARIO
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

    /// INGRESAMOS EL ELEMENTO A BUSCAR
    printf("\n\n\t Ingrese un numero a buscar en la pila: ");
    scanf("%d",&aBuscar);

    /// RECORREMOS MIENTRAS DADA NO ESTE VACIA Y SU TOPE NO SEA EL VALOR DE BUSQUEDA
    while((!pilavacia(&dada))&&(tope(&dada)!=aBuscar))
    {
        apilar(&aux, desapilar(&dada));
    }

    ///SI NO SE VACIA LA PILA ENTONCES EL ELEMENTO SE ENCUENTRA EN ELLA
    if(!pilavacia(&dada))
    {
        printf("\n\n El elemento %d se encuentra en la pila\n", aBuscar);
    }
    else
    {
        printf("\n\n El elemento %d NO se encuentra en la pila\n", aBuscar);
    }

    ///DEVOLVEMOS LOS ELEMENTOS A DADA
    while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    return 0;
}
