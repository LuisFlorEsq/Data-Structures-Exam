#include "Prueba.h"

// FUNCIONES PARA MANEJAR LA LISTA SIMPLEMENTE ENLAZADA

Lista crearLista(int *e, int id2)
{

    Lista l = (Elemento_Lista *)malloc(sizeof(Lista));
    if (l == NULL)
    {
        *e = -1;
        perror("No hay memoria para la lista");
    }
    else
    {
        l->cabecera = NULL;
        l->id = id2;
        *e = 0;
    }

    return l;
}

void generarEdad(int *edadUsuario)
{

    // La edad se genera de forma aleatoria tomando valores entre 18 y 60 anios

    srand(time(NULL));

    *edadUsuario = rand() % 42 + 18;
}

void agregarIzquierda(Lista *l, int *e, DatoL datousuario)
{
    struct PersonaL *nodousuario = (struct PersonaL *)malloc(sizeof(struct PersonaL));

    if (nodousuario == NULL)
    {

        perror("No se creo el nodo");
        *e = -4;
    }
    if ((*l)->cabecera == NULL)
    {
        nodousuario->dato = datousuario;
        nodousuario->pos = 0;
        (*l)->cabecera = nodousuario;
        (*l)->cabecera->siguiente = NULL;
    }
    else
    {

        struct PersonaL *actual = (struct PersonaL *)malloc(sizeof(struct PersonaL));
        struct PersonaL *nodoAux = (struct PersonaL *)malloc(sizeof(struct PersonaL));

        nodoAux = (*l)->cabecera;
        nodousuario->dato = datousuario;
        nodousuario->pos = 0;

        (*l)->cabecera = nodousuario;
        nodousuario->siguiente = nodoAux;

        actual = (*l)->cabecera->siguiente;

        while (actual != NULL)
        {

            actual->pos++;
            actual = actual->siguiente;
        }
    }

    //printf("\nNodo agregado correctamente\n");
}

void agregarDerecha(Lista *l, int *e, DatoL datousuario)
{

    struct PersonaL *PersonaLusuario = (struct PersonaL *)malloc(sizeof(struct PersonaL));

    if (PersonaLusuario == NULL)
    {
        *e = -4;
        perror("No se creo el PersonaL");
    }

    if ((*l)->cabecera == NULL)
    {
        printf("\nLista vacia, creando la cabecera\n");
        PersonaLusuario->dato = datousuario;
        PersonaLusuario->pos = 0;
        PersonaLusuario->siguiente = NULL;
        (*l)->cabecera = PersonaLusuario;
    }
    else
    {
        printf("\nLa lista tiene almenos un elemento\n");
        struct PersonaL *PersonaLAux = (struct PersonaL *)malloc(sizeof(struct PersonaL));
        PersonaLAux = (*l)->cabecera;

        while (PersonaLAux->siguiente != NULL)
        {

            PersonaLAux = PersonaLAux->siguiente;
        }

        int posAux = PersonaLAux->pos;
        PersonaLusuario->dato = datousuario;
        PersonaLusuario->siguiente = NULL;
        PersonaLusuario->pos = posAux + 1;
        PersonaLAux->siguiente = PersonaLusuario;
    }
    //printf("\nPersonaL agregado correctamente\n");
}

void agregarN(Lista *l, int *e, DatoL datousuario, int N)
{
    int N2 = N - 1;
    struct PersonaL *PersonaLusuario = (struct PersonaL *)malloc(sizeof(struct PersonaL));
    if (PersonaLusuario == NULL)
    {
        *e = -4;
        perror("No se creo el PersonaL");
    }
    if ((*l)->cabecera == NULL)
    {
        PersonaLusuario->pos = 0;
        PersonaLusuario->dato = datousuario;
        PersonaLusuario->siguiente = NULL;
        (*l)->cabecera = PersonaLusuario;
    }
    else
    {
        struct PersonaL *actual = (*l)->cabecera;
        struct PersonaL *anterior = NULL;
        while (actual->pos != N2)
        {
            anterior = actual;
            actual = actual->siguiente;
        }

        PersonaLusuario->dato = datousuario;
        PersonaLusuario->siguiente = actual;
        PersonaLusuario->pos = N2;

        anterior->siguiente = PersonaLusuario;

        while (actual != NULL)
        {

            actual->pos++;
            actual = actual->siguiente;
        }
    }
}

void recorrerL(Lista l, int *e)
{
    struct PersonaL *lista = (l)->cabecera;
    // printf("\nLa cabecera: %d\n", lista->dato.valor);
    if (lista == NULL)
    {
        printf("\nLista vacia\n");
        *e = 1;
    }
    else
    {
        printf("\nLa lista contiene elementos\n");

        while (lista != NULL)
        {
            printf("Nombre: %s \t", lista->dato.nombre);
            printf("Altura: %.2lf \t", lista->dato.altura);
            printf("Edad: %d \t", lista->dato.edad);
            printf("\n\n");
            lista = lista->siguiente;
        }
        *e = 0;
    }
    printf("\n\n");
    printf("-------------------");
}

