/**
1. Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres primeros elementos
a la pila AUX1 y los dos restantes a la pila AUX2, ambas pilas inicializadas en vacío.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    int i;
    Pila DADA, AUX1, AUX2;
    inicpila(&DADA);
    inicpila(&AUX1);
    inicpila(&AUX2);

    /// Cargo 5 datos en DADA por teclado
    for(i=0; i<5; i++)
    {
        leer(&DADA);
        system("cls");
    }

    /// Mostramos la pila DADA
    printf("\n Pila DADA..........\n");
    mostrar(&DADA);

    i=0; /// Inicializo el contador
    while(!pilavacia(&DADA) && (i<3))
    {
        apilar(&AUX1, desapilar(&DADA)); /// AUX1 recibe los 3 primeros elementos de DADA
        i++;
    }

    i=0;
    while(!pilavacia(&DADA) && (i<2))
    {
        apilar(&AUX2, desapilar(&DADA)); /// AUX2 recibe los otros 2 elementos de DADA
        i++;
    }

    printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n");

    printf("\n Pila DADA..........\n");
    mostrar(&DADA);

    printf("\n Pila AUX1..........\n");
    mostrar(&AUX1);

    printf("\n Pila AUX2..........\n");
    mostrar(&AUX2);

    return 0;
}
