/**
8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main()
{
    Pila MAZO, J1, J2;
    inicpila(&MAZO);
    inicpila(&J1);
    inicpila(&J2);
    srand(time(NULL));

    int limite = rand()%50+1; ///LIMITE ALMACENARA NUMERO RANDOM ENTRE 1 Y 50

    for(int i=0; i<limite; i++) ///PARA CUANDO I SEA MENOR A LIMITE / I+1
    {
        apilar(&MAZO,rand()%50+1); ///APILO EN MAZO ELEMENTO ENTRE 1 Y 50 (CANTIDAD LO DEFINE LIMITE)
    }

    printf("\n\n Pila MAZO:\n");
    mostrar(&MAZO);

    while(!pilavacia(&MAZO))   ///MIENTRAS MAZO NO ESTE VACIA
    {
        apilar(&J1, desapilar(&MAZO)); ///APILO EL TOPE DE MAZO EN J1
        if(!pilavacia(&MAZO)) ///SI MAZO AUN NO ESTA VACIA
        {
            apilar(&J2, desapilar(&MAZO)); ///APILO EL TOPE DE MAZO EN J2
        }
    }

    printf("\n Pila MAZO:\n\n");
    mostrar(&MAZO);
    printf("\n Pila J1:\n");
    mostrar(&J1);
    printf("\n Pila J2:\n");
    mostrar(&J2);

    return 0;
}
