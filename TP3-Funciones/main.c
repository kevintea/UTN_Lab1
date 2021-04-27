///NOTA: EN CADA CASE DEVUELVO LOS ELEMENTOS A LA PILA "PILAMAIN"
///PARA QUE EL USUARIO PUEDA UTILIZAR TODAS LAS CONSIGNAS
///DEL MODO QUE DESEE SIN PERDER DATOS U ORDEN EN CADA UNO DE LOS CASOS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27


///DECLARAMOS PROTOTIPADOS
///TIPO DE DATO A RETORNAR, NOMBRE DE LA FUNCION(QUE SEA ENTENDIBLE)
///TIPO DE VARIABLE - SI VA SER PUNTERO O COPIA -

//void cargarPilaRandom (Pila* puntAPilamain);

void cargarPila(Pila* puntAPilamain);

void pasajePila(Pila* puntAPilamain, Pila* puntAAux);

void pasajePilaNoInversa(Pila* puntAPilamain, Pila* puntAAux);

int buscaMenor(Pila* puntAPilamain); ///FUNCION QUE RETORNA INT

void pilaOrdenada(Pila* puntAPilamain, Pila* puntAAux);

void insertarAPila(Pila* puntAPilamain, Pila* puntAAux, int nuevo);

void insertarAPilaInversa(Pila* puntAPilamain, Pila* puntAAux, int nuevo);

int sumarTopeAnterior(Pila copiaAPilamain); ///FUNCION POR VALOR (COPIA), NO UTILIZAMOS * EN EL PROTOTIPADO NI EN LA CABECERA, DENTRO LA FUNCION UTILIZAMOS &

float promedioPila(Pila copiaAPilamain); ///FUNCION POR VALOR, RETORNA FLOAT

int pilaADecimal(Pila copiaAPilamain); ///FUNCION POR VALOR, RETORNA INT


