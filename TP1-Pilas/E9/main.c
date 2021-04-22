/**
9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila a, b, auxA, auxB;
    inicpila(&a);
    inicpila(&b);
    inicpila(&auxA);
    inicpila(&auxB);

    char opcion;

    /// Cargo la pila a
    for(int i=0; i<20; i++)
    {
        apilar(&a, rand()%10);
    }

    do
    {
        printf("\n Carga de pila A: \n\n");
        leer(&a);

        printf("\n\n ESC para salir - Presione cualquier tecla para continuar. \n");
        opcion=getch();
    }
    while(opcion!=ESC);

    /// Cargo la pila b
    for(int i=0; i<20; i++)
    {
        apilar(&b, rand()%10);
    }

    do
    {
        printf("\n Carga de pila B: \n\n");
        leer(&b);

        printf("\n\n ESC para salir - Presione cualquier tecla para continuar. \n");
        opcion=getch();
    }
    while(opcion!=ESC);


    /// Muestro el contenido de las pilas
    printf("\n\n Pila A ....... \n");
    mostrar(&a);

    printf("\n\n Pila B ....... \n");
    mostrar(&b);

    /// Recorro las dos pilas juntas mientras no estén vacías
    while((!pilavacia(&a))&&(!pilavacia(&b)))
    {
        apilar(&auxA, desapilar(&a));
        apilar(&auxB, desapilar(&b));
    }

    /// Si se vaciaron al mismo tiempo es que tienen la misma cantidad de elementos
    if((pilavacia(&a))&&(pilavacia(&b)))
    {
        printf("\n\n Las dos pilas tienen la misma cantidad de elementos\n");
    }
    else if(pilavacia(&a))
    {
        printf("\n\n La pila B tiene mas elementos que la pila A\n");
    }
    else
    {
        printf("\n\n La pila A tiene mas elementos que la pila B\n");
    }

    /// vuelvo a poner los datos en sus pilas originales
    while(!pilavacia(&auxA))
    {
        apilar(&a, desapilar(&auxA));
    }

    while(!pilavacia(&auxB))
    {
        apilar(&b, desapilar(&auxB));
    }

    return 0;
}
