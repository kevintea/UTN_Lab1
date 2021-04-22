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

    ///CARGA PREVIA DE PILA a CON ELEMENTOS RANDOM
    for(int i=0; i<20; i++)
    {
        apilar(&a, rand()%10);
    }

    ///CICLO DE CARGA DE PILA a POR USUARIO
    do
    {
        printf("\n Carga de pila A: \n\n");
        leer(&a);
        printf("\n\n\t ESC para Salir - Presiona cualquier tecla para continuar.\n");
        opcion=getch();
    }
    while(opcion!=ESC);

    ///CARGA PREVIA DE PILA b CON ELEMENTOS RANDOM
    for(int i=0; i<20; i++)
    {
        apilar(&b, rand()%10);
    }

    ///CICLO DE CARGA DE PILA b POR USUARIO
    do
    {
        printf("\n Carga de pila B: \n\n");
        leer(&b);
        printf("\n\n\t ESC para Salir - Presiona cualquier tecla para continuar.\n");
        opcion=getch();
    }
    while(opcion!=ESC);

    ///MUESTRO PILAS CARGADAS
    printf("\n\n Pila A: \n");
    mostrar(&a);

    printf("\n\n Pila B: \n");
    mostrar(&b);

    ///MIENTRAS LAS PILAS NO ESTEN VACIAS Y SUS TOPES SEAN IGUALES
    while((!pilavacia(&a))&&(!pilavacia(&b)))
    {
        apilar(&auxA, desapilar(&a));
        apilar(&auxB, desapilar(&b));
    }

    ///SI AMBAS PILAS ESTAN VACIAS
    ///(SI ALGUNA LO ESTA, QUIERE DECIR QUE NO TIENE LA MISMA CANTIDAD DE ELEMENTOS)
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

    ///DEVUELVO LOS ELEMENTOS A SUS PILAS
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
