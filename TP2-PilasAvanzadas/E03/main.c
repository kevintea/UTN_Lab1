/**
3.	Calcular el promedio de los datos de la pila dada (usar variables).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "pila.h"

#define ESC 27


int main()
{
    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);
    int cont=0;
    int total=0;
    float promedio;
    char opcion;

    ///CICLO DE CARGA POR EL USUARIO
    do
    {
        printf("\n Cargando Pila Dada:\n\n");
        leer(&dada);
        printf("\n\n\t ESC para Salir - Presione cualquier tecla para continuar.");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    printf("\n\n Pila Dada:\n");
    mostrar(&dada);

    ///MIENTRAS DADA NO ESTE VACIA DESAPILAMOS, SUMAMOS SUS ELEMENTOS DESDE EL TOPE
    ///Y CONTABILIZAMOS SUS ELEMENTOS, SACAMOS PROMEDIO
    while(!pilavacia(&dada))
    {
        total=total+tope(&dada);
        apilar(&aux, desapilar(&dada));
        cont++;
    }
    promedio= (float) total/cont;

    ///DEVOLVEMOS ELEMENTOS A DADA
    while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    ///IMPRIMIMOS RESULTADOS
    printf("\n\n Pila Dada:\n\n Cantidad de elementos:  %d \n Sumatoria de elementos: %d \n Promedio de elementos:  %.2f\n\n", cont, total, promedio);
    return 0;
}
