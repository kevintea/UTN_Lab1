/**
13. Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila
DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES,
y los elementos que sean menores a la pila MENORES.
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
    Pila dada, limite, mayores, menores, basuralimite;
    inicpila(&dada);
    inicpila(&limite);
    inicpila(&mayores);
    inicpila(&menores);

    char opcion;

    ///CARGAMOS PILA DADA

    for(int i=0; i<20; i++)
    {
        apilar(&dada, rand()%10);
    }

    do
    {
        printf(" Cargando Dada..\n");
        leer(&dada);

        printf("\n ESC para salir - Presione cualquier tecla para continuar..\n\n");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    /// CARGAMOS PILA LIMITE

    for(int i=0; i<20; i++)
    {
        apilar(&limite, rand()%20);
    }
    do
    {
        printf(" Cargando Limite..\n");
        leer(&limite);

        printf("\n ESC para salir - Presione cuaquier tecla para continuar..\n\n");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    printf(" Pila DADA...\n");
    mostrar(&dada);
    printf(" Pila  Limite..\n");
    mostrar(&limite);

    while(!pilavacia(&dada))
    {
        if(tope(&dada)>tope(&limite))
        {
            apilar(&mayores, desapilar(&dada));
        }
        else
        {
            apilar(&menores, desapilar(&dada));
        }
    }

    printf("\n\n Pila Dada..");
    mostrar(&dada);

    printf("\n\n Pila Limite..");
    mostrar(&limite);

    printf("\n\n Pila Mayores..");
    mostrar(&mayores);

    printf("\n\n Pila Menores..");
    mostrar(&menores);
    return 0;
}
