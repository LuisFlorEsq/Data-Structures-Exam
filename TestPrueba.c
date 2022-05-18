/*
 *Nombre: Flores Esquivel Luis Antonio
 *Grupo: 2BM1
 *Carrera: IIA
 *Ultima modificacion: 14/05/22
 */

#include "Prueba.h"

int main(int argc, char **argv)
{

    system("cls");

    int n = 0;
    int opc = 0;
    int error = 0;
    DatoC datocola;
    DatoC datoExt;
    DatoL datoIns;

    DatoL dato1, dato2;

    int clientesN = 0;

    // Variables de control

    int i, j, k;

    // Los datos de la persona a encolar

    int edadM;
    double alturaM;
    char nombreM[20];

    int edadE;
    double alturaE;
    char *nombreE;

    // Creamos una unica cola en la que se almacenaran todos los clientes

    Cola colaClientes = crearCola(&error);

    // Cada robot tiene asociado una lista simple, por lo que se crean las cinco listas

    Lista lista1 = crearLista(&error, 1);
    Lista lista2 = crearLista(&error, 2);
    Lista lista3 = crearLista(&error, 3);
    Lista lista4 = crearLista(&error, 4);
    Lista lista5 = crearLista(&error, 5);

    system("cls");
    printf("---------------\n");
    printf("Examen de prueba, segundo departamental \n");

    // Damos la bienvenida al usuario y le pedimos que seleccione alguna de las opciones del sistema

    printf("----------------------------------------");
    printf("\nBienvenido al sistema de cajero, por favor sigue las instrucciones que se te indiquen:\n");

    printf("\nIngrese el numero de clientes que seran atendidos\n");
    scanf("%d", &clientesN);

    // Pedimos al usuario que ingrese los datos del cliente N, hasta que se hayan ingresado todos los clientes

    printf("\nIngresando informacion de los usuarios...\n");

    for (i = 0; i < clientesN; i++)
    {
        printf("------------------------------");
        printf("\nIngrese los datos del cliente (%d)\n", i + 1);

        // Pedimos nombre y altura
        printf("Nombre:\n\t");
        fflush(stdin);
        scanf("%s", &datocola.nombre);

        printf("Altura\n\t");
        fflush(stdin);
        scanf("%lf", &datocola.altura);

        generarEdad(&edadM);

        printf("Edad generada de forma aleatoria para el usuario:\n\t");
        printf("%d", edadM);

        datocola.edad = edadM;

        encolar(&colaClientes, &error, datocola);

        printf("\n");
    }

    // Verificamos que la cola se haya llenado

    // imprimeCola(colaClientes, &error);

    // Llenamos las listas de los robots

    for (i = 0; i < clientesN; i++)
    {
        desencolar(&colaClientes, &error, &datoExt);

        // Evaluamos el dato que se ha extraido

        edadE = datoExt.edad;
        alturaE = datoExt.altura;
        nombreE = datoExt.nombre;

        datoIns.altura = alturaE;
        datoIns.edad = edadE;
        strcpy(datoIns.nombre, nombreE);

        // printf("\nDatos guardados correctamente\n");

        if (edadE > 18 && edadE < 22)
        {
            // printf("\nPersona agregada a la lista 1\n");
            agregarIzquierda(&lista1, &error, datoIns);
        }
        else if (edadE == 18)
        {
            // printf("\nPersona agregada a la lista 2\n");
            agregarIzquierda(&lista2, &error, datoIns);
        }
        else if (edadE > 22 && edadE < 44)
        {
            // printf("\nPersona agregada a la lista 3\n");
            agregarIzquierda(&lista3, &error, datoIns);
        }
        else if (edadE == 22 || edadE == 44)
        {
            // printf("\nPersona agregada a la lista 4\n");
            agregarIzquierda(&lista4, &error, datoIns);
        }
        else if (edadE > 44 && edadE <= 60)
        {
            // printf("\nPersona agregada a la lista 5\n");
            agregarIzquierda(&lista5, &error, datoIns);
        }
    }

    // Imprimimos las listas para ver si las personas se han agregado correctamente

    /*
    printf("\nLista 1:\n");
    recorrerL(lista1, &error);

    printf("\nLista 2:\n");
    recorrerL(lista2, &error);

    printf("\nLista 3:\n");
    recorrerL(lista3, &error);

    printf("\nLista 4:\n");
    recorrerL(lista4, &error);

    printf("\nLista 5:\n");
    recorrerL(lista5, &error);
    */

    // Evaluamos que la cola este vacia
    if (estaVacia(colaClientes, &error))
    {

        // Proceso para el robot 1

        atencionClientes(&lista1, &dato1, &dato2, &error);

        atencionClientes(&lista2, &dato1, &dato2, &error);

        atencionClientes(&lista3, &dato1, &dato2, &error);

        atencionClientes(&lista4, &dato1, &dato2, &error);

        atencionClientes(&lista5, &dato1, &dato2, &error);

        // Proceso para el robot 2

        /*
        while (lista2->cabecera != NULL)
        {
            extraerIzquierda(&lista2, &error, &dato1);

            if (lista2->cabecera != NULL)
            {

                extraerIzquierda(&lista2, &error, &dato2);
            }

            printf("\n-------------------\n");
            printf("\nNumero de turno: %d\n", turno);
            printf("\nNumero de robot: %d\n", lista2->id);
            printf("\n-------------------\n");
            printf("\nPersonas en ventanilla en este turno\n");
            printf("\nPersona 1: %s\t%d\t%.2lf\n", dato1.nombre, dato1.edad, dato1.altura);
            printf("\nPersona 2: %s\t%d\t%.2lf\n", dato2.nombre, dato2.edad, dato2.altura);
            printf("\n-------------------\n");

            printf("\nPersonas esperando por la atencion\n");
            recorrerL(lista2, &error);
            turno++;
        }

        turno = 1;
        // Proceso para el robot 3

        while (lista3->cabecera != NULL)
        {
            extraerIzquierda(&lista3, &error, &dato1);

            if (lista3->cabecera != NULL)
            {

                extraerIzquierda(&lista3, &error, &dato2);
            }

            printf("\n-------------------\n");
            printf("\nNumero de turno: %d\n", turno);
            printf("\nNumero de robot: %d\n", lista3->id);
            printf("\n-------------------\n");
            printf("\nPersonas en ventanilla en este turno\n");
            printf("\nPersona 1: %s\t%d\t%.2lf\n", dato1.nombre, dato1.edad, dato1.altura);
            printf("\nPersona 2: %s\t%d\t%.2lf\n", dato2.nombre, dato2.edad, dato2.altura);
            printf("\n-------------------\n");

            printf("\nPersonas esperando por la atencion\n");
            recorrerL(lista3, &error);
            turno++;
        }

        turno = 1;
        // Proceso para el robot 4

        while (lista4->cabecera != NULL)
        {
            extraerIzquierda(&lista4, &error, &dato1);

            if (lista4->cabecera != NULL)
            {

                extraerIzquierda(&lista4, &error, &dato2);
            }

            printf("\n-------------------\n");
            printf("\nNumero de turno: %d\n", turno);
            printf("\nNumero de robot: %d\n", lista4->id);
            printf("\n-------------------\n");
            printf("\nPersonas en ventanilla en este turno\n");
            printf("\nPersona 1: %s\t%d\t%.2lf\n", dato1.nombre, dato1.edad, dato1.altura);
            printf("\nPersona 2: %s\t%d\t%.2lf\n", dato2.nombre, dato2.edad, dato2.altura);
            printf("\n-------------------\n");

            printf("\nPersonas esperando por la atencion\n");
            recorrerL(lista4, &error);
            turno++;
        }

        turno = 1;
        // Proceso para el robot 5

        while (lista5->cabecera != NULL)
        {

            extraerIzquierda(&lista5, &error, &dato1);

            if (lista5->cabecera != NULL)
            {

                extraerIzquierda(&lista5, &error, &dato2);
            }

            printf("\n-------------------\n");
            printf("\nNumero de turno: %d\n", turno);
            printf("\nNumero de robot: %d\n", lista5->id);
            printf("\n-------------------\n");
            printf("\nPersonas en ventanilla en este turno\n");
            printf("\nPersona 1: %s\t%d\t%.2lf\n", dato1.nombre, dato1.edad, dato1.altura);
            printf("\nPersona 2: %s\t%d\t%.2lf\n", dato2.nombre, dato2.edad, dato2.altura);
            printf("\n-------------------\n");

            printf("\nPersonas esperando por la atencion\n");
            recorrerL(lista5, &error);
            turno++;
        }
    }
*/
        return 0;
    }
}