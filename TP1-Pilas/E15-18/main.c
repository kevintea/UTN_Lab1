/***15. Cual es la condición del siguiente ciclo? .Cuando finaliza el ciclo?
(Pila1, Pila2, y Descarte son pilas)
*/

while (!pilavacia(&Pila1))
{
    apilar (&Pila2, desapilar(&Descarte))
}


///LA CONDICION ES QUE MIENTRAS LA PILA1 NO ESTE VACIA SE APILARA EN PILA2
///LOS ELEMENTOS DE DESCARTE, ESTE FINALIZARA DE DONDE MANERAS.. CUANDO PILA1 SE QUEDE
/// SIN ELEMENTOS (NO EXPRESADOS EN LA CONDICION) O QUE SE CRASHEE AL QUEDARSE
/// SIN ELEMENTOS LA PILA DESCARTE.


/***16. Qué realiza el siguiente código escrito en lenguaje C
(Pila1, Aux y Result son pilas):
*/

while (!pilavacia(&Pila1))
{
    if (tope(&Pila1) == 5)
    {
        apilar (&Aux, desapilar(&Pila1));
        apilar (&Result, desapilar(&Aux));
    }
}

///MIENTRAS LA PILA1 NO ESTE VACIA, SI EL TOPE DE PILA1 ES 5
///SE APILARA EN AUX EL TOPE DE PILA1 Y TAMBIEN ESTE NUEVO TOPE DE AUX
///SE APILARA EN LA PILA RESULT



/***17. Para el ejercicio “Cargar por teclado una pila ORIGEN y pasar
 a la pila DISTINTO todos aquellos elementos que preceden al valor 5 }
 (elementos entre el tope y el valor 5).
  No se asegura que exista algún valor 5”, se realizo el siguiente programa:
*/


// este programa carga por teclado una pila Origen y pasa a
//la pila Destino todos aquellos elementos que preceden el valor 5

int main()
{
    Pila Origen, Distinto;
    inicpila(&Origen);
    inicpila(&Distinto);
    leer(&Origen); // CICLO DE CARGA INCOMPLETO
    if (!pilaVacia(&Origen))  //PILAVACIA MAL ESCRITO
    {
        while (tope(&Origen) != 5)
        {
            apilar (&Distinto, desapilar(&Origen));
        }
    }
}
/***a. .Resuelve el problema planteado?
b. .Cuales son los errores que encuentra?
c. Reescribir el código para que resuelva adecuadamente el problema planteado.
d. Indicar las componentes del programa

A.PODRIA RESOLVER EL PLANTEO SIEMPRE Y CUANDO SE HAGAN LAS SIGUIENTES MODIFICACIONES
B.CARECE DE CICLO DE CARGA, SOLAMENTE SE INGRESARIA UN ELEMENTO EN LA PILA ORIGEN
EN LA CONDICION DEL IF LA FUNCION PILAVACIA ESTA MAL ESCRITA, LO QUE GENERARIA UN ERROR
DE SINTAXIS
C.

*/

int main()
{
    Pila Origen, Distinto;
    inicpila(&Origen);
    inicpila(&Distinto);
    char opcion;

    ///INICIO DE CICLO DE CARGA
    do
    {
        printf(" Carga de Pila Origen:");
        leer(&Origen);
        printf(" ESC para Salir - Presione cualquier tecla para continuar. ");
        opcion=getch();
        system("cls");
    }
    while(opcion!=27);
    ///FIN CICLO DE CARGA

    /// INICIO RAZONAMIENTO
    if (!pilavacia(&Origen))
    {
        while (tope(&Origen) != 5)
        {
            apilar (&Distinto, desapilar(&Origen));
        }
    }
    ///FIN RAZONMIENTO

    ///INICIO MUESTRA DE DATOS
    printf(" Pila Origen: ");
    mostrar(&Origen);
    printf(" Pila Distinto: ");
    mostrar(&Distintos);
    ///FIN MUESTRA DE DATOS

    return 0;
}

/***18. Dado el siguiente ciclo (Pila1, Pila2 y Descarte son pilas):

while ( (!pilaVacia(&Pila1)) && (!pilaVacia(&Pila2)) ) {
      apilar (&Descarte, desapilar(&Pila1));
      apilar (&Descarte, desapilar(&Pila2))
}
a. .Cual es la condición del ciclo? Explique con sus palabras
b. .Cuales son los posibles estados de ambas pilas al finalizar el ciclo?

A. LA CONDICION DEL CICLO CITA QUE MIENTRAS NINGUNA DE AMBAS PILAS ESTE VACIA
B. PUEDE QUE UNA DE LAS PILAS QUEDE VACIA O QUE AMBAS PILAS LO ESTEN.






