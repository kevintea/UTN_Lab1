/***
4.Encontrar el menor elemento de una pila y guardarlo en otra.
(sin variables, solo pilas).
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h> ///NOS HABILITA EL SRAND PARA GENERAR ELEMENTOS ALEATORIOS
#include "pila.h"

#define ESC 27

int main()
{
    Pila dada, aux, menor;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&menor);
    srand(time(NULL)); ///PARA SEMILLA ALEATORIA UTILIZAMOS ESTA LINEA
    char opcion;

    ///CICLO PREVIO DE CARGA RANDOM
    for(int i=0; i<10; i++)
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

    ///BUSCAMOS EL MENOR ELEMENTO, LO AISLAMOS Y DEVOLVEMOS ELEMENTOS
    if(!pilavacia(&dada))
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
    }

    printf("\n\n Pila Dada:\n");
    mostrar(&dada);
    printf("\n\n El menor elemento de la Pila es: %d\n", tope(&menor));
    return 0;
}