void borrarL(Lista *l, int *e)
{
    struct PersonaL *eliminarN, *siguienteN;
    eliminarN = (*l)->cabecera;

    while (eliminarN != NULL)
    {
        siguienteN = eliminarN->siguiente;
        eliminarN->siguiente = NULL;
        free(eliminarN);
        eliminarN = siguienteN;
    }

    printf("\nLista borrada con exito\n");
    (*l)->cabecera = NULL;
    *e = 0;
}

void extraerDerecha(Lista *l, int *error, DatoL *dato)
{

    struct PersonaL *PersonaLAux;
    struct PersonaL *PersonaLExtraido;
    struct PersonaL *cursor = (*l)->cabecera;
    if ((*l)->cabecera == NULL)
    {
        perror("Lista vacia");
        *error = -2;
    }
    if (cursor->siguiente != NULL)
    {
        cursor = (*l)->cabecera;
        while (cursor->siguiente->siguiente != NULL)
        {
            cursor = cursor->siguiente;
        }
        PersonaLExtraido = cursor->siguiente;
        // PersonaLExtraido = cursor->siguiente;
        cursor->siguiente = NULL;
        (*dato) = PersonaLExtraido->dato;
        // printf("DatoL extraido=%d\n", PersonaLExtraido->dato);
        free(PersonaLExtraido);
        *error = 0;
    }
    else
    {
        PersonaLExtraido = (*l)->cabecera;
        (*l)->cabecera = NULL;
        // printf("DatoL Extraido=%d\n", PersonaLExtraido->dato);
        (*dato) = PersonaLExtraido->dato;
        free(PersonaLExtraido);
        *error = 0;
    }
}

void extraerIzquierda(Lista *l, int *error, DatoL *dato)
{

    int posFinal = 0;

    if ((*l)->cabecera == NULL)
    {
        printf("\nLa lista esta vacia\n");
    }
    else
    {
        struct PersonaL *cursor = (*l)->cabecera;
        struct PersonaL *actual = NULL;
        (*dato) = cursor->dato;
        (*l)->cabecera = cursor->siguiente;
        cursor->siguiente = NULL;
        free(cursor);
        actual = (*l)->cabecera;
        while (actual != NULL)
        {
            actual->pos--;
            actual = actual->siguiente;
        }
        *error = 0;
    }
}

void extraerN(Lista *l, int *error, DatoL *datoExtraido, int N)
{
    struct PersonaL *PersonaLAux = (*l)->cabecera;
    struct PersonaL *PersonaLEx = (*l)->cabecera;
    struct PersonaL *PersonaLCursor = (*l)->cabecera;
    int posFinal;
    int N2 = N - 1;

    if ((*l)->cabecera == NULL)
    {
        perror("Nada que extraer");
        *error = -1;
    }
    else
    {
        // Checamos la posicion final de la lista
        while (PersonaLCursor->siguiente != NULL)
        {

            PersonaLCursor = PersonaLCursor->siguiente;
            posFinal = PersonaLCursor->pos;
        }
        if (posFinal < N2)
        {
            perror("Aun no existe esa posicion");
            *error = -3;
        }

        else if (N2 != 0)
        {
            // Volvemos a la cabecera y nos movemos hasta la posicion
            PersonaLCursor = (*l)->cabecera;
            while (PersonaLCursor->pos != N2)
            {
                PersonaLCursor = PersonaLCursor->siguiente;
            }

            *datoExtraido = PersonaLCursor->dato;

            // Eliminamos el PersonaL

            PersonaLCursor = (*l)->cabecera;

            while (PersonaLCursor->pos != (N2 - 1))
            {
                PersonaLCursor = PersonaLCursor->siguiente;
            }

            while (PersonaLAux->pos != (N2 + 1))
            {
                PersonaLAux = PersonaLAux->siguiente;
            }

            while (PersonaLEx->pos != N2)
            {
                PersonaLEx = PersonaLEx->siguiente;
            }

            // Eliminamos y conectamos los PersonaLs

            PersonaLCursor->siguiente = PersonaLAux;
            PersonaLEx = NULL;
            free(PersonaLEx);

            // Recorrer las posiciones

            while (PersonaLAux->siguiente != NULL)
            {
                PersonaLAux->pos--;
                PersonaLAux = PersonaLAux->siguiente;
            }
        }
    }
}

// FUNCIONES PARA MANEJAR LA COLA DINAMICA

Cola crearCola(int *e)
{
    Cola cola = (Cola)malloc(sizeof(Elemento_de_Cola));
    if (cola == NULL)
    {
        *e = -4;
        puts("No se logro obtener memoria para una estructura COLA");
    }
    cola->cabecera = NULL;
    cola->final = NULL;
    cola->cursor = 0;
    return cola;
}

