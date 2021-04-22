/**
2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27 ///DEFINO EL ASCII 27 COMO TECLA A UTILIZAREN TODO EL PROGRAMA

int main()
{
    Pila origen, destino;
    inicpila(&origen);
    inicpila(&destino);

    char opcion;

    /// INICIO CICLO DE CARGA
    do
    {
        leer(&origen); ///LEER UTILIZA UN PRINTF POR SI MISMO
        printf("\n ESC para salir - Presione cualquier tecla para continuar.");
        opcion=getch(); ///LEE UN SOLO CARACTER SIN NECESIDAD DE INTRO (CONIO)
        system("cls"); ///BORRA LA PANTALLA DE LA CONSOLA (STDLIB)
    }
    while(opcion!=ESC);  ///MIENTRAS NO SE PRESIONE ESC..

    /// FIN CICLO DE CARGA

    printf("\n\n Pila origen ....... ");
    mostrar(&origen);

    /// HACEMOS EL PASAJE DE ELEMENTOS DE ORIGEN A DESTINO
    while(!pilavacia(&origen))
    {
        apilar(&destino, desapilar(&origen));
    }

    printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n");

    printf("\n\n Pila origen ....... \n");
    mostrar(&origen);

    printf("\n\n Pila destino ...... \n");
    mostrar(&destino);

    return 0;
}