int main()
{
    Pila pilamain, aux;
    inicpila(&pilamain);
    inicpila(&aux);

    int menor;
    int nuevo;
    int suma;
    int inciso;
    float promedio;
    int decimal;
    char opcion;

    do
    {
        printf("\n\t\t\t Bienvenidos al MENU PRINCIPAL del Trabajo Practico 3: Funciones \n\n");
//        printf(" 0-  Cargamos la pila de manera aleatoria\n");
        printf(" 1-  Cargamos la Pila manualmente\n");
        printf(" 2-  Pasamos todos los elementos de la pila a otra\n");
        printf(" 3-  Pasamos todos los elementos de la pila a otra, pero conservando el orden\n");
        printf(" 4-  Buscamos el menor elemento de la pila y lo retornamos\n");
        printf(" 5-  Generamos una pila ordenada\n");
        printf(" 6-  Insertamos en una pila ordenada un nuevo elemento, conservando el orden de la pila\n");
        printf(" 7-  Insertamos en una pila ordenada un nuevo elemento y los pasamos de una pila a otra,\n     de manera que se genere una nueva pila ordenada\n");
        printf(" 8-  Sumar y retornar los dos primeros elementos de la pila\n");
        printf(" 9-  Calcular el promedio de los elementos de la pila\n");
        printf(" 10- Mostrar los elementos de la pila en formato decimal (SOLO ELEMENTOS DE UN DIGITO)\n");

        printf("\n\n Seleccione uno de los incisos: ");
        scanf("%d", &inciso);

        switch(inciso)
        {
//            case 0:
//            {
//
//            }
        case 1:
            cargarPila(&pilamain);
            mostrar(&pilamain);
            break;

        case 2:
            pasajePila(&pilamain, &aux);
            pasajePilaNoInversa(&aux, &pilamain);
            mostrar(&pilamain);
            break;

        case 3:
            pasajePilaNoInversa(&pilamain, &aux);
            pasajePilaNoInversa(&aux, &pilamain);
            mostrar(&pilamain);
            break;

        case 4:
            if(pilavacia(&pilamain))
            {
                printf("\n La pila no tiene elementos!");
            }
            else
            {
                menor = buscaMenor(&pilamain);
                printf("\n El menor elemento de la Pila fue: %d\n\n", menor); ///ESTE VALOR FUE ELIMINADO DE LA PILA
                mostrar(&pilamain);
            }
            break;

        case 5:
            pilaOrdenada(&pilamain, &aux);
            printf("\n\n Pila ordenada:\n");
            pasajePilaNoInversa(&aux, &pilamain);
            mostrar(&pilamain);
            break;

        case 6:
            printf("\n\n Ingrese elemento a insertar: ");
            scanf("%d", &nuevo);
            insertarAPila(&pilamain, &aux, nuevo);
            mostrar(&pilamain);
            break;

        case 7:
            printf("\n\n Ingrese elemento a insertar: ");
            scanf("%d", &nuevo);
            insertarAPilaInversa(&pilamain, &aux, nuevo);
            pasajePilaNoInversa(&aux, &pilamain);
            mostrar(&pilamain);
            break;

        case 8:
            if(pilavacia(&pilamain))
            {
                printf("\n La pila no tiene elementos!");
            }
            else
            {
                suma =sumarTopeAnterior(pilamain); ///AL UTILIZAR FUNCIONES POR VALORES NO LLAMAMOS A LAS PILAS CON EL &
                printf("\n\n La suma del tope y su antecedente es: %d \n", suma);
            }
            break;

        case 9:
            promedio =promedioPila(pilamain);
            if(!pilavacia(&pilamain)&&promedio!=0)
            {
               printf("\n\n El promedio de los elementos de la pila es: %.2f \n", promedio);
            }
            else
            {
                printf("\n\n La pila no tiene elementos calculables!");
            }
            break;

        case 10:
            decimal =pilaADecimal(pilamain);
            printf("\n\n Pila:\n");
            mostrar(&pilamain);
            printf("\n\n El formato decimal de los elementos de la Pila es: %d \n", decimal);
            break;

        }
        printf("\n\n\t ESC para Terminar - Presione cualquier tecla para volver al Menu.");
        fflush(stdin);
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);

    return 0;
}

void cargarPila(Pila* puntAPilamain) ///CICLO DE CARGA POR USUARIO TOMANDO PUNTERO PILA
{
    char opcion;

    do
    {
        system("cls");
        printf("\n Cargando Pila:\n\n");
        leer(puntAPilamain);
        printf("\n\n\t ESC para Salir - Presione cualquier tecla para continuar.");
        opcion=getch();
        system("cls");
    }
    while(opcion!=ESC);
}

void pasajePila(Pila* puntAPilamain, Pila* puntAAux) ///CICLO PASAJE DE ELEMENTOS - PUNTERO AMBAS
{
    while(!pilavacia(puntAPilamain)) ///SI USO PUNTERO NO PONGO LOS & EN LAS PILAS YA QUE YA LABURO SOBRE ELLAS
    {
        apilar(puntAAux, desapilar(puntAPilamain));
    }
}

void pasajePilaNoInversa(Pila* puntAPilamain, Pila* puntAAux) ///CICLO PASAJE DE ELEMENTOS MANTENIENDO EL ORDEN - PUNTERO DE AMBAS
{
    Pila aux2;
    inicpila(&aux2);
    pasajePila(puntAPilamain, &aux2); /// REUTILIZAMOS FUNCIONES ANTERIORES
    pasajePila(&aux2, puntAAux); /// REUTILIZAMOS FUNCIONES ANTERIORES
}

