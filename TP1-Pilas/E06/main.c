/**
6. Pasar el primer elemento (tope) de la pila DADA a su última
posición (base), dejando los restantes elementos en el mismo orden.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila dada, tope, aux;
    inicpila(&dada);
    inicpila(&tope);
    inicpila(&aux);
    char opcion;

    ///CICLO DE CARGA POR USUARIO
    do
    {
        leer(&dada);
        printf("\n\n\t ESC para Salir - Presiona cualquier tecla para continuar.");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    printf("\n\n Pila Dada:\n ");
    mostrar(&dada);

    if(!pilavacia(&dada))  ///SI DADA NO ESTA VACIA
    {
        apilar(&tope, desapilar(&dada)); ///APILO EL TOPE DE DADA EN PILA TOPE
        while(!pilavacia(&dada)) ///MIENTRAS DADA NO ESTE VACIA
        {
            apilar(&aux, desapilar(&dada)); ///APILO LOS ELEMENTOS RESTANTES DE DADA EN AUX
        }
        if(!pilavacia(&tope)) ///SI TOPE NO ESTA VACIA
        {
            apilar(&dada, desapilar(&tope)); ///APILO EL TOPE DE PILA TOPE EN DADA
        }
        while(!pilavacia(&aux)) ///MIENTRAS AUX NO ESTE VACIA
        {
            apilar(&dada, desapilar(&aux)); ///APILO LOS ELEMENTOS DE AUX EN DADA
        }
    }

    printf("\n\n Pila Dada:\n ");
    mostrar(&dada);

    return 0;
}
