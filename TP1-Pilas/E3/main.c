/**
3. Cargar desde teclado una pila DADA y pasar a la pila
DISTINTOS todos aquellos elementos distintos al valor 8.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    srand(time(NULL)); /// Inicializo la semilla para generar numeros random

    Pila DADA, DISTINTOS, OCHOS;
    inicpila(&DADA);
    inicpila(&DISTINTOS);
    inicpila(&OCHOS);

    int limite;
    char opcion;

    limite=rand()%49+1; /// En la variable almaceno de manera aleatoria la cantidad de elementos (0-49)

    for(int i=0; i<limite; i++)
    {
        apilar(&DADA,rand()%15); /// Apilo random entre 0 y 14 en DADA
    }

    do
    {
        leer(&DADA);
        printf("\n\n ESC para salir - Presiona cualquier tecla para continuar.");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    printf("\n\n Pila DADA.....");
    mostrar(&DADA);

    while(!pilavacia(&DADA)) /// recorro la pila dada hasta vaciarla
    {
        if(tope(&DADA)==8)
        {
            apilar(&OCHOS, desapilar(&DADA));  /// desapilo los 8 en la pila OCHOS
        }
        else
        {
            apilar(&DISTINTOS, desapilar(&DADA));  /// desapilo el resto de los numeros en la pila DISTINTOS
        }
    }

    while(!pilavacia(&OCHOS))
    {
        apilar(&DADA, desapilar(&OCHOS)); /// Vuelvo a poner los ochos en la pila DADA
    }

    printf("\n\n Pila DADA.....");
    mostrar(&DADA);

    printf("\n\n Pila DISTINTOS.....");
    mostrar(&DISTINTOS);

    printf("\n\n Pila OCHOS.....");
    mostrar(&OCHOS);

    return 0;
}