int buscaMenor(Pila* puntAPilamain) ///BUSCA EL MENOR, LO AISLAMOS DE LA PILA Y LO RETORNAMOS (INT) - PUNTERO DE PILAMAIN
{
    Pila  menor, aux; ///DECLARO PILAS QUE SOLO QUEDARAN PARA LA FUNCION
    inicpila(&aux);
    inicpila(&menor);

    if(!pilavacia(puntAPilamain)) ///SI LA PILA NO ESTA VACIA
    {
        apilar(&menor, desapilar(puntAPilamain));

        while(!pilavacia(puntAPilamain))
        {
            if(tope(puntAPilamain)<tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(puntAPilamain));
            }
            else
            {
                apilar(&aux, desapilar(puntAPilamain));
            }
        }
        pasajePila(&aux, puntAPilamain); ///REUTILIZAMOS FUNCIONES ANTERIORES
        return tope(&menor); ///RETORNAMOS EL TOPE DE MENOR QUE FUE EL MENOR ELEMENTO DE LA PILA
    }
    else
    {
        return 0;
    }
}

void pilaOrdenada(Pila* puntAPilamain, Pila* puntAAux) ///ORDENA LA PILA DE MAYOR A MENOR - PUNTERO DE AMBAS
{
    Pila ordenada;
    inicpila(&ordenada);

    while(!pilavacia(puntAPilamain))
    {
        apilar(&ordenada, buscaMenor(puntAPilamain)); ///REUTILIZAMOS FUNCIONES PARA EL RECORRIDO DE LA ORDENADA
    }
    pasajePila(&ordenada, puntAAux); ///REUTILIZAMOS FUNCIONES PARA DEVOLVER LA PILA INVERTIDA
}

void insertarAPila(Pila* puntAPilamain, Pila* puntAAux, int nuevo) ///INSERTA VALOR Y ORDENAMOS - PUNTERO DE AMBAS Y UNA VARIABLE POR VALOR
{
    Pila aux2;
    inicpila(&aux2);
    apilar(puntAPilamain, nuevo);
    pilaOrdenada(puntAPilamain, puntAAux);
    pasajePilaNoInversa(puntAAux, puntAPilamain);
}

void insertarAPilaInversa(Pila* puntAPilamain, Pila* puntAAux, int nuevo) ///INSERTA VALOR, ORDENAMOS Y PASAMOS DE PILA - PUNTERO DE AMBAS Y UNA VARIABLE POR VALOR
{
    insertarAPila(puntAPilamain, puntAAux, nuevo);
    pasajePila(puntAPilamain, puntAAux);
}

int sumarTopeAnterior(Pila copiaAPilamain) ///SUMA TOPE Y ANTERIOR, RETORNAMOS VALOR - COPIA DE PILAMAIN
{
    Pila aux2;
    inicpila(&aux2);
    int suma=0;
    int cont=0;

    while(!pilavacia(&copiaAPilamain) && cont<2)
    {
        suma=suma+tope(&copiaAPilamain);
        apilar(&aux2, desapilar(&copiaAPilamain));
        cont++;
    }

    return suma;
}

float promedioPila(Pila copiaAPilamain) ///PROMEDIA TODOS LOS ELEMENTOS DE UNA PILA - COPIA DE PILAMAIN
{
    Pila aux2;
    inicpila(&aux2);

    int total=0;
    float promedio=0;
    int cont=0;

    while(!pilavacia(&copiaAPilamain))
    {
        total= total+tope(&copiaAPilamain);
        apilar(&aux2, desapilar(&copiaAPilamain));
        cont++;
    }
    promedio= (float) total/cont;
    return promedio;
}

int pilaADecimal(Pila copiaAPilamain) ///FUNCION QUE PASA LOS ELEMENTOS DE UNA PILA AL FORMATO DECIMAL Y LO RETORNA (INT) - COPIA DE PILAMAIN
{
    Pila aux2;
    inicpila(&aux2);

    int multiplicador=1;
    int decimal=0;

    while (!pilavacia(&copiaAPilamain)) ///MIENTRAS LA PILA NO ESTE VACIA
    {
        decimal=decimal+(multiplicador * tope(&copiaAPilamain));
        apilar(&aux2, desapilar(&copiaAPilamain));
        multiplicador=(multiplicador*10);
    }

    return decimal; ///RETORNAMOS LA PILA EN FORMATO DECIMAL
}





