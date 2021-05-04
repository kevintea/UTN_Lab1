#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int valorRandom ();
void mayorYmenor ();
int sumaMenores(int numBase);
void valorTabla(int* valorT);
void calcu();
int valorAnegativo(int* valorN);
void cargaPunteros(int* valor1, int* valor2);

int main()
{
    srand(time(NULL));
    int inciso=0;
    int opcion;
    int valorR=0;
    int numBase=0;
    int suma=0;
    int valorT=0;
    int valorN=0, valorNeg=0;
    int valor1, valor2;



    do
    {
        printf("\n\t\t\t Bienvenidos al MENU PRINCIPAL del Trabajo Practico 3-BIS: Funciones \n\n\n");
        printf(" 1-  Entrega de valor RANDOM de 0-100\n");
        printf(" 2-  Busca el mayor y el menor de los elementos ingresados \n");
        printf(" 3-  Ingreso un valor tope y sumo todos sus menores y retornamos el total \n");
        printf(" 4-  Ingreso un valor y muestro su tabla multiplicadora \n");
        printf(" 5-  Calculadora \n");
        printf(" 6-  Recibo un valor y lo paso a negativo \n");
        printf(" 7-  Recibo dos valores y los cargo \n");


        printf("\n\n Seleccione uno de los incisos: ");
        scanf("%d", &inciso);

        switch(inciso)
        {
        case 1:
            valorR=valorRandom(valorR);
            printf("\n El valor devuelto es %d \n\n", valorR);
            break;

        case 2:
            mayorYmenor();
            break;

        case 3:
            printf("\n Ingrese un valor: ");
            scanf("%d", &numBase);
            suma=sumaMenores(numBase);
            printf("\n La suma de valores menores al ingresado es: %d \n\n", suma);
            break;

        case 4:
            printf("\n Ingrese un valor: ");
            scanf("%d", &valorT);
            valorTabla(valorT);
            break;

        case 5:
            calcu();
            break;

        case 6:
            printf("\n Ingrese un valor: ");
            scanf("%d", &valorN);
            valorNeg=valorAnegativo(valorN);
            if(valorNeg!=0)
            {
                printf("\n Nuevo valor: %d\n", valorNeg);
            }
            else
            {
                printf("\n El valor ingresado fue 0!\n");
            }
            break;

        case 7:
            cargaPunteros(valor1, valor2);
            printf("\n Los nuevos valores son: %d y %d\n", valor1, valor2);
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

int valorRandom () ///DEVUELVO UN VALOR RANDOM DENTRO DE LOS LIMITES IMPUESTOS
{
    int valorR;
    valorR= rand()%100;

    return valorR;
}

void mayorYmenor () ///UTILIZO 3 VALORES PARA CONSEGUIR EL MAYOR Y EL MENOR
{
    int num1, num2, num3;
    int mayor=0, menor=0;

    printf("\n Ingrese primer valor a calcular: ");
    scanf("%d", &num1);
    printf("\n Ingrese segundo valor a calcular: ");
    scanf("%d", &num2);
    printf("\n Ingrese tercer valor a calcular: ");
    scanf("%d", &num3);

    if(num1>num2 && num1>num3) ///BUSCANDO EL MAYOR DE LOS ELEMENTOS
    {
        mayor=num1;
    }
    else if(num2>num1 && num2>num3)
    {
        mayor=num2;
    }
    else
    {
        mayor=num3;
    }

    if(num1<num2 && num1<num3) ///BUSCANDO EL MENOR DE LOS ELEMENTOS
    {
        menor=num1;
    }
    else if(num2<num1 && num2<num3)
    {
        menor=num2;
    }
    else
    {
        menor=num3;
    }

    printf("\n\t El mayor elemento es %d y el menor %d\n\n", mayor, menor);
}

int sumaMenores(int numBase) ///RECIBO UN VALOR Y CALCULO TODOS SUS MENORES Y RETORNO
{
    int i=0,sumaTotal=0,valorMenor=0;
    valorMenor=numBase;

    for(i=0; i<numBase; i++)
    {
        valorMenor=valorMenor-1;
        sumaTotal=sumaTotal+valorMenor;
    }
    return sumaTotal;
}

void valorTabla(int* valorT) ///RECIBO UN VALOR Y MUESTRO SU TABLA MULTIPLICADORA
{
    int i=0,rta=0,numT=0;
    numT=valorT;

    for(i=0; i<=10; i++)
    {
        rta=(numT*i);
        printf("\n %d x %d = %d", numT, i, rta);
    }
}

void calcu() ///DEMO DE FUNCIONES BASICAS DE CALCULADORA
{
    int numA=0, numB=0, caso=0, opcion=0;
    do
    {
        printf("\n\n 1- Suma............: \n\n");
        printf(" 2- Resta...........: \n\n");
        printf(" 3- Multiplicacion..: \n\n");
        printf(" 4- Division........: \n\n");

        printf("\n  Seleccione funcion a realizar: ");
        scanf("%d", &caso);
        switch(caso)
        {
        case 1:
            suma();
            break;

        case 2:
            resta();
            break;

        case 3:
            multiplicacion();
            break;

        case 4:
            division();
            break;
        }
        printf("\n\n\t ESC para Menu Principal - Presione cualquier tecla para Calculadora.\n\n");
        fflush(stdin);
        opcion=getch();
    }
    while(opcion!=ESC);
}

void suma() ///FUNCION DE SUMA CON CICLO
{
    int a=0, n=0, total=0, opcion=0;
    printf("\n Ingrese valor: ");
    scanf("%d", &a);
    total=a;

    do
    {
        printf("\n Ingrese valor: ");
        scanf("%d", &n);
        printf("\n %d + %d = ", total, n);
        total= total+n;
        printf("%d \n", total);

        printf("\n\n\t ESC para Calculadora - Presione cualquier tecla para seguir sumando \n\n");
        fflush(stdin);
        opcion=getch();

    }
    while(opcion!=ESC);
    system("cls");
}

void resta() ///FUNCION DE RESTA CON CICLO
{
    int a=0, n=0, total=0, opcion=0;
    printf("\n Ingrese valor: ");
    scanf("%d", &a);
    total=a;

    do
    {
        printf("\n Ingrese valor: ");
        scanf("%d", &n);
        printf("\n %d - %d = ", total, n);
        total= total-n;
        printf("%d \n", total);

        printf("\n\n\t ESC para Calculadora - Presione cualquier tecla para seguir restando \n\n");
        fflush(stdin);
        opcion=getch();

    }
    while(opcion!=ESC);
    system("cls");
}

void multiplicacion() ///FUNCION DE MULTIPLICACION CON CICLO
{
    int a=0, n=0, total=0, opcion=0;
    printf("\n Ingrese valor: ");
    scanf("%d", &a);
    total=a;

    do
    {
        printf("\n Ingrese valor: ");
        scanf("%d", &n);
        printf("\n %d * %d = ", total, n);
        total= total*n;
        printf("%d \n", total);

        printf("\n\n\t ESC para Calculadora - Presione cualquier tecla para seguir multiplicando \n\n");
        fflush(stdin);
        opcion=getch();

    }
    while(opcion!=ESC);
    system("cls");
}

void division() ///FUNCION DE DIVISION CON CICLO
{
    float a=0, n=0, total=0, opcion=0;
    printf("\n Ingrese valor: ");
    scanf("%f", &a);
    total=a;

    do
    {
        printf("\n Ingrese valor: ");
        scanf("%f", &n);
        printf("\n %.3f / %.3f = ", total, n);
        total=  total/n;
        printf("%.3f \n", total);

        printf("\n\n\t ESC para Calculadora - Presione cualquier tecla para seguir dividiendo \n\n");
        fflush(stdin);
        opcion=getch();

    }
    while(opcion!=ESC);
    system("cls");
}

int valorAnegativo(int* valorN) ///FUNCION PASAJE DE SIGNO
{
    int negativo=0;

    negativo=valorN;
    negativo=(negativo*-1);

    return negativo;
}

void cargaPunteros(int* valor1, int* valor2)
{
    printf("\n Ingrese nuevo valor para el primer numero: ");
    scanf("%d", &valor1);
    printf("\n Ingrese nuevo valor para el segundo numero: ");
    scanf("%d", &valor2);
}






