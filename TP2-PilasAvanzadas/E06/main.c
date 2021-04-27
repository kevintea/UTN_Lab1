/**
6.	Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra
 de forma tal que la segunda pila quede ordenada de mayor (tope) a menor (base).
  Esto se llama método de ordenación por selección.
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
    Pila dada, aux, menor, ordenada;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&menor);
    inicpila(&ordenada);
    char opcion;

    ///CARGA PREVIA DE PILA CON ELEMENTOS RANDOM
    for(int i=0; i<20; i++)
    {
        apilar(&dada, rand()%50);
    }

    ///CICLO DE CARGA POR USUARIO
    do
    {
        printf("\n Cargando Pila Dada:\n\n");
        leer(&dada);
        printf("\n\n\t ESC para Salir - Presione cualquier tecla para continuar.");
        opcion=getch();
    }
    while(opcion!=ESC);

    printf("\n\n Pila Dada:\n");
    mostrar(&dada);

    ///BUSCAMOS EL MENOR ATRAVEZ DE WHILE DENTRO DE LA PILA
    while(!pilavacia(&dada))
    {
        apilar(&menor, desapilar(&dada));

        while(!pilavacia(&dada))
        {
            if(tope(&dada)<tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&dada));
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
    ///ENCONTRAMOS MENOR Y LO INTRODUCIMOS
        apilar(&ordenada, desapilar(&menor));
    }

    printf("\n\n Pila Dada:\n");
    mostrar(&dada);
    printf("\n\n Pila Ordenada\n:");
    mostrar(&ordenada);

    return 0;
}
