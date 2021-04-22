/**
12. Suponiendo la existencia de una pila MODELO (vacía o no),
eliminar de la pila DADA todos los elementos que existan en MODELO.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila dada, modelo, aux, auxmodelo, basura;
    inicpila(&dada);
    inicpila(&modelo);
    inicpila(&aux);
    inicpila(&auxmodelo);
    inicpila(&basura);
    char opcion;

    ///CICLO PREVIO DE CARGA CON ELEMENTOS RANDOM
    for(int i=0; i<20; i++)
    {
        apilar(&modelo, rand()%10);
    }

    ///CICLO DE CARGA POR USUARIO
    do
    {
        printf("\n Cargando Pila Dada:\n\n");
        leer(&dada);
        printf("\n\n\t ESC para Salir - Presione cualquier tecla para continuar.");
        opcion=getch(); ///HABILITA LA UTILIZACION DE UNA TECLA Y NO NECESITA SER CONFIRMADA POR ENTER
        system("cls");
    }
    while(opcion!=ESC);

    ///CICLO PREVIO DE CARGA CON ELEMENTOS RANDOM
    for(int i=0; i<40; i++)
    {
        apilar(&dada, rand()%10);
    }

    printf("\n Pila Dada:\n");
    mostrar(&dada);
    printf("\n Pila Modelo:\n");
    mostrar(&modelo);

    ///MIENTRAS MODELO NO ESTE VACIA BUSCAMOS LOS QUE ESTEN TAMBIEN EN DADA PARA AISLARLOS
    while(!pilavacia(&modelo))
    {
        while(!pilavacia(&dada))
        {
            if(tope(&dada)==tope(&modelo))
            {
                apilar(&basura, desapilar((&dada)));
            }
            else
            {
                apilar(&aux, desapilar(&dada));
            }
        }
        while(!pilavacia(&aux))
        {
            apilar(&dada, desapilar(&aux));
        }
        apilar(&auxmodelo, desapilar(&modelo));
    }

    ///DEVOLVEMOS LOS ELEMENTOS
    while(!pilavacia(&auxmodelo))
    {
        apilar(&modelo, desapilar(&auxmodelo));
    }

    printf("\n Pila Dada:\n");
    mostrar(&dada);
    printf("\n Pila Modelo:\n");
    mostrar(&modelo);

    return 0;
}