// Insertar elemento en la cola por el final
void encolar(Cola *cola, int *e, DatoC datoIngreso)
{
    struct PersonaC *nodoUsuario = (struct PersonaC *)malloc(sizeof(struct PersonaC));
    if (nodoUsuario == NULL)
    {
        *e = -6;
        puts("La estructura del nuevo nodo no se creo correctamente, favor de liberar datos de la cola");
    }
    else if (estaVacia(*cola, e))
    {
        (*nodoUsuario).dato = datoIngreso;
        (*nodoUsuario).siguiente = NULL;
        (*cola)->cabecera = nodoUsuario;
        (*cola)->final = nodoUsuario;
    }
    else
    {
        (*nodoUsuario).dato = datoIngreso;
        (*nodoUsuario).siguiente = NULL;
        (*cola)->final->siguiente = nodoUsuario;
        (*cola)->final = nodoUsuario;
    }
    (*cola)->cursor++;
    *e = 0;
}

// Eliminar dato de la cola por la cabecera
void desencolar(Cola *cola, int *e, DatoC *datoExtraido)
{

    //printf("\nLlegamos a la funcion de desencolar\n");

    if (estaVacia(*cola, e))
    {

        *e = -1;
        puts("La cola esta vacia, no es posible leer un elemento");
    }
    else
    {

        *datoExtraido = (*cola)->cabecera->dato;
        struct PersonaC *aux = (*cola)->cabecera;

        if ((*cola)->cabecera == (*cola)->final)
        {

            (*cola)->cabecera = NULL;
            (*cola)->final = NULL;
        }
        else
        {

            (*cola)->cabecera = (*cola)->cabecera->siguiente;
        }
        free(aux);
        (*cola)->cursor--;
    }
    *e = 0;
}

// Devuelve un true o un false si la cola contiene o no Nodos:

bool estaVacia(Cola cola, int *e)
{

    if (cola->cabecera == NULL && cola->final == NULL && cola->cursor == 0)
    {

        *e = -1;
        return true;
    }
    else
    {
        *e = 0;
        return false;
    }
}

// Libera la memoria RAM usada por la cola:
void borraCola(Cola *cola, int *e)
{
    if (!estaVacia(*cola, e))
    {

        struct PersonaC *nodoAuxiliar, *nodoAuxiliarRespaldo;
        nodoAuxiliar = (*cola)->cabecera;

        while (nodoAuxiliar != NULL)
        {

            nodoAuxiliarRespaldo = nodoAuxiliar->siguiente;
            free(nodoAuxiliar);
            nodoAuxiliar = nodoAuxiliarRespaldo;
        }

        (*cola)->cabecera = NULL;
        (*cola)->final = NULL;
        (*cola)->cursor = 0;
        *e = 0;
        free(*cola);
    }
}

void imprimeCola(Cola cola, int *e)
{

    struct PersonaC *aux = cola->cabecera;
    int contador = 0;
    // printf("\nLa cabecera: %d\n", lista->dato.valor);
    if (aux == NULL)
    {
        printf("\nCola vacia\n");
        *e = 1;
    }
    else
    {
        printf("---------------------------\n");
        printf("\nLa cola contiene elementos\n\n");

        while (aux != NULL)
        {
            printf("Nombre: %s \t", aux->dato.nombre);
            printf("Altura: %.2lf \t", aux->dato.altura);
            printf("Edad: %d \t", aux->dato.edad);
            printf("\n\n");

            aux = aux->siguiente;
        }
        printf("---------------------------\n");
        *e = 0;
    }
    printf("\n\n");
}

void atencionClientes(Lista *lista, DatoL *dato1, DatoL *dato2, int *error)
{
    int turno = 1;
    while ((*lista)->cabecera != NULL)
    {
        printf("\n-------------------\n");
        printf("\nNumero de turno: %d\n", turno);
        printf("\nNumero de robot: %d\n", (*lista)->id);
        printf("\n-------------------\n");
        printf("\nPersonas en ventanilla en este turno\n");
        extraerIzquierda(lista, error, dato1);

        if ((*lista)->cabecera != NULL)
        {

            extraerIzquierda(lista, error, dato2);
            printf("\nPersona 1: %s\t%d\t%.2lf\n", (*dato1).nombre, (*dato1).edad, (*dato1).altura);
            printf("\nPersona 2: %s\t%d\t%.2lf\n", (*dato2).nombre, (*dato2).edad, (*dato2).altura);
            printf("\n-------------------\n");
        }
        else
        {
            printf("\nPersona 1: %s\t%d\t%.2lf\n", (*dato1).nombre, (*dato1).edad, (*dato1).altura);
        }

        printf("\nPersonas esperando por la atencion\n");
        recorrerL((*lista), error);
        turno++;
    }
}

void printMenu()
{
    printf("\n----------\n");
    printf("1.- Agregar PersonaL por la izquierda\n");
    printf("2.- Agregar PersonaL por la derecha\n");
    printf("3.- Agregar PersonaL por posicion N\n");
    printf("4.- Extraer PersonaL por la izquierda\n");
    printf("5.- Extraer PersonaL por la derecha\n");
    printf("6.- Extraer PersonaL por posicion N\n");
    printf("7.- Recorrer lista\n");
    printf("8.- Borrar lista\n");
    printf("9.- Salir del sistema\n");
    printf("\n");
}