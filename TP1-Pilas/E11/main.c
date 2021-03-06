/**
11. Suponiendo la existencia de una pila MODELO que no est? vac?a, eliminar de
la pila DADA todos los elementos que sean iguales al tope de la pila MODELO.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila dada, modelo, aux, basura;
    inicpila(&dada);
    inicpila(&modelo);
    inicpila(&aux);
    inicpila(&basura);
    srand(time(NULL));
    int nro;
    char option;

    ///CARGA DE PILAS CON VALORES RANDOM
    for(int i=0; i<10; i++)
    {
        apilar(&modelo, rand()%20);
    }
    for (int i=0; i<10; i++)
    {
        apilar(&dada, rand()%20);
    }

    ///CARGA DE DATOS POR EL USUARIO CON CONSIGNA
    do
    {
        printf("\n Ingrese una edad:");
        scanf("%d", &nro);
        apilar(&dada, nro);
        printf("\n\n\t ESC para Salir - presione cualquier tecla para continuar. \n");
        option=getch();
        system("cls");
    }
    while(option !=ESC);

    printf("\n Pila Dada:\n");
    mostrar(&dada);
    printf("\n Pila Modelo:\n");
    mostrar(&modelo);

    ///CONDICION DE COMPROBACION DE TOPES Y REDIRECCIONANDO LOS ELEMENTOS REPETIDOS
    if(!pilavacia(&modelo))
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
    }
    while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    printf("\n Pila Dada:\n");
    mostrar(&dada);
    printf("\n Pila Modelo:\n");
    mostrar(&modelo);

    return 0;
}
