/**
5.	Insertar un elemento en una pila ordenada de menor.
(tope) a mayor (base) de forma tal que se conserve el orden. (sin variables, solo pilas).
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila ordenada, aux, elemento;
    inicpila(&ordenada);
    inicpila(&aux);
    inicpila(&elemento);
    char opcion;

    ///CARGAMOS MANUALAMENTE UNA PILA ORDENADA
    apilar(&ordenada,7);
    apilar(&ordenada,6);
    apilar(&ordenada,5);
    apilar(&ordenada,4);
    apilar(&ordenada,3);
    apilar(&ordenada,2);
    apilar(&ordenada,1);

    ///INSERTO EL ELEMENTO A ORDENAR
    apilar(&elemento, 5);

    printf("\n\n Pila Ordenada:\n");
    mostrar(&ordenada);

    ///RECORRO LA PILA BUSCAR DONDE UBICAR EL ELEMENTO
    while((!pilavacia(&ordenada))&&(tope(&ordenada)<tope(&elemento)))
    {
        apilar(&aux, desapilar(&ordenada));
    }

    ///INSERTAMOS EL ELEMENTO
    apilar(&ordenada, desapilar(&elemento));

    ///DEVUELVO LOS ELEMENTOS A SU ORDEN ORIGINAL
    while(!pilavacia(&aux))
    {
        apilar(&ordenada, desapilar(&aux));
    }

    printf("\n\n Pila Ordenada:\n");
    mostrar(&ordenada);
    return 0;
}
