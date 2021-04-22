/**
7. Pasar el último elemento (base) de la pila DADA a su primera
posición (tope), dejando los restantes elementos en el mismo orden.
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
        printf("\n\n\t ESC para Salir - Presione cualquier tecla para continuar. ");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    printf("\n\n Pila Dada:\n ");
    mostrar(&dada);

    while(!pilavacia(&dada)) ///MIENTRAS DADA NO ESTE VACIA
    {
        apilar(&aux, desapilar(&dada)); ///APILO EN AUX LOS ELEMENTOS DE DADA
    }
    if(!pilavacia(&aux)) ///SI AUX NO ESTA VACIA
    {
        apilar(&tope, desapilar(&aux)); ///APILO EL TOPE DE AUX EN PILA TOPE
    }
    while(!pilavacia(&aux)) ///MIENTRAS AUX NO ESTE VACIA
    {
        apilar(&dada, desapilar(&aux)); ///DEVUELVO LOS ELEMENTOS DE AUX A DADA
    }
    if(!pilavacia(&tope)) ///SI TOPE NO ESTA VACIA
    {
        apilar(&dada, desapilar(&tope)); ///APILO EL TOPE DE PILA TOPE EN DADA
    }

    printf("\n\n Pila Dada:\n");
    mostrar(&dada);

    return 0;
}
