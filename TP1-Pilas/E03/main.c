/**
3. Cargar desde teclado una pila DADA y pasar a la pila
DISTINTOS todos aquellos elementos distintos al valor 8.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    srand(time(NULL)); ///SEMILLA QUE GENERA ELEMENTO ALEATORIOS (TIME.H)
    Pila DADA, DISTINTOS, OCHOS;
    inicpila(&DADA);
    inicpila(&DISTINTOS);
    inicpila(&OCHOS);
    int limite;
    char opcion;

    limite=rand()%49+1; ///EN LA VARIABLE SE ALMACENARA UN ELEMENTO RANDOM ENTRE 1 Y 50

    ///CICLO PREVIO DE CARGA RANDOM
    for(int i=0; i<limite; i++)
    {
        apilar(&DADA,rand()%15); ///APILO UN ELEMENTO RANDOM ENTRE 0 Y 14
    }

    ///CICLO DE CARGA POR USUARIO
    do
    {
        leer(&DADA);
        printf("\n\n\t ESC para Salir - Presiona cualquier tecla para continuar.");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    printf("\n\n Pila DADA:\n ");
    mostrar(&DADA);

    while(!pilavacia(&DADA)) ///MIENTRAS DADA NO ESTE VACIA
    {
        if(tope(&DADA)==8) ///SI EL TOPE ES 8
        {
            apilar(&OCHOS, desapilar(&DADA)); ///APILO EN PILA OCHOS
        }
        else
        {
            apilar(&DISTINTOS, desapilar(&DADA)); ///DESAPILO EN PILA DISTINTOS
        }
    }

    while(!pilavacia(&OCHOS)) ///MIENTRAS OCHOC NO ESTE VACIA
    {
        apilar(&DADA, desapilar(&OCHOS)); ///APILO EN PILA DADA
    }

    printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n");
    printf("\n\n Pila DADA:\n ");
    mostrar(&DADA);
    printf("\n\n Pila DISTINTOS:\n ");
    mostrar(&DISTINTOS);
    printf("\n\n Pila OCHOS:\n ");
    mostrar(&OCHOS);

    return 0;
}
