/**
1. Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres primeros elementos
a la pila AUX1 y los dos restantes a la pila AUX2, ambas pilas inicializadas en vacío.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila DADA, AUX1, AUX2;
    inicpila(&DADA);
    inicpila(&AUX1);
    inicpila(&AUX2);
    int i;

    ///CICLO DE CARGA DEFINIDO POR USUARIO (5 ELEMENTOS)
    for(i=0; i<5; i++)
    {
        leer(&DADA);
        system("cls");
    }

    ///MOSTRAMOS DADA
    printf("\n Pila DADA: \n");
    mostrar(&DADA);

    i=1; ///INICIALIZAMOS EL CONTADOR
    ///MIETNRAS DADA NO ESTE VACIA I EL CONTADOR SEA MENOR A TRES
    while(!pilavacia(&DADA) && (i<=3))
    {
        apilar(&AUX1, desapilar(&DADA)); ///AUX1 RECIBE TRES ELEMENTOS DE DADA
        i++;
    }

    i=1; ///VUELVO ASIGNAR VALOR 1 AL CONTADOR
    while(!pilavacia(&DADA) && (i<=2))
    {
        apilar(&AUX2, desapilar(&DADA)); ///AUX2 RECIBE DOS ELEMENTOS RESTANTES DE DADA
        i++;
    }

    printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n");

    printf("\n Pila DADA: \n");
    mostrar(&DADA);
    printf("\n Pila AUX1: \n");
    mostrar(&AUX1);
    printf("\n Pila AUX2: \n");
    mostrar(&AUX2);

    return 0;
}
