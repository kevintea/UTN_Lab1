/**
9.	Verificar si una pila DADA es capicúa.
*/

/**
4.	Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables, solo pilas).
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"
#include "windows.h"

#define ESC 27

int main()
{
    Pila dada, aux, copiaInv, auxCopiaInv;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&copiaInv);
    inicpila(&auxCopiaInv);
    char opcion;

    /// CICLO DE CARGA POR USUARIO
    do
    {
        printf("\n Cargando Pila Dada:\n\n");
        leer(&dada);
        printf("\n\n\t ESC para Salir - Presione cualquier tecla para continuar.");
        opcion=getch();
    }
    while(opcion!=ESC);

    printf("\n\n Pila Dada:\n");
    mostrar(&dada);

    /// HACEMOS COPIA DE DADA EN COPIAINV
    while(!pilavacia(&dada))
    {
        apilar(&copiaInv, tope(&dada));
        apilar(&aux, desapilar(&dada));
    }

    printf("\n\n Pila copiaInv:\n");
    mostrar(&copiaInv);

    /// DEVOLVEMOS LOS ELEMENTOS A DADA
    while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    /// RECORRO DADA Y COPIAINV MIENTRAS NO ESTEN VACIAS Y SUS TOPES NO SEAN IGUALES
    while((!pilavacia(&dada))&&(!pilavacia(&copiaInv))&&(tope(&dada)==tope(&copiaInv)))
    {
        apilar(&aux, desapilar(&dada));
        apilar(&auxCopiaInv, desapilar(&copiaInv));
    }

    /// SI AMBAS ESTAN VACIAS ENTONCES SON CAPICUA
    if((pilavacia(&dada))&&(pilavacia(&copiaInv)))
    {
        printf("\n\n\t La pila Dada es capicua.\n");
    }
    else
    {
        printf("\n\n\t La pila Dada NO es capicua.\n");
    }

    printf("\n\n Pila Dada:\n");
    mostrar(&dada);
    printf("\n\n Pila copiaInv:\n");
    mostrar(&copiaInv);

    return 0;
}
