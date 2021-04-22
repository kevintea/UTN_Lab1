/**
8.	Eliminar un elemento de una pila. El eliminarlo, finalizar
el recorrido y dejar el resto en el mismo orden.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    srand(time(NULL));
    Pila dada, aux, basura;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&basura);
    int aBorrar;
    char opcion;

    ///CICLO PREVIO DE CARGA RANDOM
    for(int i=0; i<20; i++)
    {
        apilar(&dada, rand()%50);
    }

    ///CICLO DE CARGA POR USUARIO
    do
    {
        printf("\n Cargando Pila Dada:\n\n");
        leer(&dada);
        printf("\n\n\t ESC para Salir - Presione cualquier tecla para continuar.");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    printf("\n\n Pila dada:\n");
    mostrar(&dada);

    /// INGRESAMOS EL VALOR A BUSCAR EN LA PILA
    printf("\n\n\t Ingrese un numero a eliminar de la pila: ");
    scanf("%d",&aBorrar);

    /// RECORREMOS MIENTRAS DADA NO ESTE VACIA Y SU TOPE NO SEA EL VALOR DE BUSQUEDA
    while((!pilavacia(&dada))&&(tope(&dada)!=aBorrar))
    {
        apilar(&aux, desapilar(&dada));
    }

    /// SI LA PILA NO SE VACIO ENTONCES EL ELEMENTO DE BUSQUEDA ES EL TOPE DE DADA
    if(!pilavacia(&dada))
    {
        apilar(&basura, desapilar(&dada));
    }

    ///DEVOLVEMOS LOS ELEMENTOS A DADA
    while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    printf("\n\n Pila Dada:\n");
    mostrar(&dada);

    return 0;
}
