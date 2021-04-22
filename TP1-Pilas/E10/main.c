/**
10. Comparar las pilas A y B, evaluando si son completamente iguales (en cantidad de elementos,
valores que contienen y posici�n de los mismos). Mostrar por pantalla el resultado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila a, b, auxA, auxB;
    inicpila(&a);
    inicpila(&b);
    inicpila(&auxA);
    inicpila(&auxB);

    char opcion;

    /// CARGA DE A POR USUARIO
    do
    {
        printf("\n Carga pila A \n");
        leer(&a);

        printf("\n\n ESC para salir - presione cualquier tecla para continuar ");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    /// CARGA DE B POR USUARIO
    do
    {
        printf("\n Carga pila B \n");
        leer(&b);

        printf("\n\n ESC para salir - presione cualquier tecla para continuar ");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    /// MUESTRO LOS VALORES
    printf("\n\n Pila A ");
    mostrar(&a);

    printf("\n\n Pila B ");
    mostrar(&b);

    /// RECORRO LOS VALORES BUSCANDO LA IGUALDAD EN TOPES Y MIENTRAS NO ESTEN VACIAS
    while((!pilavacia(&a))&&(!pilavacia(&b))&&(tope(&a)==tope(&b)))
    {
        apilar(&auxA, desapilar(&a));
        apilar(&auxB, desapilar(&b));
    }

    /// SI SE VACIARON JUNTAS SON IGUALES
    if((pilavacia(&a))&&(pilavacia(&b)))
    {
        printf("\n\n Las pilas son iguales\n");
    }
    else
    {
        printf("\n\n Las pilas NO son iguales\n");
    }

    /// DEVUELVO LOS VALORES A SU ESTADO ORIGINAL
    while(!pilavacia(&auxA))
    {
        apilar(&a, desapilar(&auxA));
    }

    while(!pilavacia(&auxB))
    {
        apilar(&b, desapilar(&auxB));
    }
    return 0;
}
