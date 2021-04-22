/**
4. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila origen, destino, aux;
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux);
    char opcion;

    ///CICLO DE CARGA POR USUARIO
    do
    {
        leer(&origen);
        printf("\n\n\t ESC para Salir - Presiona cualquier tecla para continuar.");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    printf("\n\n Pila Origen:\n ");
    mostrar(&origen);

    ///MUEVO EL CONTENIDO DE ORIGEN A AUX Y DE AUX A DESTINO
    while(!pilavacia(&origen))
    {
        apilar(&aux, desapilar(&origen));
    }
    while(!pilavacia(&aux))
    {
        apilar(&destino, desapilar(&aux));
    }

    printf("\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n");
    printf("\n\n Pila Origen:\n ");
    mostrar(&origen);
    printf("\n\n Pila Destino:\n ");
    mostrar(&destino);

    return 0;
}
