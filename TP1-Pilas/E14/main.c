/**
14. Determinar si la cantidad de elementos de la pila DADA es par.
Si es par, pasar el elemento del tope de la pila AUX a la pila
PAR y si es impar pasar el tope a la pila IMPAR.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> ///NOS DEJA UTILIZAR GETCH()
#include <time.h> ///NOS DEJA UTILIZAR SRAND
#include "pila.h"

#define ESC 27

int main()
{
    srand(time(NULL)); ///NOS DEJA GENERAR UNA SEMILLA ALEATORIA
    Pila dada, aux, par, impar;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&par);
    inicpila(&impar);

    char opcion;

    ///CICLO PREVIO DE CARGA CON ELEMENTOS RANDOM
    for(int i=0; i<15; i++)
    {
        apilar(&dada, rand()%10); ///RAND GENERA ELEMENTOS RANDOM BASADOS EN EL RANGO IMPUESTO
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

    printf("\n\n Pila Dada:\n");
    mostrar(&dada);

    ///MIENTRAS DADA NO ESTE VACIA VERIFICAMOS LA CONDICION DE DADA
    while(!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));
        if(!pilavacia(&dada))
        {
            apilar(&aux, desapilar(&dada));
        }
        else
        {
            apilar(&impar, desapilar(&aux));
        }
    }

    ///SI PILA IMPAR NO ESTA VACIA ENTONCES DADA ES IMPAR SINO ES PAR
    if(!pilavacia(&impar))
    {
        printf("\n\n La pila Dada tiene cantidad de datos impares.\n");
    }
    else
    {
        apilar(&par, desapilar(&aux));
        printf("\n\n La pila Dada tiene cantidad de datos pares.\n");
    }

    ///DEVOLVEMOS LOS ELEMENTOS
    while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    return 0;
}
