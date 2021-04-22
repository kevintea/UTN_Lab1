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

    do{
        leer(&dada);
        printf("\n\n ESC para salir - Presione cualquier tecla para continuar. ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    printf("\n\n Pila dada ....... ");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        apilar(&aux, desapilar(&dada)); /// paso el contenido de la pila dada a la pila aux
    }

    if(!pilavacia(&aux)){
        apilar(&tope, desapilar(&aux)); /// paso el tope de la pila aux (que es el elemento base de la pila dada) a la pila tope
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux)); /// vuelvo a poner todos los datos de aux en dada
    }

    if(!pilavacia(&tope)){
        apilar(&dada, desapilar(&tope)); /// paso el elemento que era la base de dada al tope de la pila dada
    }

    printf("\n\n Pila dada ....... ");
    mostrar(&dada);

    return 0;
}
