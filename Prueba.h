#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

/*
    |Variable   | Estado    | Significado
        error       0           Sin errores (todo resultado es exitoso)
        error      -1           Error, Lista vacía
        error      -2           Inexistencia de la Lista, esta apunta a NULL
        error      -3           Inexistencia de dato en la estructura
        error      -4           No se creo el nodo, no hay suficiente memoria
*/

// OPERACIONES DE LA LISTA SIMPLEMENTE ENLAZADA

typedef struct
{
    double altura;
    int edad;
    char nombre[20];
}DatoL;

struct PersonaL
{
    int pos;
    DatoL dato;
    struct PersonaL *siguiente;
};

// TDA Lista simple
typedef struct
{
    struct PersonaL *cabecera;
    int id;
} Elemento_Lista;

typedef Elemento_Lista *Lista;

// Crear Lista
Lista crearLista(int *e, int id);

// Agregar por la izquierda
void agregarIzquierda(Lista *l, int *e, DatoL datousuario);

// Agregar por la derecha
void agregarDerecha(Lista *l, int *e, DatoL datousuario);

// Agregar en la posicion N
void agregarN(Lista *l, int *e, DatoL datousuario, int N);

// Extraer por la izquierda
void extraerIzquierda(Lista *l, int *error, DatoL *dato);

// Extraer por la derecha
void extraerDerecha(Lista *l, int *error, DatoL *dato);

// Extraer por la posicion N

void extraerN(Lista *l, int *error, DatoL *datoExtraido, int N);

// Recorrer lista
void recorrerL(Lista l, int *e);

// Borrar lista
void borrarL(Lista *l, int *e);

// Menu de opciones
void printMenu();

// Creamos una persona, que almacenara los datos ingresados por el usuario y posteriormente generara la edad de forma aleatoria

void generarEdad(int *edadUsuario);


// OPERACIONES DE LA COLA DINAMICA

typedef struct
{
    double altura;
    int edad;
    char nombre[20];
}DatoC;

struct PersonaC
{
    DatoC dato;
    struct PersonaC *siguiente;
};

// TDA Cola dinámica
typedef struct
{
    int cursor; // iterador  -> cantidad de nodos existentes
    struct PersonaC *cabecera;
    struct PersonaC *final;
} Elemento_de_Cola;

typedef Elemento_de_Cola *Cola;

Cola crearCola(int *);

// Inserta cola por el final
void encolar(Cola *cola, int *, DatoC datoc);

// Eliminar dato por la cabecera
void desencolar(Cola *cola, int *, DatoC *datoc);

// Devuelve un true o un false si la cola contiene o no Nodos:
bool estaVacia(Cola, int *);

// Libera la memoria RAM usada por la cola:
void borraCola(Cola *, int *);


// Funciones extras

void imprimeCola(Cola, int *);

void atencionClientes(Lista *lista, DatoL *dato1, DatoL *dato2, int *error);
